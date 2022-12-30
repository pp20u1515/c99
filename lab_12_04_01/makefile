CC := gcc
PACK := ar rcs
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc -D ARR_EXPORTS
LFLAGS := --coverage 
OBJS := $(OBJ)main.o $(OBJ)additional_funcs.o
OBJU := $(OBJ)check_main.o $(OBJ)check_mysort.o $(OBJ)check_key.o

.PHONY : clean unit func load_static

app.exe: obj app.dll $(OBJ)main.o
	$(CC) $(CFLAGS) $(OBJ)main.o -L. -lapp -o $@ 

app.dll: $(OBJ)additional_funcs.o
	$(CC) -shared $(OBJ)additional_funcs.o -Wl,--subsystem,windows -o app.dll

obj/main.o: $(SRC)main.c $(INC)additional_funcs.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/additional_funcs.o: $(SRC)additional_funcs.c $(INC)additional_funcs.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_mysort.o: $(UNIT_TESTS)check_mysort.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/check_key.o: $(UNIT_TESTS)check_key.c
	$(CC) $(CFLAGS) -o $@ -c $<

unit_tests.exe: obj $(OBJU)
	$(CC) -o $@ $(OBJU) -lcheck #-lsubunit -lm -lpthread

unit: unit_tests.exe
	./unit_tests.exe

load_static.exe: obj static_app.a $(OBJ)main.o
	$(CC) $(OBJ)main.o -L. static_app.a -o load_static.exe 

static_app.a: $(OBJ)additional_funcs.o
	$(PACK) $@ $+
	ranlib $@

load_static: load_static.exe

obj:
	mkdir -p obj

func:
	cd $(FUNC_TESTS) && bash ./all_scripts.sh

clean :
	rm -rf .vscode
	rm *.exe 
	rm -fr obj/
	rm *.dll
	rm *.txt
	rm *.a