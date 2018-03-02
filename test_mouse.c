#include <assert.h>
#include <ncurses.h>

int main()
{
	MEVENT event;

	initscr();
	noecho();
	cbreak();

	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

	 printf("\033[?1003h\n"); // Makes the terminal report mouse movement events
	
	int c; 
	int x = 0;
	int y = 0;

	while((c = getch()) != 'q')
	{
		if (c == KEY_MOUSE)
		{
			assert(getmouse(&event) == OK);
			if( event.bstate & BUTTON1_CLICKED)
			{
				mvprintw(y, x, "left button clicked");
				y++;
			}
			refresh();

		}
	}
	

	printf("\033[?1003l\n"); // Disable mouse movement events, as l = low
	endwin();
	return 0;
}

