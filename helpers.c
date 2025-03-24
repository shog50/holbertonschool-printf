#include "main.h"

/**
* print_char - Prints a single character.
* @args: The argument list containing the character.
*
* Return: Number of characters printed.
*/
int print_char(va_list args)
{
char c = va_arg(args, int);

return (write(1, &c, 1));
}

/**
* print_string - Prints a string.
* @args: The argument list containing the string.
*
* Return: Number of characters printed.
*/
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (!str)
str = "(null)";

while (*str)
count += write(1, str++, 1);

return (count);
}

/**
* print_percent - Prints a literal percent sign.
*
* Return: Number of characters printed.
*/
int print_percent(void)
{
return (write(1, "%", 1));
}

/**
* print_number - Recursively prints each digit of a number.
* @num: The number to print.
*
* Return: Number of characters printed.
*/
int print_number(int num)
{
int count = 0;
char digit;

if (num / 10)
count += print_number(num / 10);

digit = (num % 10) + '0';
count += write(1, &digit, 1);

return (count);
}
