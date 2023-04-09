#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	char buf[10];
	int n;

	n = read(STDIN_FILENO, buf, 10);
	if (n < 0)
	{
		perror("read STDIN_FILENO");
		// printf("%d\n", errno);
		exit(1);
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}