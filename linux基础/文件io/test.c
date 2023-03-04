#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


/*
	0 代表的是标准输入
	1 代表的是标准输出
	2 代表的是标准出错
*/
#define FILE_PATH_1 "/mnt/hgfs/C_CODE/新建文件夹/1.txt"
#define FILE_PATH_2 "/mnt/hgfs/C_CODE/新建文件夹/2.txt"


int main(int argc, char const *argv[])
{
	//功能 : 打开或创建一个文件
	//返回值:成功则返回一个文件描述符, 失败则返回-1
	//参数 : const char* pathname 路径名
	//参数 : int flags O_RDONLY  以只读的方式打开文件
					//O_WEONLY 以只写的方式打开文件
				    //O_RDWR   以读写的方式打开文件
	int fd = open(FILE_PATH_1, O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd == -1)
	{
		printf("打开文件失败!\n");
		return -1;
	}
	printf("文件描述符为: %d\n", fd);


	//写操作
	//功能 : 往一个文件描述符当中写入数据
	//参数 : int fd 文件描述符 往哪个文件当中写入数据
	//参数 : const void* buf 要把什么数据写入进去
	//参数 : size_t count 要写入文件的字节数
	//参数 : 成功 一定是大于0的数据 失败则是小于等于0的数据

	char write_data[54];
	memset(write_data, 0, sizeof(write_data));
	printf("请输入一个字符串>");
	scanf("%[^.]", write_data);
	// while (getchar() != '\n');

	ssize_t ret = write(fd, write_data, sizeof(write_data));

	if (ret <= 0)
	{
		printf("写入数据失败!\n");
		close(fd);
		return ret;
	}

	printf("写入了 %ld 个数据\n", ret);

	//功能 : 关闭文件
	//int fd : 文件描述符
	close(fd);
	return 0;
}


//=========================================================
/*
	可选参数
	O_APPEND 追加写入数据
	O_CREAT 如果你要打开的文件不存在, 则会自动创建
	O_EXCL 文件存在,则报错
*/

// int main(int argc, char const *argv[])
// {

// /*
// 	判断一个文件 "存在"或者"执行"的权限
//     参数:const char *path 你要判断的文件路径
//     参数:int amode R_OK, W_OK, X_OK, F_OK
//     返回值 "存在"为0, "不存在"为-1
// */

//     int fd;
//     int ret = access(FILE_PATH, F_OK);
//     if (ret == -1)
//     {
//     	fd = open(FILE_PATH, O_RDWR | O_CREAT, 0777);
//     	if (fd == -1)
//     	{
//     		printf("打开文件失败!\n");
//     		return -1;
//     	}
//     }
//     else
//     {
//     	fd = open(FILE_PATH, O_RDWR);
//     	if (fd == -1)
//     	{
//     		printf("打开文件失败\n");
//     		return -1;
//     	}
//     }

// 	return 0;
// }
