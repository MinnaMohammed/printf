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
	int len =  _printf("Character:[%c]\n", 'H');
	printf("Length:[%d]\n", len);
	return (0);
}
