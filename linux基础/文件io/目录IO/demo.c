#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>

#define FILE_PATH "/mnt/hgfs/2212/文件IO/目录IO/代码/1.txt"

int main(int argc, char const *argv[])
{
	//功能：获取文件属性
	//参数：const char *pathname 文件路径
	//参数：struct stat *buf 传出参数 装文件信息的
	//返回值 成功获取到了文件信息则返回 0 失败则返回 -1
	struct stat buf;
	//该函数运行完毕之后,会把获取到的信息存放在buf当中
	int ret = stat(FILE_PATH, &buf);
	if (ret != 0)
	{
		perror("get info failed\n");
		return -1;
	}

	if ((buf.st_mode & S_IFMT) == S_IFREG)
	{
		printf("是普通文件\n");
	}
	else
	{
		printf("不是普通文件\n");
	}
	



	return 0;
}
