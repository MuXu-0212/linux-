#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


// 0 代表的是标准输入
// 1 代表的是标准输出
// 2 代表的是标准出错
#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"
#define FILE_PATH1 "/mnt/hgfs/2212/文件IO/代码/2.txt"

int main(int argc, char const *argv[])
{
	//功能  : 打开或创建一个文件
	//返回值: 成功打开则返回一个文件描述符 失败则返回-1
	//参数 : const char *pathname 路径名
	//参数 : int flags  O_RDONLY    以只读的方式打开文件
					   //O_WRONLY   以只写的方式打开文件
					   //O_RDWR		以读写的方式打开文件
	int fd = open(FILE_PATH, O_RDWR);
	if (fd == -1)
	{
		printf("打开文件失败\n");
		return -1;
	}
	printf("文件描述符为：%d\n",fd);

	//写操作
	//功能: 往一个文件描述符当中写入数据
	//参数：int fd 文件描述符 你要往哪个文件当中写入数据
	//参数：const void *buf 你要把什么数据写入进去
	//参数: size_t count 你要写多少个字节到该文件当中去
	//返回值： 成功 一定是大于0的数据 失败则是小于等于0的数据

	char w_data[54];
	memset(w_data,0,sizeof(w_data));
	printf("请输入一个字符串:\n");
	scanf("%s",w_data);

	ssize_t ret = write(fd, "12345", 5);
	if (ret <= 0)
	{
		printf("写入数据失败\n");
		close(fd);
		return -2;
	}

	printf("写入了 %d 个数据\n",ret);
	
	//功能：关闭文件
	//int fd ：文件描述符
	close(fd);
	return 0;
}
