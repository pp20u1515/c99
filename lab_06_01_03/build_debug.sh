#!/bin/bash

gcc -std=c99 main.c additional_funcs.c io_funcs.c -Wall -Werror -Wpedantic -Wextra -g3 --coverage -o app.exe
