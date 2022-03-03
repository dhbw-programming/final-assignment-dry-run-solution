#pragma once

#include "tasks.h"

#define LOG_TEST_FAILURE(msg) \
    ++*failed_tests;          \
    printf("%s:%d test failed: %s\n", __FILE__, __LINE__, msg)
#define LOG_TEST_FAILURE_ARGS(msg, ...) \
    ++*failed_tests;                    \
    printf("%s:%d test failed: " msg "\n", __FILE__, __LINE__, __VA_ARGS__)

void test_string_task(int *failed_tests);

void test_struct_io_task(int *failed_tests);
