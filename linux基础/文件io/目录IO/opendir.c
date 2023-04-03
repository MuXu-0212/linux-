#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>



int main(int argc, char const *argv[])
{

	DIR* dp = opendir(argv[1]);
	struct dirent* sdp;

	if (dp == NULL)
	{
		perror("opendir error");
		exit(1);
	}

	while ((sdp = readdir(dp)) != NULL)
	{
		printf("%s\t", sdp->d_name);
	}

	printf("\n");

	closedir(dp);



	return 0;
}

