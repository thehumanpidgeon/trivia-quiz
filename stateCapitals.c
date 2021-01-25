#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quiz.h"


//defining a structure that has string for the state and capital so they are stored togethe


int main(void){
    char *quizSelected = chooseQuiz();


    //define array of structures to store all the states data
    //dynamically allocate memory depending on size of file being ingested
    unsigned fileLength = countFileLines(quizSelected);
    struct quiz *states = malloc(fileLength * 16);
    if (states == NULL){
        printf("Not enough memory");
        return 1;
    }
    //tenp stores line input from file; choice and answer are used for input
    char *choice = malloc(3);
    int i;
    //an unsigned int is required to get more random numbers
    unsigned seed;
    parseCSVStruct(states,fileLength,quizSelected);
    //Getting seed to make rand more random
    printf("Please enter a seed number:\n");
    fscanf(stdin,"%u",&seed);

    //Asking the user for input about how the quiz works
    printf("Multiple choice or type in (m/t)?\n");
    //Flush stdin of \n
    while (*choice != 'm' && *choice != 't')
        fscanf(stdin,"%c",choice);
    //uses seed to make rand() more random
    srand(seed);
    if (*choice == 'm')
        multipleChoice(states,fileLength);
    else if (*choice == 't')
        typeAnswer(states,fileLength);
    free(choice);
    free(states);
    return 0;
}

