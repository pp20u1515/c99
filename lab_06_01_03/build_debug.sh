#!bin/bash

gcc -std=c99 main.c -Wall -Werror -Wpedantic -Wextra -g3 --coverage -o app.exe
