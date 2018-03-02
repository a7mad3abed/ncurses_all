#include <ncurses.h>

int main()
{
	int ch;
	initscr();


	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Type any character to see it in bold\n");

	ch = getch();

	if(ch == KEY_F(2))
		printw("F2 key Pressed");

	else 
	{
		mvwprintw(stdscr, 2,5,"The pressed key is ");
		//attron(A_BOLD);
		//printw("%c", ch);

		addch(ch | A_BOLD | A_UNDERLINE);
		//attroff(A_BOLD);
	}

	refresh();
	getch();
	endwin();

	return 0;
}

