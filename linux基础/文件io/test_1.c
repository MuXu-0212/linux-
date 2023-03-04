#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH(x) "/mnt/hgfs/C_CODE/新建文件夹/新建文件夹/%d.txt"
#define MAXSIZE_INPUT 50


int main(int argc, char const *argv[])
{
	int i = 1;
	while (1)
	{
		int fd = open(FILE_PATH(i), O_RDWR | O_CREAT | O_EXCL, 0777);
		if ( fd == -1)
		{
			break;
		}
	}
	

	if (fd == -1)
	{
		printf("文件打开失败!\n");
		return 0;
	}
	printf("文件描述符为 : %d\n", fd);

	char write_data[MAXSIZE_INPUT];
	memset(write_data, 0, sizeof(write_data));

	printf("请输入用户信息>");
	scanf("%[^.]", write_data);

	ssize_t ret = write(fd, write_data, sizeof(MAXSIZE_INPUT));
	if (ret <= 0)
	{
		printf("写入数据失败!\n");
		close(fd);
		return 1;
	}

	close(fd);
	return 0;
}