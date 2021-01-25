
struct quiz{
    char *state;
    char *capital;
};


void parseCSVStruct(struct quiz [],unsigned,const char *);
void multipleChoice(struct quiz [],unsigned);
void typeAnswer(struct quiz [],unsigned);
int findIn(int ,int []);
unsigned countFileLines(const char *);
char * chooseQuiz(void);
char * getConfig(void);



//defining a structure that has string for the state and capital so they are stored together


#define FILENAME "data/state.txt"

