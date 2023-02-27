#include "stdio.h"
#include "unistd.h"


int main ()
{
	printf("%i\n", getpid());
	while (1)
		;
	return (0);
}
