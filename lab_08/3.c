#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F_NAME_MAX 32
#define L_NAME_MAX 32

typedef struct {
    char first_name[F_NAME_MAX]; // Uwaga: tablica!
    char last_name[L_NAME_MAX];  // Uwaga: tablica!
    unsigned short age;
    size_t email_max;
    char email[];                // Uwaga: tablica elastyczna!
} Student_v3;

Student_v3 *create_student(char *first_name, char *last_name, unsigned short age, char *email);
void print_students(FILE* stream, Student_v3 *student_list, size_t n);

int main(void) {
    Student_v3 *me = create_student("Franio", "U.", 19, "tajemnica@gmail.com");
    print_students(stdout, me, 1);

    FILE *franio = fopen("franio.dat", "wb+");
    fwrite(me, sizeof(*me)+me->email_max, 1, franio);

    // valgrind krzyczy i troche nie wiem czemu
    Student_v3 *new_me = malloc(sizeof(Student_v3));
    fseek(franio, 0, SEEK_SET);
    fread(new_me, sizeof(*me), 1, franio);
    new_me = realloc(new_me, sizeof(Student_v3)+new_me->email_max);
    fread(new_me->email, new_me->email_max, new_me->email_max, franio);
    print_students(stdout, new_me, 1);

    free(me);
    free(new_me);
    fclose(franio);
}

Student_v3 *create_student(char *first_name, char *last_name, unsigned short age, char *email) {
    Student_v3 *student = malloc(sizeof(Student_v3) + strlen(email) + 1);
    strncpy(student->first_name, first_name, F_NAME_MAX-1);
    student->first_name[F_NAME_MAX-1] = '\0';
    strncpy(student->last_name, last_name, L_NAME_MAX-1);
    student->first_name[L_NAME_MAX-1] = '\0';
    student->age = age;
    student->email_max = strlen(email) + 1;
    strncpy(student->email, email, student->email_max);
    return student;
}

void print_students(FILE* stream, Student_v3 *student_list, size_t n) {
    fseek(stream, 0, SEEK_END);
    for(size_t i = 0; i < n; i++) {
        fprintf(stream, "First name: %s\nLast name: %s\nAge: %hu\nEmail: %s\n\n", student_list[i].first_name, student_list[i].last_name, student_list[i].age, student_list[i].email);
    }
}