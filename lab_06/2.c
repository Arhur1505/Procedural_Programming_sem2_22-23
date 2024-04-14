#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void join_snake_case(char **str1, int *size, char *str2)
{
    int str2_len = strlen(str2);
    int new_size = *size + str2_len + 1;

    *str1 = realloc(*str1, new_size + 1);
    if (*size > 0)
    {
        strcat(*str1, "_");
    }
    strcat(*str1, str2);
    *size = new_size;
}

void to_camel_case(char *str)
{
    char *tmp;
    char *result = malloc(strlen(str) + 1);

    tmp = strtok(str, "_");
    strcat(result, tmp);

    printf("%s \n", tmp);

    strcpy(str, result);
    free(result);
}

int main(int argc, char *argv[])
{
    char *result = NULL;

    int size = 0;

    for (int i = 1; i < argc; i++)
    {
        join_snake_case(&result, &size, argv[i]);
    }

    printf("%s\n", result);

    to_camel_case(result);

    free(result);
}