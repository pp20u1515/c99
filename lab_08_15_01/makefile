CC := gcc
INC := ./inc/
SRC := ./src/
FUNC_TESTS := ./func_tests/scripts/
OBJ := ./obj/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsing-conversion -Wvla
LFLAGS := --coverage

.PHONY: clean realease program_scripts

realease: app.exe

SRCS = $(wildcard $(SRC)*.c)
OBJS = $(wildcard $(SRC)%.c, $(OBJ)%.o, $(SRCS))

app.exe: $(OBJS)
	$(CC) $^ -o $@

$(OBJ)%.o: $(SRC)%.c
	mkdir -p obj && cd obj && $(CC) $(CFLAGS) -c ../$<

clean:
	rm -rf .vscode
	rm *.exe