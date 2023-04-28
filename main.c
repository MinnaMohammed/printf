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
	int len;
	len = _printf("%s\n", "This sentence vaargs");
	printf("[%d]\n", len);
	return (0);
}
