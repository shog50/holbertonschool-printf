#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
* _printf - Produces output according to a format
* @format: Format string containing the directives
* Return: Number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
int i; /* Declare variables outside the loop */

if (!format)
return (-1);

va_start(args, format);

for (i = 0; format[i] != '\0'; i++) /* Use declared variable */
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
int j; /* Declare variables outside the inner loop */
if (!str)
str = "(null)";
for (j = 0; str[j] != '\0'; j++, count++)
write(1, &str[j], 1);
}
else if (format[i] == '%')
{
printf("%%");
count++;
}
else
{
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
}
}
else
{
write(1, &format[i], 1);
count++;
}
}

va_end(args);
return (count);
}

