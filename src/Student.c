//
// Created by Sam on 12/2/2019.
//
#include "Student.h"

struct Student* getStudent(struct Student* list,char* fname, char* lname, int listSize){
    char fullName[MAX_NAME_LENGTH];
    strcpy(fullName, fname);
    strcat(fullName, " ");
    strcat(fullName, lname);
    for(unsigned i = 0; i < listSize; i++){
        if(strcmp(fullName, list[i].fullName) == 0){
            return &list[i];
        }
    }
    return NULL;
}