#include <stddef.h>
#include "../main.h"

int main(void)
{
    _printf("Simple sentence: Hello, world!\n");
    _printf("Character: [%c]\n", 'H');
    _printf("String: [%s]\n", "I am a string!");
    _printf("Percent: [%%]\n");
    _printf("NULL string: [%s]\n", NULL);
    return (0);
}

