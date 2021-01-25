#include "quiz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findIn(int test,int containing[]){
    for (int i = 0; i < 50; i++)
        if (test == containing[i])
            return 1;
    return 0;
}

unsigned countFileLines(const char *fileName){
    unsigned count = 0;
    FILE *f;
    char c;
    f = fopen(fileName,"r");
    if (f == NULL){
        perror("The file doesn't exist\n");
        exit(1);
    }
    for (c = getc(f);c != EOF;c = getc(f))
        if (c == '\n')
            count += 1;
    fclose(f);
    return count;
}

char * getConfig(void){
    char *homeLocation = getenv("HOME");
    char *configLocation = malloc(strlen(homeLocation) + 13);
    strcpy(configLocation,homeLocation);
    strcat(configLocation,"/.config/quiz");
    return configLocation;
}