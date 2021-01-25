# trivia-quiz
## Purpose
The purpose of this program is a comand line program that allows someone to be tested on a subject of their choice through loading data from a comma seperated variable file.

## Usage
All the data files need to be located in the .config directory of the user who wants to use the program.
Data should be stored in a text file with each line a different question. The prompt should be the first item of data in the line and the answer should be the second.
Also located in the .config directory should be a file named index.txt. This should contain the availible data for quizes. The first item on each line should be the prompt for the user to select from and the second item contains the name of the file that should be accessed with a \n character on the end.

## Building:
```
git clone https://github.com/thehumanpidgeon/trivia-quiz.git
make clean
```
Then copy the binary to where every you want to put
