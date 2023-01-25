CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc
LFLAGS := --coverage 
OBJS := $(OBJ)main.o $(OBJ)additional_funcs.o $(OBJ)io_funcs.o
OBJU := $(OBJ)check_main.o $(OBJ)check_mysort.o $(OBJ)check_key.o

.PHONY : clean unit func 

app.exe: obj $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS)

obj/main.o: $(SRC)main.c $(INC)additional_funcs.h $(INC)io_funcs.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/additional_funcs.o: $(SRC)additional_funcs.c $(INC)additional_funcs.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/io_funcs.o: $(SRC)io_funcs.c $(INC)io_funcs.h $(INC)return_codes.h $(INC)io_funcs.h
	$(CC) $(CFLAGS) -o $@ -c $< 

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_mysort.o: $(UNIT_TESTS)check_mysort.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_key.o: $(UNIT_TESTS)check_key.c
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck #-lsubunit -lm

unit: unit_tests.exe
	./unit_tests.exe

obj:
	mkdir -p obj

func:
	cd $(FUNC_TESTS) && bash ./all_scripts.sh

clean :
	rm -rf .vscode
	rm *.exe 
	rm -fr obj/
