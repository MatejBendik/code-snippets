#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

void moving_arrow();

int main(){
    srand(time(NULL));
    // initialize the library
    initscr();
    // set implicit modes
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    // invisible cursor, visibility of cursor (0,1,2)
    curs_set(FALSE);
    // getch() will be non-blocking
    nodelay(stdscr, TRUE);

    return 0;
}

void moving_arrow()
{
    clear();
    int y = LINES / 2;
    int x = COLS / 2;
    char buffer[] = "Press q/Q to quit. Move by arrows.";
    mvprintw(LINES - 1, 0, "%s", buffer);
    char player = '>', previous = ' ';
    mvprintw(y, x, "%c", player);
    refresh();
    int c;
    do
    {
        c = getch();
        previous = (y == LINES - 1 && x < 34) ? buffer[x] : ' ';
        if (c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN)
        {
            mvprintw(y, x, "%c", previous);
        }
        switch (c)
        {
        case KEY_LEFT:
            player = '<';
            x = (x > 0) ? x - 1 : COLS - 1;
            break;
        case KEY_RIGHT:
            player = '>';
            x = (x < COLS - 1) ? x + 1 : 0;
            break;
        case KEY_UP:
            player = '^';
            y = (y > 0) ? y - 1 : LINES - 1;
            break;
        case KEY_DOWN:
            player = 'v';
            y = (y < LINES - 1) ? y + 1 : 0;
            break;
        default:
            continue;
            break;
        }
        mvprintw(y, x, "%c", player);
        refresh();
    } while (c != 'q' && c != 'Q');
}
