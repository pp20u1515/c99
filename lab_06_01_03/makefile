CC := gcc
OBJ := ./obj/
INC := ./inc/
SRC := ./src/
FUNC_TESTS := ./func_tests/scripts/
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wsign-conversion -Wfloat-conversion -Wredundant-decls
LFLAGS := --coverage

.PHONY : cleaner release

#release: CFLAGS += -o2
release: app.exe

SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ)%.o, $(SRCS))

app.exe: $(OBJS)
	$(CC) $^ -o $@

$(OBJ)%.o : $(SRC)%.c
	mkdir -p obj && cd obj && $(CC) $(CFLAGS) -c ../$<

cleaner : 
	rm *.exe
	rm -fr .vscode
