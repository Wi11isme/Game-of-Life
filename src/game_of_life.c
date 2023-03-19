#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define HEIGHT 25
#define WIDTH 80

void input(int** field1, int** field2);
void draw(int** field);
int new_cell(int** field, int y, int x);
void copy(int** field1, int** field2);

int main() {
    int** field1 = malloc(HEIGHT * sizeof(int*));
    int* ptr1 = malloc(HEIGHT * WIDTH * sizeof(int));
    for (int i = 0; i < HEIGHT; i++) {
        field1[i] = ptr1 + WIDTH * i;
    }
    for (int q = 0; q < HEIGHT; q++) {
        for (int s = 0; s < WIDTH; s++) {
            scanf("%d", &field1[q][s]);
        }
    }
    for (int i = 0; i < 30; i++) {
        usleep(300000);
        system("clear");
        draw(field1);
        int** field2 = malloc(HEIGHT * sizeof(int*));
        int* ptr2 = malloc(HEIGHT * WIDTH * sizeof(int));
        for (int k = 0; k < HEIGHT; k++) field2[k] = ptr2 + WIDTH * k;
        input(field1, field2);
        copy(field1, field2);
        free(ptr2);
        free(field2);
    }
    free(ptr1);
    free(field1);
    return 0;
}

void input(int** field1, int** field2) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field2[i][j] = new_cell(field1, i, j);
        }
    }
}

void draw(int** field) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j]) {
                if (j == WIDTH - 1)
                    printf("#\n");
                else
                    printf("#");
            } else {
                if (j == WIDTH - 1)
                    printf(".\n");
                else
                    printf(".");
            }
        }
    }
}

int new_cell(int** field, int y, int x) {
    int result_cell = field[y][x], count;
    x += WIDTH;
    y += HEIGHT;
    count = field[(y - 1) % HEIGHT][(x - 1) % WIDTH] + field[(y - 1) % HEIGHT][x % WIDTH] +
            field[(y - 1) % HEIGHT][(x + 1) % WIDTH] + field[y % HEIGHT][(x - 1) % WIDTH] +
            field[y % HEIGHT][(x + 1) % WIDTH] + field[(y + 1) % HEIGHT][(x - 1) % WIDTH] +
            field[(y + 1) % HEIGHT][x % WIDTH] + field[(y + 1) % HEIGHT][(x + 1) % WIDTH];
    x -= WIDTH;
    y -= HEIGHT;
    if (field[y][x]) {
        if (count != 2 && count != 3) result_cell = 0;
    } else if (count == 3)
        result_cell = 1;
    return result_cell;
}

void copy(int** copy_field, int** field_orig) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            copy_field[i][j] = field_orig[i][j];
        }
    }
}
