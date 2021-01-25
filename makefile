CC=gcc
CFLAGS=-I.
DEPS = quiz.h
OBJ = stateCapitals.o general.o parseCSV.o multipleChoice.o typeAnswer.o choose.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

quizTest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

._PHONY: clean

clean:
	rm -fv *.o 