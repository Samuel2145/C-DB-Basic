//
// Created by Sam on 12/2/2019.
//

#include "Finders.h"

void classAverage(struct Student* studentList, char* className, char* classes[], int listSize, int classCount){
    int exists = 0;
    for(unsigned k = 0; k < classCount;k++){
        if(strcmp(classes[k], className) == 0){
            exists = 1;
            break;
        }
    }

    if(exists == 0){
        printf("Class does not exist!\n");
        return;
    }

    double ave = 0.00;
    int students = 0;
    for(unsigned i = 0; i < listSize; i++){
        for(unsigned k = 0; k < 25; k++){
            if(studentList[i].classes[k] != NULL){
                if(strcmp(className, studentList[i].classes[k]) == 0 && studentList[i].grades[k] >= 0){
                    ave += studentList[i].grades[k];
                    students++;
                    break;
                }
            }
        }
    }
    if(students == 0){
        printf("Nobody is enrolled or graded in this class!\n %d\n", 0);
        return;
    }
    ave = ave/students;
    printf("The average for %s is: %.2lf\n", className, ave);
}

void listCourses(struct Student* student){
    if(student == NULL){
        printf("This student does not exist!\n");
        return;
    }

    int classCount = 0;
    for(unsigned i = 0; i < 25;i++){
        if(student->classes[i] != NULL){
            classCount++;
        }
    }

    if(classCount == 0){
        printf("This student is not currently enrolled in any classes!\n");
        return;
    }

    printf("%s %s has the following classes: ", student->fname, student->lname);
    for(unsigned k = 0; k < 25; k++){
        if(student->classes[k] != NULL){
            if(classCount == 1){
                printf("%s\n", student->classes[k]);
            }else{
                printf("%s, ", student->classes[k]);
                classCount--;
            }
        }
    }
}

void findFirstNames(struct Student* studentList, char* lname, int listSize){
    int timesFound = 0;
    for(unsigned k = 0; k < listSize; k++){
        if(strcmp(studentList[k].lname, lname) == 0){
            timesFound++;
        }
    }

    if(timesFound == 0){
        printf("There is no such student with that last name!\n");
        return;
    }

    for(unsigned i = 0; i < listSize; i++){
        if(strcmp(studentList[i].lname, lname) == 0){
            if(timesFound == 1){
                printf("%s", studentList[i].fname);
            }else{
                printf("%s, ", studentList[i].fname);
                timesFound--;
            }
        }
    }
    printf("\n");
}

void topStudent(struct Student* studentList, char* className, int listSize){
    double highestGrade = 0.00;
    int studentCount = 0;
    char* students[25];
///Attempt to Simplify using a double array for grades
    for(unsigned i = 0; i < listSize; i++){
        for(unsigned k = 0; k < 25; k++){
            if(studentList[i].classes[k] != NULL){
                if(strcmp(className, studentList[i].classes[k]) == 0){
                    if(studentList[i].grades[k] > highestGrade || studentList[i].grades[k] == highestGrade){
                        highestGrade = studentList[i].grades[k];
                        break;
                    }
                }
            }
        }
    }

    for(unsigned i = 0; i < listSize; i++){
        for(unsigned k = 0; k < 25; k++){
            if(studentList[i].classes[k] != NULL){
                if(strcmp(className, studentList[i].classes[k]) == 0){
                    if(studentList[i].grades[k] > highestGrade || studentList[i].grades[k] == highestGrade){
                        studentCount++;
                        students[studentCount - 1] = studentList[i].fullName;
                        break;
                    }
                }
            }
        }
    }

    if(studentCount == 0){
        printf("No one has been graded in this course!\n");
        return;
    }

    int j = 0;
    printf("The top student(s) in %s is: ", className);
    while(students[j] != NULL){
        if(studentCount == 1){
            printf("%s\n", students[j]);
            return;
        }else{
            printf("%s, ", students[j]);
            studentCount--;
            j++;
        }
    }
}