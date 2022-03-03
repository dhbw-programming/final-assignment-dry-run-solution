#include "tasks.h"

typedef struct {
    highscore_entry *list;
    unsigned int     max_length;
    unsigned int     cur_length;
} leaderboard;

leaderboard state;

void init_highscores(unsigned int len) {
    state.list       = malloc(len * sizeof(highscore_entry));
    state.max_length = len;
    state.cur_length = 0;
}

void add_highscore_entry(char *name, int points) {
    if (state.cur_length >= state.max_length) {
        return;
    }
    unsigned int insert_at = 0;
    for (unsigned int i = 0; i < state.cur_length; ++i) {
        if (state.list[i].points > points)
            ++insert_at;
    }
    for (unsigned int i = state.cur_length; i > insert_at; --i) {
        state.list[i] = state.list[i - 1];
    }
    state.list[insert_at].name   = name;
    state.list[insert_at].points = points;
    ++state.cur_length;
}

highscore_entry *get_highscores(void) { return state.list; }

void write_highscores_to_file(const char *filename) {
  FILE *f = fopen(filename, "w");
  for (unsigned int i = 0; i < state.cur_length; ++i) {
    fprintf(f, "%d. %s scored %d points\n", i + 1, state.list[i].name,
            state.list[i].points);
  }
  fclose(f);
}
