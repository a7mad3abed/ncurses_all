#include <stdio.h>
#include <ncurses.h>

int main() /* This is the main function */
{
	initscr(); /* here we initialize */
	int c;
	int row, col;
	printw("Hello World !!!");
	noecho();
	//keypad(stdscr, TRUE);
	refresh();

	while((c = getch()) != 'q')
	{
		if (c == 27)
			noecho();
		if (c == 'i')
			echo();
		
		//getmaxyx(stdscr, row, col);
		//mvprintw(0, 0, "%c", c);
	}
	endwin();
}
