#include <stdio.h>
#include <unistd.h>
/**
 * main - adds the numbers 3 and 5 and 
 * displays the result and the parent process id
 * Return: Always 0
 */

int main(void)
{
	int a = 3;
	int b = 5;
	int sum = a + b;
	pid_t ppid;

	ppid = getppid();

	printf("sum is %d\n", sum);
	printf("pid is %d\n", ppid);

	return (0);
}
