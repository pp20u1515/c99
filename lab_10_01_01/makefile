CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -g -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc
LFLAGS := --coverage 
OBJS := $(OBJ)main.o $(OBJ)list_func.o $(OBJ)io_funcs.o
OBJU := $(OBJ)check_main.o $(OBJ)check_funcs.o

.PHONY : clean unit func 

app.exe: obj $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS)

obj/main.o: $(SRC)main.c $(INC)struct.h $(INC)io_funcs.h $(INC)list_func.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/list_func.o: $(SRC)list_funcs.c $(INC)list_func.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/io_funcs.o: $(SRC)io_funcs.c $(INC)io_funcs.h $(INC)list_func.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $< 

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

obj/check_funcs.o: $(UNIT_TESTS)check_funcs.c $(INC)check_funcs.h
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

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
