#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15

char *read_line(void)
{
    char *str = malloc(SIZE);
    char c = getchar();
    int i = 0;

    do
    {
        *(str + i) = c;
        i++;
        if (i % SIZE == 0)
        {
            str = realloc(str, i + SIZE);
        }
    } while ((c = getchar()) != '\n');
    *(str + i) = '\0';
    return str;
}

char *trim(char *string)
{
    return realloc(string, strlen(string) + 1);
}

void safe_free(void **my_tab)
{
    if (my_tab && *my_tab)
    {
        free(*my_tab);
        *my_tab = NULL;
    }
}

char *find_first_char_from_set(const char *input_string, const char *set)
{
    const char *a = input_string;
    const char *b = set;

    for (size_t j = 0; j != strlen(input_string); j++)
    {
        for (size_t i = 0; i != strlen(set); i++)
        {
            if (*(b + i) == *(a + j))
            {
                return (char *)(a + j);
            }
        }
    }
    return NULL;
}

int hmw(const char *input_string, const char *set)
{
    int counter = 1;

    if (input_string == NULL || strlen(input_string) == 0)
        return 0;

    while ((input_string = find_first_char_from_set(input_string, set)))
    {
        input_string++;

        while (input_string == find_first_char_from_set(input_string, set))
        {
            input_string++;
        }
        counter++;
    }
    return counter;
}

int main()
{
    printf("Lancuch: ");
    char *str = read_line();
    printf("Zbior znakow: ");
    char *set = read_line();

    str = trim(str);
    set = trim(set);

    printf("Wskaznik: %p \n", find_first_char_from_set(str, set));

    safe_free((void **)&str);
    safe_free((void **)&set);

    printf("Lanuch: ");
    str = read_line();
    set = " \t";

    printf("Slow: %d", hmw(str, set));

    safe_free((void **)&str);
    safe_free((void **)&set);

    return 0;
}