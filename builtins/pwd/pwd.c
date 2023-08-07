#include <unistd.h>
#include <stdio.h>

int main()
{
	char cwd[1000000];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", getcwd(cwd, sizeof(cwd)));
	else
	{
		perror("getcwd() error");
		exit (1);
	}
	exit (0);
}
