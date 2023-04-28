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
				return (0);
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
		return (0);
	}
	_putchar(c);
	return (1);
}
/**
 * _printd -  produces output according to a format.
 *
 *@num: a number
 * Return: Always 0 (Success)
*/
int _printd(int num)
{
	int  count = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}

	if (num / 10)
	{
		count++;
		_printd(num / 10);
	}
	_putchar(num % 10 + '0');
	return (count + 2);
}
/**
 * _printf -  produces output according to a format.
 *
 *@format: a character string
 * Return: Always 0 (Success)
*/
int _printf(const char *format, ...)
{
	int i = 0, count = 0, flag = 0;
	char value;
	va_list argument;
	char c;
	char *s;
	int d;

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
				if (_prints(s) == 0)
				{
					count = 0;
					exit(98);
				}
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
			else if (value == 'd')
			{
				d = va_arg(argument, int);
				count += _printd(d);
			}
			else if (value == '\0')
			{
				exit(98);
			}
			else if (value != 'c' || value != 's' || value != '%' || value != '\0')
			{
				_putchar(format[i]);
				_putchar(value);
				_putchar('\n');
				count = 3;
				break;
			}	
			else
				count++;
			i += 2;
			flag = 1;
		}
		else
			count++;
		_putchar(format[i]);
		if (flag == 1 && format[i] != '\0')
		{
			count++;
			flag = 0;
		}
		i++;
	}
	va_end(argument);
	return (count);
}
