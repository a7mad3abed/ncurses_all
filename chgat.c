#include <ncurses.h>

int 
main (int argc, char ** argv)
{
	initscr();
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);

	printw("A big string which i didn't care to type fully ");
	mvchgat(0, 9, -1, A_BLINK, 1, NULL);

	refresh();
	getch();
	endwin();
}


