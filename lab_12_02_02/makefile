CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc
LFLAGS := --coverage 
OBJS := $(OBJ)library.o $(OBJ)main.o
OBJU := $(OBJ)check_main.o $(OBJ)check_library.o

.PHONY : clean unit func

app.exe: obj app.so $(OBJ)main.o
	$(CC) -o $@ $(OBJ)main.o -L. app.so
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

app.so: $(OBJ)library.o
	$(CC) -o app.so -shared $(OBJ)library.o 

obj/main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/library.o: $(SRC)library.c $(INC)library.h
	$(CC) $(CFLAGS) -fPIC -o $@ -c $<

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<
	
obj/check_library.o: $(UNIT_TESTS)check_library.c $(INC)library.h
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck -lsubunit -lm -lpthread

unit: unit_tests.exe
	./unit_tests.exe

obj:
	mkdir -p obj

func:
	cd $(FUNC_TESTS) && bash ./all_scripts.sh

clean :
	rm -rf .vscode 
	rm -fr obj/
	rm *.so
	rm *.exe
