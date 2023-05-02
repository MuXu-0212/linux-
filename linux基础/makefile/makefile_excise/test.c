#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <strings.h>
#include<stdlib.h>

#define FILE_PATH "/mnt/hgfs/c_code/WH2212/3/4系统IO/排行榜.txt"

typedef struct node
{
	char name[20];
	int cj;
}node,*node_p;

void Write_Txt(int fd,node_p a)
{
	char s[10];
	for (int i = 0; i < 3; i++)
	{
		memset(s,0,sizeof(s));
		write(fd,a[i].name,10);
		
		sprintf(s,"%d",a[i].cj);
		write(fd," ",1);
		write(fd,s,strlen(s));
		write(fd,"\r\n",strlen("\r\n"));
	}
}

void Show(node_p a)
{
	printf("排行榜：\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s",a[i].name);
		printf("%d",a[i].cj);
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	node a[3] = {
		{.name = "张三",.cj = 67},
		{.name = "李四",.cj = 66},
		{.name = "王五",.cj = 65}
	};
	char c[50] = {0};
	int fd = open(FILE_PATH,O_RDWR | O_CREAT);
	//Write_Txt(fd,a);
	read(fd,c,50);
	//Show(a);
	printf("%s\n",c);

	close(fd);
	

	fd = open(FILE_PATH,O_RDWR);
	char arr[50] = {0};
	char arr1[50] = {0};
	//偏移光标
	lseek(fd,0,SEEK_SET);
	for (int i = 0; i < 3; i++)
	{
		memset(arr,0,sizeof(arr));
		memset(arr,0,sizeof(arr1));
		//读名字
		read(fd,arr,10);
		//printf("%s\n",arr);
		//偏移光标
		lseek(fd,1,SEEK_CUR);
		//读成绩
		read(fd,arr1,2);
		//printf("%s\n",arr1);
		strcpy(a[i].name,arr);
		a[i].cj = atoi(arr1);
		//printf("%d\n",a[i].cj);
		lseek(fd,2,SEEK_CUR);
		
	}
	Show(a);

	node p;
	node tmp;
	printf("新成绩：\n");
	printf("姓名：\n");
	scanf("%s",p.name);
	printf("成绩:\n");
	scanf("%d",&p.cj);
	//fd = open(FILE_PATH,O_RDWR | O_TRUNC);
	lseek(fd,0,SEEK_SET);
	for (int i = 0; i < 3; i++)
	{
		if (p.cj > a[i].cj)
		{
			strcpy(tmp.name,a[i].name);
			tmp.cj = a[i].cj;
			strcpy(a[i].name,p.name);
			a[i].cj = p.cj;
			strcpy(p.name,tmp.name);
			p.cj = tmp.cj;
		}
		
	}
	Write_Txt(fd,a);
	Show(a);







close(fd);

	return 0;
}

