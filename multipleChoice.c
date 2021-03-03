#include "quiz.h"
#include <stdio.h>
#include <stdlib.h>

void multipleChoice(struct quiz quizData[],unsigned fileLength){
    //continues the quiz until n entered
    int right, f[3];
    char *choice = malloc(3), *answer = malloc(3), temp;
    while (*choice != 'n'){

        //getting randomlibc.so.6 numnber between 0 and 3 (determines placement of right answer)
        right = rand() % 4;
        scanf("%c");

        //geting random number between 0 and 47 for wrong anwers and question (f[0] determines queston asked and f[1-3] determine wrong answers)
        for (int i = 0; i < 4;i++)
            f[i] = rand() % fileLength;

        printf("What is the state capital is %s?\n\n",quizData[f[0]].state);

        //position right answer amongst wrong answers
        if (right == 0){
            printf("A: %s\n",quizData[f[0]].capital);
            printf("B: %s\n",quizData[f[1]].capital);
            printf("C: %s\n",quizData[f[2]].capital);
            printf("D: %s\n",quizData[f[3]].capital);
        }
        else if (right == 1){
            printf("A: %s\n",quizData[f[1]].capital);
            printf("B: %s\n",quizData[f[0]].capital);
            printf("C: %s\n",quizData[f[2]].capital);
            printf("D: %s\n",quizData[f[3]].capital);
        }
        else if (right == 2){
            printf("A: %s\n",quizData[f[2]].capital);
            printf("B: %s\n",quizData[f[1]].capital);
            printf("C: %s\n",quizData[f[0]].capital);
            printf("D: %s\n",quizData[f[3]].capital);
        }
        else if (right == 3){
            printf("A: %s\n",quizData[f[3]].capital);
            printf("B: %s\n",quizData[f[1]].capital);
            printf("C: %s\n",quizData[f[2]].capital);
            printf("D: %s\n",quizData[f[0]].capital);
        }

        //get user input for answer
        printf("Please enter an answer (A/B/C/D)\n");
        while (!(*answer > 64 && *answer < 69))
            fgets(answer,2,stdin);
             while((temp=getchar()) != EOF && temp != '\n')
		        printf("Invalid input... please enter a letter: \n");
        //compare the ascii value of answer to rand that determines right answer placement with constant to account for ascii values
        
        if ( *answer == (right + 65)){
            printf("That is correct\n");

        }
        else
            printf("That is incorrect.\nThe correct answer was %s",quizData[f[0]].capital);
        *answer = '\0';


        //get user input for continuing
        do {
            printf("Do you want to continue (y/n)?\n");
            while((temp=getchar()) != EOF && temp != '\n');
            fgets(choice,2,stdin);

        } while (*choice != 'n' && *choice != 'y');

        
    }
    free(choice);
    free(answer);
}