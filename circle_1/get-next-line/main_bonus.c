

#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
//   int fd;
//   int fd2;

//   fd = 0;
//   fd = open("test.txt", O_RDONLY);
//   printf("%d\n", fd);
//   char *line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   fd2 = open("test2.txt", O_RDONLY);
//   printf("%d\n", fd2);
//   char *line2 = get_next_line(fd2);
//   printf("%p\n", line2);
//   printf("%s", line2);

//   printf("\n---------------------------------------\n");
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
//   return (0);
// }
