#include <stdio.h> // sprintf,
#include <string.h> // strstr, strlen, strcpy, strcat, memset
#include <strings.h> // bzero
#include <unistd.h> // write, close
#include <stdlib.h> // malloc, realloc, free, calloc, atoi, exit
#include <arpa/inet.h> // htons
#include <sys/socket.h> // socket, accept, listen, send, recv, bind
#include <sys/select.h> // select

const int BUF_SIZE = 42 * 4096;
const char* FATAL_ERROR = "Fatal error\n";
unsigned int IP_ADDR;
int next_id = 0, max = 0;

void set_ip(unsigned int* ip) {
	unsigned char a = 127, b = 0, c = 0, d = 1;
	ip = (a << 24) | (b << 16) | (c << 8) | d;
}

typedef struct s_client {
	int id;
	char msg[110000];
} t_client;

t_client clients[1024];
fd_set current_fds, w_fds, r_fds;
char r_buf[BUF_SIZE], w_buf[BUF_SIZE];

void printerror(char* str) {
	int len = strlen(str);
	write(2, str, len);
	exit(1);
}

void send_all(int socket) {
	for (int i = 0; i <= max; i++) {
		if (FD_ISSET(i, &w_fds) && i != socket) {
			send(i, w_buf, strlen(w_buf), 0);
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printerror("Wrong number of arguments\n");
	}
	bzero(&clients, sizeof(clients));
	FD_ZERO(&current_fds);
	set_ip(&IP_ADDR);

	int master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (master_socket < 0) printerror(FATAL_ERROR);

	max = master_socket;
	FD_SET(master_socket, &current_fds);

	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(argv[1]);
	addr.sin_addr.s_addr = htonl(IP_ADDR);

	if (bind(master_socket, (const struct sockaddr *)&addr, sizeof(addr)) < 0)
		printerror(FATAL_ERROR);
	if (listen(master_socket, 42) < 0) // maximum length for the queue of pending connections: 맘대로~
		printerror(FATAL_ERROR);

	while (1) {
		current_fds = w_fds = r_fds; // 클라이언트의 존재유무는 r_fds에 남아있으므로, r_fds 기준으로 복사
		if (select(max + 1, &r_fds, &w_fds, NULL, NULL) < 0)
			continue; // 오류가 있으면 넘어가서 다시 FD세트를 정리.
		for (int socket = 0; socket <= max; socket++) { // 오류가 없으면 이벤트가 있는 소켓을 찾아본다.
			if (FD_ISSET(socket, &r_fds) && socket == master_socket) { // 소켓이 읽기 가능하고, 서버 소켓일 때: 서버소켓이 읽을 준비.
				int new_fd = accept(socket, (struct sockaddr*)&addr, &addr_len); // 클라이언트를 받아들이고, 새로운 소켓 할당
				if (new_fd < 0) continue; // 실패시 넘어감
				FD_SET(new_fd, &current_fds); // 새로운 클라이언트의 소켓을 FD세트에 추가
				clients[new_fd].id = next_id++; // 이 클라이언트의 아이디(번호)를 붙여줌
				max = max > new_fd ? max : new_fd; // max를 더 큰값으로 설정: 클라이언트 인원수 재조정
				sprintf(w_buf, "server: client %d just arrived\n", clients[new_fd].id); // 쓰기 버퍼에 "클라이언트 도착" 메모
				send_all(new_fd); // 메모를 전체 클라이언트에게 전송(보낸이 제외)
				break ;
			} else if (FD_ISSET(socket, &r_fds)) { // socket == master_socket이 아닐 때, 즉, 클라이언트 소켓일 때: 클라이언트가 읽을 준비.
				int res = recv(socket, r_buf, BUF_SIZE, 0); // 클라이언트의 신호를 읽기 버퍼에 메모
				if (res <= 0) {  // 연결종료 혹은 오류
					sprintf(w_buf, "server: client %d just left\n", clients[socket].id); // 쓰기 버퍼에 "클라이언트 떠남" 메모
					send_all(socket); // 메모를 전체 클라이언트에게 전송(떠난이 제외)
					FD_CLR(socket, &current_fds); // FD세트에서 현재 소켓 제거
					close(socket); // 소켓 종료
					break ;
				} else { // 메세지를 받음(쓰기 상태)
					for (int i = 0, j = strlen(clients[socket].msg); i < res; i++, j++) {
						clients[socket].msg[j] = r_buf[i]; // 읽기 버퍼에 메모해둔 클라이언트 신호(메세지)를 해당 클라이언트 구조체에 저장
						if (clients[socket].msg[j] == '\n') { // 개행일 때
							clients[socket].msg[j] = '\0'; // 문장 종료로 바꿈
							sprintf(w_buf, "client %d: %s\n", clients[socket].id, clients[socket].msg); // 쓰기 버퍼에 메세지 메모
							send_all(socket); // 메모를 전체 클라이언트에게 전송(보낸이 제외)
							bzero(&clients[socket].msg, strlen(clients[socket].msg)); // 클라이언트 메세지 삭제
							j = -1; // 빈 클라이언트 메세지란에 개행이후부터 쓰기 시작, 읽기 버퍼에 메모해둔 걸 다 출력할 때까지.
						}
					}
					break ;
				}
			}

		}
	}
}

