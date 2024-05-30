#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char street[100];
    char city[50];
    char state[50];
    int zipCode;
} Address;

typedef struct {
    char name[50];
    int age;
} Professor;

typedef struct {
    char name[50];
    int creditHours;
} Course;

typedef struct {
    char name[50];
    int age;
    Address address;
    Course courses[5];
    int numCourses;
} Student;

typedef struct {
    char name[50];
    Professor professors[3];
    int numProfessors;
} Department;

typedef struct {
    char name[100];
    char location[50];
    Department departments[3];
    int numDepartments;
} University;

int main() {
    Student student;

    strcpy(student.name, "John Doe");
    student.age = 20;

    strcpy(student.address.street, "123 Main St");
    strcpy(student.address.city, "New York");
    strcpy(student.address.state, "NY");
    student.address.zipCode = 10001;

    strcpy(student.courses[0].name, "Mathematics");
    student.courses[0].creditHours = 3;
    strcpy(student.courses[1].name, "Physics");
    student.courses[1].creditHours = 4;
    student.numCourses = 2;

    University university;
    strcpy(university.name, "ABC University");
    strcpy(university.location, "City XYZ");

    strcpy(university.departments[0].name, "Computer Science");
    strcpy(university.departments[0].professors[0].name, "Dr. Smith");
    university.departments[0].professors[0].age = 40;
    university.departments[0].numProfessors = 1;

    strcpy(university.departments[1].name, "Electrical Engineering");
    strcpy(university.departments[1].professors[0].name, "Dr. Johnson");
    strcpy(university.departments[1].professors[1].name, "Dr. Wilson");
    university.departments[1].professors[0].age = 45;
    university.departments[1].professors[1].age = 50;
    university.departments[1].numProfessors = 2;

    university.numDepartments = 2;

    printf("Student Information:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Address:\n");
    printf("Street: %s\n", student.address.street);
    printf("City: %s\n", student.address.city);
    printf("State: %s\n", student.address.state);
    printf("Zip Code: %d\n", student.address.zipCode);
    printf("Courses:\n");
    for (int i = 0; i < student.numCourses; i++) {
        printf("Course: %s\n", student.courses[i].name);
        printf("Credit Hours: %d\n", student.courses[i].creditHours);
    }

    printf("\nUniversity Information:\n");
    printf("Name: %s\n", university.name);
    printf("Location: %s\n", university.location);
    printf("Departments:\n");
    for (int i = 0; i < university.numDepartments; i++) {
        printf("Department: %s\n", university.departments[i].name);
        printf("Professors:\n");
	}
}

