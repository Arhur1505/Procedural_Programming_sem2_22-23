#include "Student_v1.h"
#include <stdio.h>
#include <stdlib.h>

size_t count_students(FILE* list);
Student_v1* get_students(FILE* list, size_t n);
void print_students(FILE* stream, Student_v1 *student_list, size_t n);
void free_all(Student_v1 **student_list, size_t n);

int main(void) {
    FILE *dziekanat = fopen("./Students.csv", "r+");
    size_t n = count_students(dziekanat);
    Student_v1 *student_list = get_students(dziekanat, n);
    
    qsort(student_list, n, sizeof(*student_list), students_cmp);
    
    Student_v1 student_to_find = {.age = 23, "bilfooter@tumblr.com", .first_name = "Weider", "Bilfoot"};
    print_student(bsearch(&student_to_find, student_list, n, sizeof(*student_list), students_cmp));
    
    fprintf(dziekanat, "\n--- SORTED ---\n");
    print_students(dziekanat, student_list, n);

    free_all(&student_list, n);
    fclose(dziekanat);
    return 0;
}

size_t count_students(FILE* list) {
    fseek(list, 0, SEEK_SET);
    char line[100];
    size_t counter = 0;
    while(fgets(line, 100, list)) {
        counter++;
    }
    return counter;
}

Student_v1* get_students(FILE* list, size_t n) {
    fseek(list, 0, SEEK_SET);
    Student_v1* student_list = malloc(n * sizeof(Student_v1));
    char first_name[100];
    char last_name[100];
    for(size_t i = 0; i < n; i++) {
        fscanf(list, "%s , %s , %hu , %s", first_name, last_name, &student_list[i].age, student_list[i].email);
        set_first_name(student_list+i, first_name);
        set_last_name(student_list+i, last_name);
    }
    return student_list;
}

void print_students(FILE* stream, Student_v1 *student_list, size_t n) {
    fseek(stream, 0, SEEK_END);
    for(size_t i = 0; i < n; i++) {
        fprintf(stream, "%s , %s , %hu , %s\n", student_list[i].first_name, student_list[i].last_name, student_list[i].age, student_list[i].email);
    }
}

void free_all(Student_v1 **student_list, size_t n) {
    for(size_t i = 0; i < n; i++) {
        free_student(*student_list+i);
    }
    free(*student_list);
    *student_list = NULL;
}