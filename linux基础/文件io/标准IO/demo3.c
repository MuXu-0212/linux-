#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH1 "/mnt/hgfs/2212/文件IO/标准IO/code/1.txt"

int main(int argc, char const *argv[])
{
	//从文件当中获取
	FILE * file1_fp = fopen(FILE_PATH1,"r+");
	if (file1_fp == NULL)
	{
		perror("open file1 failed\n");
		return -1;
	}

	// int ret = fgetc(file1_fp);
	// printf("%c\n",ret);


	//从键盘获取
	//int ret = fgetc(stdin);
	//printf("%c\n",ret);

	//输出到屏幕
	//fputc('C',stdout);

	//char buf[100];
	//返回值 成功 返回成功读取的数据 失败返回NULL
	//char *p = fgets(buf, sizeof(buf), stdin);
	//printf("%s",p);

	//fputs("1234567890000000\n", stdout);


	fprintf(file1_fp, "ABNKASJDAOLISHDKAHS\n");

	//char buf[100];
	//fscanf(file1_fp,"%s",buf);
	//printf("%s\n",buf);


	return 0;
}
