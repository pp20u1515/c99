CC := gcc
INC := inc/
SRC := src/
OBJ := obj/
UNIT_TESTS := unit_tests/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=gnu99 -g -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla -Iinc
LFLAGS := --coverage 
OBJS := $(OBJ)main.o $(OBJ)additional_funcs.o $(OBJ)arr_product.o $(OBJ)product.o
OBJU := $(OBJ)check_main.o $(OBJ)check_additional_funcs.o

.PHONY : clean unit func 

app.exe: obj $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS)

obj/main.o: $(SRC)main.c $(INC)additional_funcs.h $(INC)arr_product.h $(INC)product.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/additional_funcs.o: $(SRC)additional_funcs.c $(INC)additional_funcs.h $(INC)return_codes.h $(INC)product.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/arr_product.o: $(SRC)arr_product.c $(INC)arr_product.h $(INC)return_codes.h $(INC)product.h $(INC)additional_funcs.h
	$(CC) $(CFLAGS) -o $@ -c $< 

obj/product.o: $(SRC)product.c $(INC)product.h $(INC)return_codes.h
	$(CC) $(CFLAGS) -o $@ -c $< 

obj/check_main.o: $(UNIT_TESTS)check_main.c
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

obj/check_additional_funcs.o: $(UNIT_TESTS)check_additional_funcs.c
	$(CC) $(CFLAGS) -Isrc -o $@ -c $<

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
