#include <stdio.h>
#include "test_registry.h"

extern void test_numlib_matf_multiply(void);
extern void test_numlib_matf_identity(void);
extern void test_numlib_matf2x2_identity(void);
extern void test_numlib_matf2x2_mult(void);

test_entry_t tests[] = {
    REGISTER_TEST(test_numlib_matf_multiply),
    REGISTER_TEST(test_numlib_matf_identity),
    REGISTER_TEST(test_numlib_matf2x2_identity),
    REGISTER_TEST(test_numlib_matf2x2_mult)
};

int test_count = sizeof(tests) / sizeof(test_entry_t);

int main(void)
{
    for (int i = 0; i < test_count; i++)
    {
        printf("Running %s...\n", tests[i].name);
        tests[i].func();
        printf("%s passed!\n", tests[i].name);
    }
    return 0;
}