CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc -D ARR_EXPORTS
LFLAGS := --coverage 
OBJS := $(OBJ)library.o $(OBJ)main.o
OBJU := $(OBJ)check_main.o $(OBJ)check_mysort.o $(OBJ)check_key.o

.PHONY : clean unit func

app.exe: obj libapp.dll $(OBJ)main.o
	$(CC) $(CFLAGS) $(OBJ)main.o -L. -lapp -o $@ 

libapp.dll: $(OBJ)library.o
	$(CC) -shared $(OBJ)library.o -Wl,--subsystem,windows -o libapp.dll

obj/main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/library.o: $(SRC)library.c $(INC)library.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck #-lsubunit -lm -lpthread

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
	rm *.dll