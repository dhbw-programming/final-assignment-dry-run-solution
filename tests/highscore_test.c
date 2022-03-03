#include "tests.h"

int highscore_entry_equal(highscore_entry a, highscore_entry b);

int highscore_entry_equal(highscore_entry a, highscore_entry b) {
    return a.points == b.points && strlen(a.name) == strlen(b.name) && strcmp(a.name, b.name) == 0;
}

void test_struct_io_task(int *failed_tests) {
    highscore_entry one   = {"one", 1};
    highscore_entry two   = {"two", 2};
    highscore_entry three = {"three", 3};

    // init highscores
    init_highscores(4);
    highscore_entry *highscores = get_highscores();
    if (highscores == NULL) {
        LOG_TEST_FAILURE("no valid pointer returned by get_highscores; aborting execution of further test cases");
        return;
    }

    // add entry with points 1
    add_highscore_entry(one.name, one.points);
    if (!highscore_entry_equal(highscores[0], one)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              one.name,
                              one.points,
                              0,
                              highscores[0].name,
                              highscores[0].points);
    }

    // add entry with points 3
    add_highscore_entry(three.name, three.points);
    if (!highscore_entry_equal(highscores[0], three)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              three.name,
                              three.points,
                              0,
                              highscores[0].name,
                              highscores[0].points);
    }
    if (!highscore_entry_equal(highscores[1], one)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              one.name,
                              one.points,
                              1,
                              highscores[1].name,
                              highscores[1].points);
    }

    // add entry with points 2
    add_highscore_entry(two.name, two.points);
    if (!highscore_entry_equal(highscores[0], three)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              three.name,
                              three.points,
                              0,
                              highscores[0].name,
                              highscores[0].points);
    }
    if (!highscore_entry_equal(highscores[1], two)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              two.name,
                              two.points,
                              1,
                              highscores[1].name,
                              highscores[1].points);
    }
    if (!highscore_entry_equal(highscores[2], one)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              one.name,
                              one.points,
                              2,
                              highscores[2].name,
                              highscores[2].points);
    }

    // add another entry with points 2
    add_highscore_entry(two.name, two.points);
    if (!highscore_entry_equal(highscores[0], three)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              three.name,
                              three.points,
                              0,
                              highscores[0].name,
                              highscores[0].points);
    }
    if (!highscore_entry_equal(highscores[1], two)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              two.name,
                              two.points,
                              1,
                              highscores[1].name,
                              highscores[1].points);
    }
    if (!highscore_entry_equal(highscores[2], two)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              two.name,
                              two.points,
                              2,
                              highscores[2].name,
                              highscores[2].points);
    }
    if (!highscore_entry_equal(highscores[3], one)) {
        LOG_TEST_FAILURE_ARGS("entry was not inserted correctly; expected %s, %d at index %d but got %s, %d",
                              one.name,
                              one.points,
                              3,
                              highscores[3].name,
                              highscores[3].points);
    }

    // write to file
    const char     *filename           = "highscores.txt";
    highscore_entry expected_entries[] = {three, two, two, one};

    write_highscores_to_file(filename);

    FILE *f = fopen(filename, "r");
    for (int i = 0; i < 4; ++i) {
        int  rank;
        char name[20];
        int  points;
        if (fscanf(f, "%d. %s scored %d points\n", &rank, name, &points) != 3) {
            LOG_TEST_FAILURE("could not parse highscores in file; aborting remaining test cases");
            break;
        }
        if (rank != i + 1) {
            LOG_TEST_FAILURE_ARGS("file entry does not have expected rank; found %d but expected %d", rank, i + 1);
        }
        highscore_entry found_entry = {name, points};
        if (!highscore_entry_equal(expected_entries[i], found_entry)) {
            LOG_TEST_FAILURE_ARGS("did not find correct entry; expected %s, %d but got %s, %d",
                                  expected_entries[i].name,
                                  expected_entries[i].points,
                                  found_entry.name,
                                  found_entry.points);
        }
    }
    fclose(f);

    free(highscores);
}
