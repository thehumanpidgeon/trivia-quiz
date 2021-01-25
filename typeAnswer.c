#include "quiz.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void typeAnswer(struct quiz quizData[],unsigned fileLength){
//declaring string for user to store answer in
    char answer[50],choice = 'y';
    int containing[49],current = 0;
    while (choice != 'n' && current < fileLength - 1){
        //detrmines the question asked and it has not been asked before
        int right = rand() % fileLength;
        while (findIn(right,containing))
            right = rand() % fileLength;

        //collect user input from question posed form right
        scanf("%c");
        printf("What is the state capital of %s\n",quizData[right].state);
        fgets(answer,50,stdin);
        
        //compare user input and question answer
        if (!(strcmp(answer,quizData[right].capital))){
            printf("That is correct\n");
            containing[current] = right;
            current += 1;
        }
        else
            printf("That is incorrect.\nThe correct answer is %s\n",quizData[right].capital);
            printf("Do you want to continue (y/n)?\n");
            scanf("%c",&choice);
    }
    if (current == fileLength - 1)
        printf("Well done you have got all answers correct\n");
}
