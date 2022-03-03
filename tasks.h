#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include ".assignment/dhbw.h"

/* Strings */

// return true if c is a letter, false otherwise
int is_letter(char c);

// copy letters from str to target (ignores the rest)
void string_copy_letters_only(const char *str, char *target);

/* Structs and IO */

// single entry for a highscore list
typedef struct {
    char *name;
    int points;
} highscore_entry;

// initialize list of highscores with length len
void init_highscores(unsigned int len);

// add a highscore entry with name and points to the list of highscores, at the corresponsing spot (high to low scores)
void add_highscore_entry(char *name, int points);

// return list of highscores
highscore_entry *get_highscores(void);

// write out list of highscores to a file (appropriately formatted of course)
void write_highscores_to_file(const char *filename);
