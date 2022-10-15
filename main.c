#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char map[10][21];
    char dog = '@';
    char apple = '*';
    char input;

    int x = 10, y = 5;
    int ox, oy;
    int ax = 5, ay = 3;
    int score = 0;


    srand(time(NULL));

    do {
        sprintf(map[0], "####################");
        for (int i = 1; i < 9; ++i)
            sprintf(map[i], "#                  #");
        sprintf(map[9], "####################");

        map[y][x] = dog;
        map[ay][ax] = apple;

        system("cls");
        for (int i = 0; i < 10; ++i) {
            printf("%s\n", map[i]);
        }
        printf("\n Score: %d", score);

        input = getch();

        ox = x;
        oy = y;
        switch (input) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
        }

        if (map[y][x] == '#') {
            x = ox;
            y = oy;
        }

        if ((x == ax) && (y == ay)) {
            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;

            score++;
        }

    } while (input != 'e');

    return 0;
}
