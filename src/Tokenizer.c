//
// Created by Sam on 12/2/2019.
//

#include "Tokenizer.h"

void trim_whitespaces_and_extra_spaces(char *str) {
    if (!str)
        return;

    int write_loc = 0;
    int i = 0;

    while (str[i] != '\0' && isspace(str[i]))
        i++;

    int last_was_space = 0;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            if (last_was_space == 1)  //when we switch from space to non-space we add one space
                str[write_loc++] = ' ';
            str[write_loc++] = str[i];
            last_was_space = 0;
        } else
            last_was_space = 1;

        i++;
    }
    str[write_loc] = '\0';
}

unsigned int tokenize_input_line(char *line, char *tokens[]) {
    unsigned int tokenCount = 0;
    char* token = strtok(line, " ");
    tokens[0] = token;
    char* temp[100];
    int k = 0;

    if(strcmp(token, "enroll") == 0){
        tokenCount = 4;
    }else if(strcmp(token, "unenroll") == 0){
        tokenCount = 4;
    }else if(strcmp(token, "grade") == 0){
        while(token != NULL){
            temp[k] = token;
            k++;
            token = strtok(NULL," ");
            tokenCount++;
        }
        if(tokenCount > 5){
            char work[100] = "";
            tokens[0] = temp[0];
            tokens[1] = temp[1];
            tokens[2] = temp[2];
            strcpy(work, temp[3]);
            for(unsigned j = 4; j < (k-1);j++){
                strcat(work, " ");
                strcat(work, temp[j]);
            }
            tokens[3] = work;
            tokens[4] = temp[k-1];
        }
        tokenCount = 5;
        return tokenCount;
    }else if(strcmp(token, "ave") == 0){
        tokenCount = 2;
    }else if(strcmp(token, "gpa") == 0){
        tokenCount = 3;
    }else if(strcmp(token, "count") == 0){
        tokenCount = 2;
    }else if(strcmp(token, "topstudent") == 0){
        tokenCount = 2;
    }else if(strcmp(token, "findmutual") == 0){
        tokenCount = 3;
    }else if(strcmp(token, "listcourses") == 0){
        tokenCount = 3;
    }else if(strcmp(token, "findfirstnames") == 0){
        tokenCount = 2;
    }else if(strcmp(token, "quit") == 0){
        tokenCount = 0;
    }

    for(unsigned i = 1; i < tokenCount; i++){
        if(i != (tokenCount-1)){
            token = strtok(NULL, " ");
            tokens[i] = token;
        }else if(i == (tokenCount-1)){
            token = strtok(NULL, "\0");
            tokens[i] = token;
        }
    }
    return tokenCount;
}

void to_lowercase(char *line){
    int i = 0;
    while(line[i] != '\0'){
        if( line[i]>=65 &&line[i] <= 90) line[i]+=32;
        i++;
    }
}