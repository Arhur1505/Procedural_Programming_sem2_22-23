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
    FILE *binarny_plik = fopen("binarny_plik.dat", "wb+");
    fwrite(students, sizeof(*students), n, binarny_plik);
    
    fseek(binarny_plik, 0, SEEK_SET);
    Student_v2 students_v3[n];
    fread(students_v3, sizeof(*students), n, binarny_plik);
    print_students(stdout, students_v3, n);

    fclose(binarny_plik);
}

void print_students(FILE* stream, Student_v2 *student_list, size_t n) {
    fseek(stream, 0, SEEK_END);
    for(size_t i = 0; i < n; i++) {
        fprintf(stream, "First name: %s\nLast name: %s\nAge: %hu\nEmail: %s\n\n", student_list[i].first_name, student_list[i].last_name, student_list[i].age, student_list[i].email);
    }
}