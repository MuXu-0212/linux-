#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"

int main(int argc, char const *argv[])
{
	int fd = open(FILE_PATH, O_RDWR | O_CREAT, 0777);
	if (fd == -1)
	{
		printf("打开文件失败\n");
		return -1;
	}

	char read_data[100];
	ssize_t ret = read(fd, read_data, sizeof(read_data));
	if (ret > 0)
	{
		printf("读取了%ld个字节数据\n",ret);
		printf("读取的数据为%s:\n",read_data);
	}
	



	close(fd);

	return 0;
}
