//
// Created by Sam on 12/2/2019.
//

#ifndef STUDENTMANAGEMENT3_FINDERS_H
#define STUDENTMANAGEMENT3_FINDERS_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"

void classAverage(struct Student* studentList, char* className, char* classes[], int listSize, int classCount);
void listCourses(struct Student* student);
void findFirstNames(struct Student* studentList, char* lname, int listSize);
void topStudent(struct Student* studentList, char* className, int listSize);

#endif //STUDENTMANAGEMENT3_FINDERS_H
