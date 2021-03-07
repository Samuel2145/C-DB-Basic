//
// Created by Sam on 12/2/2019.
//

#ifndef STUDENTMANAGEMENT3_TOKENIZER_H
#define STUDENTMANAGEMENT3_TOKENIZER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim_whitespaces_and_extra_spaces(char *str);
unsigned int tokenize_input_line(char *line, char *tokens[]);
void to_lowercase(char *line);

#endif //STUDENTMANAGEMENT3_TOKENIZER_H
