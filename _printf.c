#include <stdio.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_char - prints a character
 * @b: the buffer
 * @c: the character to print
 * @counter: the pointer to the character
 * @i: the pointer to the buffer
 */
void print_char(char *b, char c, int *counter, int *i)
{
	b[*i] = c;
	(*i)++;
	(*counter)++;
}

/**
 * print_string - prints a string
 * @b: the buffer
 * @s: the string to print
 * @counter: pointer
 * @i: pointer to the buffer
 */
void print_string(char *b, char *s, int *counter, int *i)
{
	while (*s != '\0')
	{
		b[*i] = *s;
		s++;
		(*i)++;
		(*counter)++;
	}
}

/**
 * print_percent - prints a percent
 * @b: the buffer to write to
 * @counter: pointer
 * @i:pointer to the buffer
 */
void print_percent(char *b, int *counter, int *i)
{
	b[*i] = '%';
	(*i)++;
	(*counter)++;
}

/**
 * _printf - write output to stdout
 * @format: the format string
 * @...: arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char b[BUFFER_SIZE];
	int counter = 0, i = 0;
	
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				print_char(b, (char)c, &counter, &i);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				print_string(b, s, &counter, &i);
			}
			else if (*format == '%')
			{
				print_percent(b, &counter, &i);
			}
		}
		else
		{
			print_char(b, *format, &counter, &i);
		}
		format++;
	}

	va_end(args);

	write(1, b, i);
	return (counter);
}
