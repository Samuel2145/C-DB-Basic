//
// Created by Sam on 12/2/2019.
//



#ifndef STUDENTMANAGEMENT3_STUDENT_H
#define STUDENTMANAGEMENT3_STUDENT_H

#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_TOK 5

struct Student{
    char fname [MAX_NAME_LENGTH];
    char lname [MAX_NAME_LENGTH];
    char fullName[MAX_NAME_LENGTH];
    int classCount;
    double grades[100];
    char* classes[100];
};

struct Student* getStudent(struct Student* list,char* fname, char* lname, int listSize);


#endif //STUDENTMANAGEMENT3_STUDENT_H
