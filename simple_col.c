#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int 
main(int argc, char *argv[])
{
	initscr();
	if(has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}

	start_color();
	init_color(8, 500, 0, 500);
       	init_pair(1, 8, 0);


	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, 9, 0, 0, "Viola !!! In color ...");
	attroff(COLOR_PAIR(1));
	getch();
	endwin();
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
	int length, x, y;
	float temp;

	if (win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = COLS;
	length = strlen(string);
	temp = (width -length)/2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}


