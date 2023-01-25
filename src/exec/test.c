#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char *cmd = "/bin/ls";
	char *env[] = {NULL};
	char *argVec[] = {"ls", "-l", "-a", NULL};
	struct stat s;
	
	if (stat(cmd, &s) == 0)
		printf("%d", s.st_mode);
		
	// if (execve(cmd, argVec, env) == -1)
	// 	printf("Error");
	printf("huh");
}