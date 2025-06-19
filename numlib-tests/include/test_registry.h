#pragma once

typedef void (*test_func_t)(void);

typedef struct
{
    const char* name;
    test_func_t func;
} test_entry_t;

#define REGISTER_TEST(fn) { #fn, fn }

extern test_entry_t tests[];
extern int test_count;