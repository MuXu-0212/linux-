#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH "/mnt/hgfs/2212/文件IO/标准IO/code/1.txt"

int main(int argc, char const *argv[])
{

	// 函数功能：打开一个普通文件
	// 参数const char *path：路径
	// 参数const char *mode : 你要使用什么权限打开该文件
	// 返回值 ： 成功则返回一个指向文件的指针 失败 NULL
	FILE * fp = fopen(FILE_PATH, "w");
	if (fp == NULL)
	{
		perror("open file failed\n");
		return -1;
	}

	// 函数功能：把某些数据写入到文件当中去
	// 参数 const void *ptr：你要写入的数据是什么
	// 参数 size_t size  :   你要写入多大的数据
	// 参数 size_t nmemb :   你要写入多少块数据  写入数据的总大小为 size * nmemb
	// FILE *stream	  :   文件流指针 你要往哪个文件当中写入数据
	// 返回值 成功则返回 成功写入的块数 失败 <= 0
    size_t ret = fwrite("12345", 5, 1,fp);
	if (ret <= 0)
	{
		perror("write data failed\n");
		return -2;
	}
	printf("成功写入了 %ld 块的数据\n",ret);

	fclose(fp);


	fp = fopen(FILE_PATH, "r+");
	if (fp == NULL)
	{
		perror("open file failed\n");
	}

	fseek(fp, 0, SEEK_END);

	//功能：获取从文件开头处到光标的当前位置有多少个偏移量;
	long v = ftell(fp);
	printf("偏移量：%ld\n", v);

	fseek(fp, 0, SEEK_SET);
	//函数功能 移动光标所在位置
	//FILE *stream : 你要移动哪个文件的光标
	//long offset  : 偏移量
	//int whence   : SEEK_SET 文件开头处 SEEK_CUR 当前位置 SEEK_END 移动到文件末尾处
	//fseek(fp, 0, SEEK_SET);


    // 函数功能：从文件当中读取数据
	// 参数 void *ptr ：你读取的数据存放到哪里
	// 参数 size_t size  :   你要读多大的数据
	// 参数 size_t nmemb :   你要读多少块数据  读入数据的总大小为 size * nmemb
	// FILE *stream	  :   文件流指针 你要往哪个文件当中读取数据
	// 返回值 成功则返回 成功读取的块数 失败 <= 0
	char read_data[128];
	memset(read_data, 0 , sizeof(read_data));
	ret = fread(read_data, sizeof(read_data), 1, fp);
	printf("%ld\n",ret);
	if (ret <= 0)
	{
		//feof(fp):光标到达文件末尾处,但是数据不够我指定读取的块数
		if (ret = feof(fp)) 
		{
			printf("到达文件末尾处 %ld \n",ret);
			printf("成功读取了 %ld 块的数据\n",ret);
			printf("读取到的数据为 %s\n",read_data);
		}
		else //真的读取文件失败
		{
			perror("read data failed\n");
			return -3;
		}
	}

	fclose(fp);
}
