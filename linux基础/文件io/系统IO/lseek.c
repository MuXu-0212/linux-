#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <error.h>


#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"

int main(int argc, char const *argv[])
{
	int fd = open(FILE_PATH, O_RDWR);
	if (fd == -1)
	{
		perror("open file failed\n");
		return -1;
	}

	write(fd,"1234567890",10);

	//功能：移动光标所在的位置
	//参数 int fd : 你要移动哪个文件的光标 文件描述符
	//参数 off_t offset : 偏移量
		//如果该参数为负数 则向左偏移 整数 则向右偏移
	//参数 int whence  : 确定光标的所在位置
			//SEEK_SET   把光标移动到文件的开头处
			//SEEK_CUR 	 光标的当前位置
			//SEEK_END   把光标移动到文件的末尾处
	lseek(fd, 0, SEEK_SET);


	char read_buf[20] = {0};
	int ret = read(fd, read_buf, sizeof(read_buf));
	printf("读取了 %d 个数据\n",ret);
	printf("读取到的数据为 %s\n",read_buf);

	close(fd);
	

	return 0;
}
