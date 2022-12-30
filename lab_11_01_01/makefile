CC := gcc
INC := ./inc/
OBJ := ./obj/
SRC := ./src/
UNIT_TESTS := ./unit_tests/
LFLAGS := --coverage
CFLAGS := -std=c99 -Iinc -g -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla
OBJS := $(OBJ)main.o $(OBJ)my_snprintf.o
OBJU := $(OBJ)check_main.o $(OBJ)check_mysnprintf.o

.PHONY: clean unit

app.exe: obj $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS)

obj/main.o: $(SRC)main.c $(INC)my_snprintf.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/my_snprintf.o: $(SRC)my_snprintf.c $(INC)my_snprintf.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_main.o: $(UNIT_TESTS)check_main.c $(INC)check_mysnprintf.h
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

obj/check_mysnprintf.o: $(UNIT_TESTS)check_mysnprintf.c $(INC)check_mysnprintf.h
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck #-lsubunit -lm -g

unit: unit_tests.exe
	./unit_tests.exe

obj:
	mkdir -p obj

clean:
	rm -fr *.exe
	rm -fr obj/
