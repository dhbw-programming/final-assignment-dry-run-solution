all: main

main: main.c
	mkdir -p out
	gcc -std=c17 -Wall -Werror -Wextra -Wpedantic -Wconversion -Wcast-align -Wshadow -Wmissing-prototypes -Wmissing-format-attribute -Wno-unused -g -O0 -I . *.c tests/*.c tasks/*.c .assignment/*.c -o out/main

