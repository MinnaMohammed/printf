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
	len = _printf("%d", -1232);
	printf("[%d]\n", len);
	printf("[%d,%i]\n",INT_MAX,INT_MAX);
	return (0);
}
