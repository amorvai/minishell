#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i;

	i = 0;
		printf("\n");
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
