CC := gcc
INC := ./inc/
SRC := ./src/
OBJ := ./obj/
FUNC_TESTS := ./func_tests/scripts
CFLAGS := -std=c99 #-Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wsign-conversion -Wvla 
LFLAGS := --coverage 

.PHONY : clean release program_scripts

release : app.exe

SRCS = $(wildcard $(SRC)*.c)
OBJS = $(patsubst $(SRC)%.c, $(OBJ)%.o, $(SRCS))

app.exe: $(OBJS)
	$(CC) $^ -o $@

$(OBJ)%.o : $(SRC)%.c
	mkdir -p obj && cd obj && $(CC) $(CFLAGS) -c ../$<

clean :
	rm -rf .vscode
	rm *.exe 