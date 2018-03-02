#include <ncurses.h>
#include <string.h>
#include <assert.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] ={	"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit"
};

int n_choices = sizeof(choices)/ sizeof(char*);

void print_menu(int highlight);
void report_choice(int mouse_x, int mouse_y, int *p_choice);

int main()
{
	int c, choice = 0;
	WINDOW *menu_win;
	MEVENT event;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	startx = 2;
	starty = 2;

	attron(A_REVERSE);
	mvprintw(43, 1, "Click on Exit to quit (Works best in a virtual console)");
	refresh();
	attroff(A_REVERSE);

	//menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(1);
	mousemask(ALL_MOUSE_EVENTS , NULL);

	printf("\033[?1003h\n"); // that was the missing code to activate the mouse

	while((c = getch()) != 'q')
	{
	//	assert(getmouse(&event) == OK);
		switch(c)
		{
			case KEY_MOUSE:
				if (getmouse(&event) == OK)
				{
					if (event.bstate & BUTTON1_CLICKED)
					{
						report_choice(event.x + 1, event.y + 1, &choice);
						if(choice == -1)
							goto end;
						mvprintw(22, 1, "Choice made is: %d String Chosen is \"%10s\"", choice , choices[choice - 1]);
						refresh();
					}
				}
				print_menu(choice);
				refresh();
				break;
		}
	}
end:
	printf("\033[?1003l\n"); // that is important too to restore the normal terminal state
	endwin();
	return 0;
}

void print_menu(int highlight)
{
	int x, y, i;
	x = 2;
	y = 2;
	for(i = 0; i < n_choices; ++i)
	{
		if(highlight == i + 1)
		{
			attron(A_REVERSE);
			mvprintw(y, x, "%s", choices[i]);
			attroff(A_REVERSE);
		}
		else
			mvprintw(y, x, "%s", choices[i]);
		++y;
	}
	refresh();
}

void report_choice(int mouse_x, int mouse_y, int *p_choice)
{
	int i, j, choice;

	i = startx + 0;
	j = starty + 1;

	for(choice = 0; choice < n_choices; ++choice)
		if(mouse_y == j + choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice]))
		{
			if(choice == n_choices - 1)
				*p_choice = -1;
			else 
				*p_choice = choice + 1;
			break;
		}
}
