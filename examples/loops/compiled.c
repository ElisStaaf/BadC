#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    int j = 0;
    while (++j < 10) {
        printf("%d\n", j);
    }

    int k = 0;
    do {
        printf("%d\n", k);
    } while (++k < 10);

    return 0;
}
