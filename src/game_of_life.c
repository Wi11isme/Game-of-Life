#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MMAX 25
#define NMAX 80

void input(int field1[][NMAX], int field2[][NMAX]);
void draw(int field[][NMAX]);
int new_cell(int field1[][NMAX], int x, int y);

int main() {
    int field1[MMAX][NMAX];
    for (int i = 0; i < MMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            field1[i][j] = rand() % 2;
        }
    }
    system("clear");
    draw(field1);
    int field2[MMAX][NMAX];
    input(field1, field2);
    printf("\n хто я\n");

    // system("clear");
    draw(field2);
    return 0;
}

void input(int field1[][NMAX], int field2[][NMAX]) {
    for (int i = 0; i < MMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            field2[i][j] = new_cell(field1, i, j);
        }
    }
}

void draw(int field1[][NMAX]) {
    for (int i = 0; i < MMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            if (field1[i][j]) {
                if (j == NMAX - 1)
                    printf("#\n");
                else
                    printf("#");
            } else {
                if (j == NMAX - 1)
                    printf(".\n");
                else
                    printf(".");
            }
        }
    }
}

int new_cell(int field1[][NMAX], int x, int y) {
    int result_cell = field1[x][y], count = 0;
    for (int i = x - 1; i < x + 2; i++) {
        for (int j = y - 1; j < y + 2; j++) {
            if (i != x || j != y) {
                if (field1[i][j]) count++;
            }
        }
    }
    if (field1[x][y]) {
        if (count != 2 && count != 3) result_cell = 0;
    } else if (count == 3)
        result_cell = 1;
    return result_cell;
}
