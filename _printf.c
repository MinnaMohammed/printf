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
int _prints(char *string)
{
	int j, counter = 0;

		for (j = 0; string[j] != '\0'; j++)
		{
			if (string == NULL)
			{
				exit(98);
			}
			_putchar(string[j]);
			counter++;
		}
		return (counter);
}
/**
 * _printc -  produces output according to a format.
 *
 *@c: a character
 * Return: Always 0 (Success)
*/
int _printc(char c)
{
	if (c == '\0')
	{
		return (-1);
	}
	_putchar(c);
	return (1);
}
/**
 * _printf -  produces output according to a format.
 *
 *@format: a character string
 * Return: Always 0 (Success)
*/
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char value;
	va_list argument;
	char c;
	char *s;

	if (format == NULL)
		exit(98);
	va_start(argument, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			value = format[i + 1];
			if (value == 's')
			{
				s = va_arg(argument, char *);
				count += _prints(s);
			}
			else if (value == 'c')
			{
				c = va_arg(argument, int);
				count += _printc(c);
			}
			else if (value == '%')
			{
				_putchar('%');
				count++;
			}
			else if (value != '!' || value != 'K')
				count++;
			i += 2;
		}
		else
			count++;
		_putchar(format[i]);
		i++;
	}
	va_end(argument);
	return (i);
}
