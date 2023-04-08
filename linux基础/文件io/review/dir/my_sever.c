#include <arpa/inet.h>
#include <stido.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int jack = socket(AF_INIET, SOCK_STREAM, 0);
	if (jack == -1)
	{
		printf("创建套接字失败\n");
		return -1;
	}

	struct sockaddr_in jack_addr;
	memset(&jack_addr, 0 , sizeof(jack_addr));

	jack_addr.sin_family = AF_INET;
	jack_Add.sin_port = htons(atoi(argv[1]));

	jack_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(jack, (struct sockaddr *)&jack_addr, sizeof(jack_addr));

	if (ret != 0)
	{
		printf("绑定失败\n");
		return -1;
	}


	listen(jack, 1);


	
	return 0;
}