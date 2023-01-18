#include <sys/stat.h>
#include <stdio.h>

int main(){
	int i;
	struct stat *h;
	
	if (stat("not here", h) != 0)
		printf("Not Found");
}