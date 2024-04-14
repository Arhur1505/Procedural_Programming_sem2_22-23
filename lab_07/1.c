#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void my_printf(const char *format, ...);

int main(){

    const char *text8 = "Liczba osemkowa";
    const char *text10 = "Liczba dziesietna";
    const char *text16 = "Liczba szesnastkowa";
    unsigned int decimal = 2662834401u;

    printf("my_printf | printf\n");
    my_printf("");
    my_printf("Brak specyfikatorow! ");
    printf("| Brak specyfikatorow!\n");
    my_printf("%s:", text10);
    my_printf(" %u ", decimal);
    printf("| %s:", text10);
    printf(" %u\n", decimal);
    my_printf("Jeden specyfikator: %X, koniec! ", decimal);
    printf("| Jeden specyfikator: %X, koniec!\n", decimal);
    my_printf("%s: %u, %s: %o, %s: %X", text10, decimal, text8, decimal, text16, decimal);
    printf("| %s: %u, %s: %o, %s: %X\n", text10, decimal, text8, decimal, text16, decimal);
    

    return 0;
}

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    if (strlen(format) == 0)
        return;

    char cpy[strlen(format) + 1];
    strcpy(cpy, format);

    char *str = strtok(cpy, "%");
    if (*str == *cpy)
    {
        printf("%s", str);
        str = strtok(NULL, "%");
    }

    while (str)
    {
        switch (*str)
        {
        case 's':
            printf("%s", va_arg(args, char *));
            break;
        case 'u':
            printf("%u", va_arg(args, unsigned int));
            break;
        case 'o':
            printf("%o", va_arg(args, unsigned int));
            break;
        case 'X':
            printf("%X", va_arg(args, unsigned int));
            break;
        }
        printf("%s", str + 1); 
        str = strtok(NULL, "%");
    }
    va_end(args);
}