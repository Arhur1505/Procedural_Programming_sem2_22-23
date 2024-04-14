#include "Student_v1.h"
#include <stdio.h>
#include <stdlib.h>

int count_students(FILE *list)
{
    char line[256];
    int a = 0;
    while (fgets(line, 256, list))
    {
        a++;
    }
    return a;
}

Student_v1 *students_tab(FILE *list, int n)
{
    Student_v1 *student_list = malloc(n * sizeof(Student_v1));
    char first_name[256];
    char last_name[256];
    for (int i = 0; i < n; i++)
    {
        fscanf(list, "%s , %s , %hu , %s", first_name, last_name, &student_list[i].age, student_list[i].email);
        set_first_name(student_list + i, first_name);
        set_last_name(student_list + i, last_name);
    }
    return student_list;
}

void free_all(Student_v1 **student_list, int n) {
    for(int i = 0; i < n; i++) {
        free_student(*student_list+i);
    }
    free(*student_list);
    *student_list = NULL;
}

int main()
{
    FILE *plik = fopen("./Students.csv", "r+");
    int a = count_students(plik);
    printf("Ilość studentów: %d \n", a);

    rewind(plik); 
    Student_v1 *student_list = students_tab(plik, a);

    rewind(plik);
    qsort(student_list, a, sizeof(*student_list), students_cmp);

    rewind(plik);
    Student_v1 student_to_find = {.age = 33, "jgonnin9@eepurl.com", .first_name = "Jillie", "Gonnin"};
    print_student(bsearch(&student_to_find, student_list, a, sizeof(*student_list), students_cmp));

    free_all(&student_list, a);
    fclose(plik);
    return 0;
}