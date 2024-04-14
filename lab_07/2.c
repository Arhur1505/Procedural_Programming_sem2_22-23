#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int my_charcmp(char a, char b)
{
    char a1, b1;

    if (isdigit(a))
        a1 = 3;
    if (isdigit(b))
        b1 = 3;
    if (isalpha(a))
        a1 = 2;
    if (isalpha(b))
        b1 = 2;

    if (a1 == b1)
    {
        return toupper(b) - toupper(a);
    }
    else
    {
        if (a1 < b1)
            return -1;
        else
            return 1;
    }
    return 0;
}

int my_strcmp(const void *a, const void *b)
{
    const char *a_char = *(const char **)a;
    const char *b_char = *(const char **)b;

    if (strlen(a_char) > strlen(b_char))
    {
        return 1;
    }
    else if (strlen(a_char) < strlen(b_char))
    {
        return -1;
    }

    int i = 0;

    while (*(a_char + i) != 0 && *(b_char + i) != 0)
    {
        int c = my_charcmp(*(a_char + i), *(b_char + i));
        if (c < 0)
        {
            return 1;
        }
        else if (c > 0)
        {
            return -1;
        }
        i++;
    }

    return 0;
}

int main()
{
    char a = 'd';
    char b = 'd';
    char c = 'D';
    char d = 'e';
    char e = '9';
    char f = '7';

    printf("a = '%c', b = '%c', c = '%c', d = '%c', e = '%c', f = '%c' \n", a, b, c, d, e, f);
    printf("Wynik a i b: %d\n", my_charcmp(a, b));
    printf("Wynik a i c: %d\n", my_charcmp(a, c));
    printf("Wynik a i d: %d\n", my_charcmp(a, d));
    printf("Wynik e i f: %d\n\n", my_charcmp(e, f));

    const char *strings[] = {"Z", "u", "REh4HmPJRS", "One", "one", "[", "@$9325", "two", "THREE", "four", "415", "@#$325", "@#$315", "@#9325", "five", "alpha", "zet", "0zero", "0123", "0", "(text)", "8", "@#$325"};

    size_t n = sizeof(strings) / sizeof(*strings);

    qsort(strings, n, sizeof *strings, my_strcmp);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(strings + i));
    }

    return 0;
}