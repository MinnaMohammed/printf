#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _prints -  produces output according to a format.
 *
 *@string: a string pointer
 * Return: Always 0 (Success)
*/
void _prints(char *string)
{
	int j;

		for (j = 0; string[j] != '\0'; j++)
		{
			if (string == NULL)
			{
				exit(98);
			}
			_putchar(string[j]);
		}
}
/**
 * _printc -  produces output according to a format.
 *
 *@c: a character
 * Return: Always 0 (Success)
*/
void _printc(char c)
{
	_putchar(c);
	_putchar('\n');
}
/**
 * _printf -  produces output according to a format.
 *
 *@format: a character string
 * Return: Always 0 (Success)
*/
int _printf(const char *format, ...)
{
	int i = 0;
	char value;
	va_list argument;
	char c;
	char *s;

	if (format == NULL)
	{
		exit(98);
	}
	va_start(argument, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			value = format[i + 1];
			if (value == 's')
			{
				s = va_arg(argument, char *);
				_prints(s);
			}
			else if (value == 'c')
			{
				c = va_arg(argument, int);
				_printc(c);
			}
			else if (value == '%')
			{
				_putchar('%');
			}
			i += 2;
		}
		_putchar(format[i]);
		i++;
	}
	va_end(argument);
	return (i);
}
