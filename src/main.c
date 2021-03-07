#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokenizer.h"
#include "Finders.h"

void enrollStudent(struct Student* student, char* className, char* classes[], int listSize){
    if(student == NULL){
        printf("Student not Enrolled (Student does not Exist!)\n");
        return;
    }

    for(unsigned i = 0; i < listSize; i++){
        if(strcmp(classes[i], className) == 0){
            for(unsigned k = 0; k < 25; k++){
                if(student->classes[k] != NULL){
                    if(strcmp(student->classes[k], className) == 0){
                        printf("Student already enrolled in class!\n");
                        return;
                    }
                }
                if(student->classes[k] == NULL){
                    student->classCount++;
                    student->classes[k] = malloc(sizeof(className));
                    strcpy(student->classes[k], className);
                    student->grades[k] = -1.00;
                    printf("Student Enrolled!\n");
                    return;
                }


            }
        }
    }
    printf("Student not Enrolled (Class does not Exist!)\n");
}

void unenrollStudent(struct Student* student, char* className){
    if(student == NULL){
        printf("Student not Unenrolled (Student does not exist!)\n");
        return;
    }

    for(unsigned k = 0; k < 50; k++){
        if(student->classes[k] != NULL){
            if(strcmp(className, student->classes[k]) == 0){
                student->classes[k] = NULL;
                student->grades[k] = -1.00;
                printf("Student Unenrolled!\n");
                return;
            }
        }
    }
    printf("Student not Unenrolled (Student does not have class!)\n");
}

void setGrade(struct Student* student, char* className, double grade){
    if(student == NULL){
        printf("Student does not exist!\n");
        return;
    }

    for(unsigned k = 0; k < 25; k++){
        if(student->classes[k] != NULL){
            if(strcmp(className, student->classes[k]) == 0){
                student->grades[k] = grade;
                printf("Student Graded!\n");
                return;
            }
        }
    }

    printf("Student does not have class!\n");
}

void studentGPA(struct Student* student){
    if(student == NULL){
        printf("This student does not exist!\n");
        return;
    }
    int classCount = 0;
    double GPA = 0.00;
    for(unsigned i = 0; i < 25;i++){
        if(student->classes[i] != NULL && student->grades[i] >= 0){
            GPA += student->grades[i];
            classCount++;
        }
    }

    if(classCount == 0){
        printf("This student is not enrolled/graded in any classes\n");
        return;
    }
    GPA = GPA/classCount;
    printf("%s %s has the following GPA: %.2lf\n", student->fname, student->lname, GPA);
}

void countEnrollments(struct Student* studentList, char* classes[], char* className, int listSize, int classesSize){
    int exists = 0;
    for(unsigned j = 0; j < classesSize; j++){
            if(strcmp(className, classes[j]) == 0){
                exists = 1;
            }
    }

    if(exists == 0){
        printf("This class does not exist!\n");
        return;
    }

    int enrollments = 0;
    for(unsigned i = 0; i < listSize; i++){
        for(unsigned k = 0; k < 25; k++){
            if(studentList[i].classes[k] != NULL){
                if(strcmp(className, studentList[i].classes[k]) == 0){
                    enrollments++;
                    break;
                }
            }
        }
    }
    printf("The number of active enrollments for %s is: %d\n", className, enrollments);
}

void findMutual(struct Student* student, struct Student* studentList, int listSize){

}

int main() {
    char line[300];
    char *tokens[MAX_TOK];
    unsigned int N, M, tokenCount;

    printf("Number of students:");
    scanf("%d",&N);
    getchar();  //Added in to prevent error in which subsequent calls of fgets() produce undesired side effects due to a newline character being read
    printf("Number of classes:");
    scanf("%d", &M);
    getchar();

    struct Student* studentList = calloc(N, sizeof(struct Student));
    char* classes[M];

    for(unsigned i = 0; i < N; i++){
        printf("Name of student %d:\n", i+1);
        fgets(line,300,stdin);
        to_lowercase(line);
        trim_whitespaces_and_extra_spaces(line);
        strcpy(studentList[i].fullName, line);
        sscanf(line, "%s %s", studentList[i].fname, studentList[i].lname);
    }

    for(unsigned i = 0; i < M; i++){
        printf("Name of class %d:\n", i+1);
        fgets(line,300,stdin);
        to_lowercase(line);
        trim_whitespaces_and_extra_spaces(line);
        classes[i] = malloc(sizeof(line));
        strcpy(classes[i], line);
    }

    ///Enroll, Unenroll, Grading, Average, FindFirstNames, ListCourses, GPA, Count, topStudent all work
    ///Still need findMutual
    while(printf("Query:"), fgets(line, 300, stdin)){
        to_lowercase(line);
        trim_whitespaces_and_extra_spaces(line);
        tokenCount = tokenize_input_line(line, tokens);

        for(unsigned i = 0; i < tokenCount; i++){
            trim_whitespaces_and_extra_spaces(tokens[i]);
        }

        if(tokenCount == 0){
            break;
        }

        if(strcmp(tokens[0], "enroll") == 0){
            enrollStudent(getStudent(studentList,tokens[1], tokens[2], N), tokens[3], classes, M);
        }else if(strcmp(tokens[0], "unenroll") == 0){
            unenrollStudent(getStudent(studentList,tokens[1], tokens[2], N), tokens[3]);
        }else if(strcmp(tokens[0], "grade") == 0){
            double x = atof(tokens[4]);
            setGrade(getStudent(studentList,tokens[1], tokens[2], N), tokens[3], x);
        }else if(strcmp(tokens[0], "ave") == 0){
            classAverage(studentList, tokens[1], classes, N, M);
        }else if(strcmp(tokens[0], "gpa") == 0){
            studentGPA(getStudent(studentList,tokens[1], tokens[2], N));
        }else if(strcmp(tokens[0], "count") == 0){
            countEnrollments(studentList, classes, tokens[1], N, M);
        }else if(strcmp(tokens[0], "topstudent") == 0){
            topStudent(studentList,tokens[1], N);
        }else if(strcmp(tokens[0], "findmutual") == 0){
            //findMutual(getStudent(studentList,tokens[1], tokens[2], N), studentList, N);
        }else if(strcmp(tokens[0], "listcourses") == 0){
            listCourses(getStudent(studentList, tokens[1],tokens[2], N));
        }else if(strcmp(tokens[0], "findfirstnames") == 0){
            findFirstNames(studentList, tokens[1], N);
        }else{
            continue;
        }
    }
    return 0;
}