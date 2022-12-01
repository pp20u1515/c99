CC := gcc
OBJ := ./obj/
INC := ./inc/
SRC := ./src/
FUNC_TESTS := ./func_tests/
UNIT_TESTS := ./unit_tests/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wredundant-decls -Wvla -pedantic -lm -ls
LFLAGS := --coverage

.PHONY: clean release debug

release: CFLAGS += -o2 
release: $(OBJ)release.lastbuildstate app.exe unit_tests.exe

debug: CFLAGS += --coverage
debug: LFLAGS += -g3
debug: $(OBJ)debug.lastbuildstate app.exe unit_tests.exe

app.exe: $(OBJ)main.o $(OBJ)additional_funcs.o $(OBJ)io_funcs.o $(OBJ)list_funcs.o
	$(CC) $(LFLAGS) -o $@ $^ -lm

#unit_tests.exe: $(OBJ)check_main.o $(OBJ)check_matrix_operations.o $(OBJ)matrix_operations.o $(OBJ)matrix.o
#	$(CC) $(LFLAGS) -I$(INC) -o $@ $^ -lcheck -lm

#$(OBJ)check_%.o: $(UNIT_TESTS)check_%.c
#	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)release.lastbuildstate: | dir
	rm -rf *.exe $(OBJ)*.o $(OBJ)debug.lastbuildstate
	touch $(OBJ)release.lastbuildstate

$(OBJ)debug.lastbuildstate: | dir
	rm -rf *.exe $(OBJ)*.o $(OBJ)release.lastbuildstate
	touch $(OBJ)debug.lastbuildstate

#unit: unit_tests.exe
#	./unit_tests.exe

dir:
	mkdir -p $(OBJ)

clean :
	rm -fv *.exe
	rm -fv $(OBJ)*.o
	rm -fv $(OBJ)*.gcno
	rm -fv $(OBJ)*.gcda
	touch $(OBJ)*.lastbuildstate
