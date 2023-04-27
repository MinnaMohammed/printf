#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printcs -  produces output according to a format.
 *
 *@format: a character
 *@string: a string pointer
 * Return: Always 0 (Success)
*/
void _printcs(const char format, char *string)
{
	int i = 0, j;

	if (format == 'c')
	{
		if (string == NULL)
		{
			string = "(nil)";
		}
		_putchar(string[i]);
	}
	else if (format == 's')
	{
		for (j = 0; string[j] != '\0'; j++)
		{
			if (string == NULL)
			{
				string = "(nil)";
			}
			_putchar(string[j]);
		}
	}
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
	char *c;
	char *s;

	if (format == NULL)
	{
		return (0);
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
				_printcs(value, s);
			}
			else if (value == 'c')
			{
				c = va_arg(argument, char *);
				_printcs(value, c);
			}
			else if (value == '%')
			{
				_putchar('%');
			}
			i++;
		}
		_putchar(format[i]);
		i++;
	}
	va_end(argument);
	return (i);
}
