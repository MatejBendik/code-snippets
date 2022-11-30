#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <stdbool.h>
#include <unistd.h>

void loading_screen();

int main(){

    loading_screen();

    retrun 0;
}

void loading_screen()
{
    clear();
    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2 + 1, COLS - COLS + 3, "[");
    mvprintw(LINES / 2 + 1, COLS - 4, "]");
    attroff(COLOR_PAIR(1));

    refresh();

    char title[7][150] = {
        "   ____      ____     __   __   ____     ______    _____     __   __        _        __     _      ",
        "  |  _ \\    / __ \\   |  \\/  |  |  _ \\   |  ____|  |  __\\    |  \\/  |      /  \\      |   \\  | |               ",
        "  | |_) |  | |  | |  | \\  / |  | |_) |  | |__     | |__) |  | \\  / |     / /\\ \\     | |\\ \\ | |              ",
        "  |  _ <   | |  | |  | |\\/| |  |  _ <   |  __|    |  _  /   | |\\/| |    / ____ \\    | | \\ \\| |               ",
        "  | |_) |  | |__| |  | |  | |  | |_) |  | |____   | | \\ \\   | |  | |   / /    \\ \\   | |  \\   |                ",
        "  |____/    \\____/   |_|  |_|  |____/   |______|  |_|  \\_\\  |_|  |_|  /_/      \\_\\  |_|   \\__|                ",
        "                                                                                                          "};

    int center = COLS / 2 - strlen(title[0]) / 2;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            mvprintw(LINES - LINES + 5 + i, center + j, "%c", title[i][j]);
        }
    }

    for (int j = 0; j < COLS - 8; j++)
    {
        mvprintw(LINES / 2 + 1, COLS / COLS + 2 + j + 1, "=");
        refresh();
        usleep(10000);
    }

    mvprintw(LINES / 2 + 3, COLS / 2 - 10, "Press any key to continue...");

    refresh();
    getchar();
}
