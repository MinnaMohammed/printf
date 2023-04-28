#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", NULL);
	printf("L:[%d]\n", len);
	
	return (0);
}
