# final-assignment-dry-run

This is the dry run of the final coding assignment. The assignemnt is structured around its two central tasks.

1. strings
2. structs and IO

## Repo structure

The repo consists of tasks, tests and the `main.c`.

### Tasks

The tasks is the part of the code you should work on. `tasks.h` contains all function declarations
to be used for the task completion. To make the project build you should start with 2.1. After that the tasks can be
done in any order.

Under the `tasks/` folder there are two files corresponding to the individual tasks:

- strings : `strings.c`
- structs and IO: `highscore.c`

The tasks will the elaborated on further down.

### Tests

The `tests.h` file and `tests/` folder contains the test cases that will be executed when you run the program. They
will help you verify that your program is behaving correctly. Initially there will be a lot of test failures,
which will be resolved as you solve the individual tasks. Each test failure logs the specific line in the test file so
you could check what the test is doing. But this should be a last resort.

## 1. Strings

These tasks revolve around strings and should be implemented in `tasks/strings.c`.

### 1.1 Is a letter?

Write an implementation for the `is_letter` function. It should return 1 if the provided character is a letter (a-z or A-Z).
0 should be returned otherwise.

### 1.2 Copy only letters

Write an implementation for the `string_copy_chars_only` function. It should copy the contents of `str` to `target`.
However, anything that is not a letter (see 1.1) should be left out. Meaning `"Hello? You okay??"` as `str` should
populate `target` with `"HelloYouokay"`. Don't forget to properly terminate the target string.

Sidenote: `target` already points to an allocated block of memory so no need to allocate here.

## 2. Structs and IO

These tasks revolve around structs and IO and should be implemented in `tasks/highscore.c`. You will see why.

### 2.1 Create highscore entry struct

Add a `typedef` to `tasks.h` named `highscore_entry`. It should be a `struct` which contains two members in this order:

- name: char*
- points: int

### 2.2 Initialize high score list

Write an implementation for the `init_highscores` function. It should allocate enough space to store `len` number
of `highscore_entry`s, and store a pointer to the allocated space for later.

### 2.3 Add a highscore entry

Write an implementation for the `add_highscore_entry` function. It should create a new `highscore_entry` from its
parameters and add it to the array created in 2.2. However, it should not just append the new entry. Instead it
should be inserted in the correct space so that the entries in the array remain sorted from highest points to lowest.

### 2.4 Get the highscore array

Write an implementation for the `get_highscores` function. It should return the pointer to the memory block allocated
in 2.2.

### 2.5 Write highscores to file

Write an implementation for the `write_highscores_to_file` function. It is supposed to write the added highscores
to a file with the name `filename`. The file's contents should resemble the format of a leaderboard. Thus each line
should only contain one entry formatted like this `"<rank>. <name> scored <points> points"`. The rank should start
with 1, the next entry has rank 2 and so on. An example output could look like this:

```
1. first scored 250 points
2. second scored 225 points
3. john scored 200 points
```

