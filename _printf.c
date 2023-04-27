#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf -  produces output according to a format.
 *
 *@format: a character string
 * Return: Always 0 (Success)
*/
void _printcs(const char *format)
int _printf(const char *format, ...)
{
	int i = 0, j;
	char value;
	va_list argument;
	char c;
	char *s;
	
	if (format == NULL)
	{
		return (0);
	}

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			value = format[i + 1];
			i++;
		}
		i++;
	}
	
	va_start(argument, format);


	if (value == '%')
	{
		_putchar('%');
		_putchar('\n');
	}
	else if (value == 'c')
	{
		c = va_arg(argument, char);
		
		if (c == NULL)
		{
			c = "(nil)";
		}
		_putchar(c);
		_putchar('\n');
	}
	else if (value == 's')
	{
		for (j = 0; j != '\0'; j++)
		{
			s = va_arg(argument, char *);
			if (s == NULL)
			{
				s = "(nil)";
			}
			_putchar(s[j]);
		}
		_putchar('\n');
	}

}

