#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd, n;
	char msg[] = "It's a test for lseek\n";
	char ch;

	fd = open("lseek.txt", O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open lseek.txt error");
		exit(1);
	}

	write(fd, msg, strlen(msg));

	lseek(fd, 0, SEEK_SET);

	while ( (n = read(fd, &ch, 1)))
	{
		if (n < 0)
		{
			perror("read error");
			exit(1);
		}
		printf("%c", ch);
	}
	return 0;
}
