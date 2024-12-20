#include <stdio.h>
#include <stddef.h>

int main(int argc, char **argv) {
    char ch = 'a';
    printf("%c\n", ch);

    char *st = "hello";
    printf("%s\n", st);

    int in = 9;
    printf("%i\n", in);

    long ma = 9;
    printf("%l\n", ma);

    double dou = 9;
    printf("%d\n", dou);

    float bu = 9.99;
    printf("%f\n", bu);

    size_t sz = sizeof("hello");
    printf("%d\n", sz);

    unsigned int ui; // This works for all numbers.
    printf("%d\n", ui);

    return 0;
}
