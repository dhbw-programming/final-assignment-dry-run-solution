#include "tests.h"

int main(int argc, const char *argv[]) {
    int failed_tests = 0;

    test_string_task(&failed_tests);
    test_struct_io_task(&failed_tests);

    dhbw_print_integer("number of failed tests", failed_tests);
    return 0;
}
