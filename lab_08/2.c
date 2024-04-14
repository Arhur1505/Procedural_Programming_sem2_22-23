#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define EMAIL_MAX 50  // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 50 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 50 // Rozmiar tablicy last_name w strukturze.

typedef struct {
    char first_name[F_NAME_MAX];
    char last_name[L_NAME_MAX];  // Uwaga: tablica!
    unsigned short age;
    char email[EMAIL_MAX];
} Student_v2;

void print_students(FILE* stream, Student_v2 *student_list, size_t n);

int main(void) {
    #include "array.h"
    size_t n = sizeof(students)/sizeof(*students);
    FILE *binarny_dziekanat = fopen("binarny_dziekanat.dat", "wb+");
    fwrite(students, sizeof(*students), n, binarny_dziekanat);
    
    fseek(binarny_dziekanat, 0, SEEK_SET);
    Student_v2 students_new[n];
    fread(students_new, sizeof(*students), n, binarny_dziekanat);
    print_students(stdout, students_new, n);

    fclose(binarny_dziekanat);
}

void print_students(FILE* stream, Student_v2 *student_list, size_t n) {
    fseek(stream, 0, SEEK_END);
    for(size_t i = 0; i < n; i++) {
        fprintf(stream, "First name: %s\nLast name: %s\nAge: %hu\nEmail: %s\n\n", student_list[i].first_name, student_list[i].last_name, student_list[i].age, student_list[i].email);
    }
}