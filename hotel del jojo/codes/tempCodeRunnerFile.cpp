#include <stdio.h>
#include <string.h>
#include <stdlib.h> // dynamic memory allocation (malloc.h)
// Array: banyak elemen -> array of int, array of char, array of float, dkk..
// Array of Struct : elemen yang memiliki beberapa tipe data

// CRUD: Create, Read, Update, Delete 

struct Course {
    char ID[10];
    char namaDosen[255];
};

struct Student { // singular-capital
    char name[255]; 
    double GPA;
    Course c; // course yang diikuti oleh student
};

// 255 bytes + 8 bytes + 10 bytes + 255 bytes = sizeof(Student) = size dari Student object

// malloc -> memory allocation : alokasikan memory untuk menyimpan sesuatu
// = malloc(sizeof(Student))
// = malloc(255+8+10+255)

// Create
Student* create(const char *name, double GPA, const char *id, const char *namaDosen) {
    // 6 baris
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->GPA = GPA;
    strcpy(newStudent->c.ID, id);
    strcpy(newStudent->c.namaDosen, namaDosen);
    return newStudent; // return variabel pointer yg menunjuk ke address newStudent
}

// Read
void read(Student *s) { // pass pointer yang menunjuk ke alamat student
    printf("Name: %s\n", s->name); // (*s).name
    printf("GPA: %lf\n", s->GPA); // (*s).GPA
    printf("Course ID: %s\n", s->c.ID); // (*s).c.ID
    printf("Nama Dosen: %s\n", s->c.namaDosen); // (*s).c.namaDosen
}

// Update
void update(Student *s) {
    strcpy(s->name, "Tanto");
}

// Pointer -> Objectnya
// Kalau ga pake pointer -> Valuenya

// Delete
void remove(Student *s) {
    free(s); // free allocated memory from malloc
    s = NULL; // protect against dangling pointer
}
int main() {
    // Student s = {"Dodi", 3.90, {"COMP6047", "Pak Indra"}};
    // printf("%s ", s.name);
    // printf("%s\n", s.c.namaDosen);

    // char name[] = "Andrew";
    // char ID[] = "COMP6047";
    // char namaDosen[] = "Pak Indra";
    // create(name, 3.90, ID, namaDosen);

    Student *s = create("Joselyn", 3.9, "COMP6047", "Pak Indra");
    read(s);
    update(s);
    // remove(s);
    read(s); // undefined behavior
    // garbage collector (X)
    // garbage collector -> Java, Python

    return 0;
}