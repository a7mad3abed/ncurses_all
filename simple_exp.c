#include <ncurses.h>
#include <string.h>

int main()
{
	char mesg[] = "Just a string";
	int row, col;

	initscr();


	// This is very important: this is the function to get the recent coordinates and 
	// save it in variables
	getmaxyx(stdscr, row, col);


	mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg);

	mvprintw(row-3, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window(if possible) and then run this program again\n");
	addnstr( mesg, -1);
	

	refresh();
	getch();
	endwin();

	return 0;
}
