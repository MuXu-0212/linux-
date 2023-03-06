#include <stdio.h>

#include <unistd.h>	
/*关闭头文件, int close(int fd)关闭成功返回0, 失败返回-1
  读取数据, ssize_t read(int fd ,void* buf, size_t count)
  写入数据, ssize_t write(int fd ,void* buf, size_t count)
	*/
#include <sys/stat.h>
#include <sys/types.h>/*& #include<unistd.h>*/
/*移动文件的读写位置 off_t lseek(int fildes, off_t offset, int whence)
	*/

#include <fcntl.h>
#include <string.h>

#include <errno.h>  
/*perror("")错误提示示例代码

	*/

#define FILE_PATH "/mnt/hgfs/C_CODE/系统IO/test_open.txt"
#define MAXSIZE 50
int main(int argc, char const *argv[])
{
	int fd_creat = open( FILE_PATH, O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd_creat == -1)
	{
		perror("打开文件失败\n");
		return -1;
	}
	printf("文件描述符为%d\n", fd_creat);

	int fd_open = open( FILE_PATH, O_RDWR);
	char write_data[MAXSIZE];
	memset(write_data, 0, sizeof(write_data));

	printf("请输入一个字符串>");
	scanf("%[^\n]", write_data);
	while (getchar() != '\n');

	ssize_t ret = write( fd_open, write_data, sizeof(write_data));

	if (ret <= 0)
	{
		printf("写入数据失败!\n");
		return 0;
	}

	printf("写入了 %ld 个数据!\n", ret);

	close(fd_creat);
	close(fd_open);
	return 0;
}