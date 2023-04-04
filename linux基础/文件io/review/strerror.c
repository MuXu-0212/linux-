#include "head.h"

#define path_doc "./dir/2.txt"

int main(int argc, char const *argv[])
{
	int fd = open(path_doc, O_RDONLY);
	printf("fd = %d, errno = %d : %s\n", fd, errno, strerror(errno));

	close(fd);
	return 0;
}