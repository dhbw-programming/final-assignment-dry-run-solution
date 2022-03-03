#include "tasks.h"

int is_letter(char c) {
    return (c > 64 && c < 91) || (c > 96 && c < 123);
}

void string_copy_letters_only(const char *str, char *target) {
  unsigned int j = 0;
  for (unsigned int i = 0; str[i] != '\0'; ++i) {
    if (is_letter(str[i])) {
      target[j++] = str[i];
    }
  }
  target[j] = '\0';
}
