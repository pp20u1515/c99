CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Iinc -g -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla
LFLAGS := --coverage 
OBJS := $(OBJ)main.o $(OBJ)matrix_operations.o $(OBJ)io_funcs.o
OBJU := $(OBJ)check_main.o $(OBJ)check_matrix_operations.o

.PHONY : clean unit func 

app.exe: obj $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS)

obj/main.o: $(SRC)main.c $(INC)struct.h $(INC)io_funcs.h $(INC)matrix_operations.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/matrix_operations.o: $(SRC)matrix_operations.c $(INC)matrix_operations.h $(INC)struct.h $(INC)io_funcs.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/io_funcs.o: $(SRC)io_funcs.c $(INC)io_funcs.h $(INC)matrix_operations.h $(INC)struct.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $< 

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_matrix_operations.o: $(UNIT_TESTS)check_matrix_operations.c $(INC)check_matrix_operations.h
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck #-lsubunit -lm -g

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
