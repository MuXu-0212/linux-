#include "head.h"

// #define path_doc ""

int main(int argc, char const *argv[])
{
	char read_data[1024];

	int n = 0;

	int fd_read = open(argv[1], O_RDONLY);
	if (fd_read == -1)
	{
		perror("fd_read error");
		exit(1);
	}

	int fd_write = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_write == -1)
	{
		perror("fd_write error");
		exit(1);
	}

	while( (n = read(fd_read, read_data, 1024)) != 0)
	{
		if (n < 0)
		{
			perror("error");
			exit(1);
		}
		write(fd_write, read_data, n);
		memset(read_data, 0,sizeof(read_data));

	}

	close(fd_read);
	close(fd_write);
	printf("拷贝成功\n");
	return 0;
}