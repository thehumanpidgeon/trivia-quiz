#include "quiz.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char * chooseQuiz(void){
    unsigned short choice = 0,temp;
    //Get the file location of the cuurent users config directory
    char *configLocation = getConfig();
    //allocate enough space for the quiz index file path
    char *indexLocation = malloc(strlen(configLocation) + 10);
    //create the file path to the index file
    strcpy(indexLocation,configLocation);
    strcat(indexLocation,"/index.txt");

    //find the length of the index file
    unsigned length = countFileLines(indexLocation);

    //allocate enogh space for the data in the index file
    struct quiz *options = malloc(16 * length);

    /*put data from index file into struct to hold it
    state:      name presented to user
    capital:    file name includng anyextensions*/
    parseCSVStruct(options,length,indexLocation);

    //free memory used to store index file location
    free(indexLocation);



    //collect user input for the choice of the the quiz they wish to take
    while(!(1 <= choice && choice <= (length + 1))){
        //Directing user input and providing list of all option availible
        printf("Please select the number of the quiz you wish to select\n");
        for(int i = 1;i < (length + 1);++i)
            printf("%d)\t%s\n",i,options[i - 1].state);

    
        //loops until input in suitable range
        fscanf(stdin,"%u",&choice);
        while((temp=getchar()) != EOF && temp != '\n')
		    printf("Invalid input... please enter a number: \n");

    }
    //Reduce choice by one so that the choice made the user matches up with the index of the array
    choice -= 1;
    //allocate memory for file that the user has chosen to access
    char *fileChoice = malloc(strlen(options[choice].capital) + strlen(configLocation) + 1);
    //create file location for file that contains the data for the quiz that the user has selected
    strcpy(fileChoice,configLocation);
    strcat(fileChoice,"/");
    strncat(fileChoice,options[choice].capital,strlen(options[choice].capital) - 1);

    //release unused memory
    free(options);
    free(configLocation);

    //reurn the pointer to the file location of the quiz the user has chosen
    return fileChoice;
}