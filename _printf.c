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
		if (string  == 	NULL)
		{
			return (0);
		}

		for (j = 0; string[j] != '\0'; j++)
		{
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
long int _printd(long int num)
{
	long int count = 0, new = num;

	while (new != 0)
	{
		if (new < 0)
		{
			new = -new;
		}
		new = new / 10;
		count++;
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}
	if (num / 10)
	{
		_printd(num / 10);
	}
	_putchar(num % 10 + '0');
	if (num == 0)
	{
		return (1);
	}
	return (count);
}
/**
 * _printb -  produces output according to a format.
 *
 *@num: a number
 * Return: Always 0 (Success)
*/
unsigned long int _printb(long int num)
{
	unsigned long int count = 0;
	long int new[100];
	int i = 0, j;

	if (num == 0)
	{
		_putchar(num + '0');
		return (1);
	}

	if (num < 0)
	{
		num = -num;
	}

	if (num == 1)
	{
		_putchar(num + '0');
		return (1);
	}

	while (num != 0)
	{
		new[i] = num % 2;
		num = num / 2;
		count++;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(new[j] + '0');
	}
	return (count);
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
	long int d;
	long int b;

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
				if (format[i + 2] == '\0')
				{
					break;
				}
			}
			else if (value == '%')
			{
				_putchar('%');
				count++;
				if (format[i + 2] == '\0')
				{
					break;
				}
			}
			else if (value == 'd' || value == 'i')
			{
				d = va_arg(argument, int);
				count += _printd(d);
				if (format[i + 2] == '\0')
				{
					break;
				}
			}
			else if (value == 'b')
			{
				b = va_arg(argument, int);
				count += _printb(b);
				if (format[i + 2] == '\0')
				{
					break;
				}

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
