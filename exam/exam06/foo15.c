#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const int BUF_SIZE = 42 * 4096;
const char* FATAL_ERROR = "Fatal error\n";
unsigned int IP_ADDR;
int max = 0, next_id = 0;
char w_buf[BUF_SIZE], r_buf[BUF_SIZE];
fd_set current_fds, w_fds, r_fds;

typedef struct s_client {
	int id;
	char msg[110000];
} t_client;

t_client clients[1024];

void printerror(const char* str) {
	write(2, str, strlen(str));
	exit(1);
}

void set_ip(unsigned int* ip) {
	char a = 127, b = 0, c = 1;
	*ip = (a << 24) | (b << 16) | (b << 8) | c;
}

void send_all(int socket) {
	for (int i = 0; i <= max; i++) {
		if (FD_ISSET(i, &w_fds) && i != socket)
			send(i, w_buf, strlen(w_buf), 0);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) printerror("Wrong number of input\n");

	int master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (master_socket < 0) printerror(FATAL_ERROR);
	max = master_socket;

	FD_ZERO(&current_fds);
	bzero(&clients, sizeof(clients));
	FD_SET(master_socket, &current_fds);
	set_ip(&IP_ADDR);

	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(IP_ADDR);

	if (bind(master_socket, (const struct sockaddr*)&addr, addr_len) < 0) printerror(FATAL_ERROR);
	if (listen(master_socket, 42) < 0) printerror(FATAL_ERROR);

	while (1) {
		r_fds = w_fds = current_fds;
		if (select(max + 1, &r_fds, &w_fds, NULL, NULL) < 0) continue ;
		for (int socket = 0; socket <= max; socket++) {
			if (FD_ISSET(socket, &r_fds) && socket == master_socket) {
				int new_fd = accept(socket, (struct sockaddr*)&addr, &addr_len);
				if (new_fd < 0) continue ;
				FD_SET(new_fd, &current_fds);
				clients[new_fd].id = next_id++;
				max = new_fd < max ? max : new_fd;
				sprintf(w_buf, "server: client %d just arrived\n", clients[new_fd].id);
				send_all(new_fd);
				break ;
			} else if (FD_ISSET(socket, &r_fds)) {
				int res = recv(socket, r_buf, BUF_SIZE, 0);
				if (res <= 0) {
					sprintf(w_buf, "server: client %d just left\n", clients[socket].id);
					send_all(socket);
					FD_CLR(socket, &current_fds);
					close(socket);
					break ;
				} else {
					for (int i = 0, j = strlen(clients[socket].msg); i < res; i++, j++) {
						clients[socket].msg[j] = r_buf[i];
						if (clients[socket].msg[j] == '\n') {
							clients[socket].msg[j] = '\0';
							sprintf(w_buf, "client %d: %s\n", clients[socket].id, clients[socket].msg);
							send_all(socket);
							bzero(&clients[socket].msg, strlen(clients[socket].msg));
							j = -1;
						}
					}
					break ;
				}
			}
		}
	}
}
