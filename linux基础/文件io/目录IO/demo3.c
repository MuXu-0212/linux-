#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

int main(int argc, char const *argv[])
{
    struct stat info;

    //获取文件属性
    stat(argv[1],&info);
    char * fileuser = getpwuid(info.st_uid)->pw_name;
	
    printf("%s\n", fileuser);
    return 0;
}
 