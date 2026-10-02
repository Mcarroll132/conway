#include "life.h"

int count_alive(int field[HEIGHT][WIDTH], int y, int x)
{
    int n = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0)
                continue;
            int ny = y + dy, nx = x + dx;
            if (ny >= 0 && ny < HEIGHT && nx >= 0 && nx < WIDTH)
                n += field[ny][nx];
        }
    }
    return n;
}

void evolve(int field[HEIGHT][WIDTH], int next[HEIGHT][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int n = count_alive(field, y, x);
            next[y][x] = (n == 3) || (field[y][x] && n == 2);
        }
    }
}
