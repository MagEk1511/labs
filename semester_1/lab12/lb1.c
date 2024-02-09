#include <stdio.h>
#include <string.h>

#define MAX_LEN 60

struct student {
    char surname[15];
    char name[15];
    int grade;
    int math;
    int phys;
    int inf;
};

int badStudentsC = 0;

struct student getStudent() {
    struct student student;

    scanf("%s %s %d %d %d %d", student.surname, student.name,
          &student.grade, &student.math, &student.phys, &student.inf);

    return student;
}

void makeAllStudentsArr(struct student* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = getStudent();
    }
}

int averageMark(struct student student) {
    return (student.inf + student.math + student.phys) / 3;
}

struct student findWorst2GradeStudent(struct student* arr, int size, struct student* badStudentsArr) {
    int min = averageMark(arr[0]);
    struct student worstStudent = arr[0];
    for (int i = 1; i < size; ++i) {
        struct student currStudent = arr[i];
        if (averageMark(currStudent) <= min && currStudent.grade == 2) {
            min = averageMark(currStudent);
            if (averageMark(currStudent) == min && currStudent.grade == 2) {
                badStudentsArr[badStudentsC++] = currStudent;
            }
            worstStudent = currStudent;
        }
    }

    return worstStudent;
}

void printWorseStudent(struct student* badStudents, struct student* arr, int size) {
    for (int i = 0; i < size; ++i) {
        int fl = 1;
        struct student currStudent = arr[i];
            for (int j = 0; j < badStudentsC; ++j) {
                struct student currBadStudent = badStudents[j];
                if (strcmp(currStudent.name, currBadStudent.name) == 0 && strcmp(currStudent.surname, currBadStudent.surname) == 0) {
                    fl = 0;
                }
            }
            if (fl) {
                if (averageMark(badStudents[0]) >= averageMark(currStudent)) {
                    printf("%s %s\n", currStudent.surname, currStudent.name);
            }
        }
    }
}

void printStudent(struct student currStudent) {
    printf("%-15s%-15s%5d%5d%5d%5d\n", currStudent.surname, currStudent.name,
           currStudent.grade, currStudent.math, currStudent.phys, currStudent.inf);
}

void printAllStudents(struct student* arr, int size) {
    for (int i = 0; i < size; ++i) {
        struct student currStudent = arr[i];
        printStudent(currStudent);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    struct student arr[size];
    struct student badStudentsArr[size];
    makeAllStudentsArr(arr, size);
    printAllStudents(arr, size);
    printf("\n");


    findWorst2GradeStudent(arr, size, badStudentsArr);
    for (int i = 0; i < badStudentsC; ++i) {
        printf("%s %s\n", badStudentsArr[i].surname, badStudentsArr[i].name);
    }
    printf("\n");

    printWorseStudent(badStudentsArr, arr, size);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct Student {
        char last_name[16];
        char first_name[16];
        int course;
        int math;
        int physics;
        int informatics;
    };

    int n; scanf("%d", &n);
    struct Student students[n];

    for (int i = 0; i < n; ++i) scanf("%s %s %d %d %d %d", &students[i].last_name, &students[i].first_name, &students[i].course, &students[i].math, &students[i].physics, &students[i].informatics);

    for (int i = 0; i < n; ++i) printf("%-15s%-15s%5d%5d%5d%5d\n", students[i].last_name, students[i].first_name, students[i].course, students[i].math, students[i].physics, students[i].informatics);

    printf("\n");
    int min_points = 301, points;
    for (int i = 0; i < n; ++i) {
        if (students[i].course == 2) {
            points = students[i].math + students[i].physics + students[i].informatics;
            if (points < min_points) min_points = points;
        }
    }
    for (int i = 0; i < n; i++){
        points = students[i].math + students[i].physics + students[i].informatics;
        if (min_points == points && students[i].course == 2) printf("%s %s\n", students[i].last_name, students[i].first_name);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        points = students[i].math + students[i].physics + students[i].informatics;
        if (points < min_points) printf("%s %s\n", students[i].last_name, students[i].first_name);
    }

    return 0;
}
