#include "tests.h"

void test_string_task(int *failed_tests) {
    /* string_copy_chars_only tests */

    const char   s[]   = "Wow, this is so crazy! Can you believe it?!";
    unsigned long int s_len = strlen(s);

    char *target  = malloc(sizeof(char) * (s_len + 1));
    target[s_len] = '\0';

    const char exp[] = "WowthisissocrazyCanyoubelieveit";

    string_copy_letters_only(s, target);
    if (strlen(target) != strlen(exp) || strcmp(target, exp) != 0) {
        LOG_TEST_FAILURE_ARGS("letters were not copied correctly; expected: \"%s\" but got \"%s\"", exp, target);
    }
    free(target);

    /* is_letter tests */
    for (char c = 'A'; c <= 'z'; ++c) {
        if (!is_letter(c)) {
            LOG_TEST_FAILURE_ARGS("character %c is supposed to be a letter", c);
        }
        if (c == 'Z') {
            c = 'a';
        }
    }
    if (is_letter(' ')) {
        LOG_TEST_FAILURE("space should not be a letter");
    }
    if (is_letter('!')) {
        LOG_TEST_FAILURE("'!' should not be a letter");
    }
    if (is_letter('?')) {
        LOG_TEST_FAILURE("'?' should not be a letter");
    }
}
