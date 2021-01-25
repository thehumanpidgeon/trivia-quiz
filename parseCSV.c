#include "quiz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseCSVStruct(struct quiz given[],unsigned fileLength,const char * fileName){
    //standard file opening
    char temp[100];
    FILE *f = fopen(fileName,"r");
    if (f == NULL){
        printf("The file cannot be found");
        exit(1);
    }
    //interates thorugh all the lines of the file
    for (int i = 0; i < fileLength; i++){
        //stores the current line of the file in a variable so it can be read
        fgets(temp,100,f);

        //parses first element of csv data
        char *tok = strtok(temp,",");

        //allocate the size of the string that needs to be stored
        given[i].state = malloc(strlen(tok));

        //check for correct allocation
        if (given[i].state == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }
        //copy the first csv data into the state of the current structure from the array
        strcpy(given[i].state,tok);

        //this access second part of the csv data (expression access all subsequent data of csv file)
        tok = strtok(NULL,",");

        //allocate the size of the string to store to the struct string
        given[i].capital = malloc(strlen(tok));
        //check the memory has been allocated
        if (given[i].capital == NULL){
            printf("Memory allocation has failed\n");
            exit(1);
        }
        //copy the data into the current structure
        strcpy(given[i].capital,tok);
    }
    fclose(f);
}