

#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
//   int fd;

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
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
//   return (0);
// }
