#include <stdio.h>
#include <string.h>
#include "life.h"

static void dump_field(int field[HEIGHT][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            putchar(field[y][x] ? '#' : '.');
        putchar('\n');
    }
    putchar('\n');
}

int main(void)
{
    int a[HEIGHT][WIDTH] = {0};
    int b[HEIGHT][WIDTH];

    /* a glider */
    a[1][2] = a[2][3] = a[3][1] = a[3][2] = a[3][3] = 1;

    for (int g = 0; g < GENERATIONS; g++) {
        dump_field(a);
        evolve(a, b);
        memcpy(a, b, sizeof(a));
    }
    return 0;
}
