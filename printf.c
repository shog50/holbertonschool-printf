#include "main.h"
#include <stdarg.h>

/**
* handle_char - Handles the %c format specifier.
* @args: Argument list containing the character.
* Return: Number of characters printed.
*/
int handle_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
* handle_string - Handles the %s format specifier.
* @args: Argument list containing the string.
* Return: Number of characters printed.
*/
int handle_string(va_list args)
{
int count = 0;
char *str = va_arg(args, char *);

if (!str)
str = "(null)";

while (*str)
count += _putchar(*str++);

return (count);
}

/**
* handle_percent - Handles the %% format specifier.
* Return: Number of characters printed.
*/
int handle_percent(void)
{
return (_putchar('%'));
}

/**
* _printf - Produces output according to a format.
* @format: Format string containing specifiers.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

if (!format)
return (-1); /* Handle NULL format */

va_start(args, format);

while (*format)
{
if (*format == '%') /* Handle format specifiers */
{
format++;
switch (*format)
{
case 'c':
count += handle_char(args);
break;
case 's':
count += handle_string(args);
break;
case '%':
count += handle_percent();
break;
default: /* Handle unknown specifier */
count += _putchar('%');
count += _putchar(*format);
}
}
else /* Handle regular characters */
{
count += _putchar(*format);
}
format++;
}

va_end(args);
return (count);
}

