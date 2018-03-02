#include <ncurses.h>
#include <stdlib.h>

struct line_struct
{
	int y, x, width;
	char drawer;
};

typedef struct line_struct LN;
typedef struct line_struct *LNP;

char ch;

static void init_line(LN *newline)
{
	newline->y = LINES/2;
	newline->width = 10;
	newline->x = (COLS-(newline->width))/2;
	newline->drawer = '*';
}


static void move_line(LN *newline)
{

	int y, x, width;
	char drawer;
	y = newline->y;
	x = newline->x;
	width = newline->width;
	drawer = newline->drawer;

	mvhline(y , x, drawer, width);
	refresh();
}

static void erase_line(LN *newline)
{
	int y, x, width;
	char drawer;
	y = newline->y;
	x = newline->x;
	width = newline->width;
	drawer = newline->drawer;
	int i;

	for (i = x; i <= (x+width); i++)
		mvaddch(y, i, ' ');
	refresh();
}

int main(int argc, char **argv)
{
	LNP new_line;
	new_line = (LNP )malloc(sizeof(LN));
	initscr();
	start_color();
	noecho();
	cbreak();
	init_pair(1, COLOR_RED, COLOR_BLACK);


	attron(COLOR_PAIR(1));
	
	init_line(new_line);
	move_line(new_line);



	while((ch = getch()) != 'q')
	{
		switch (ch)
		{
			case 'l':
				erase_line(new_line);
				++(new_line->x);
				move_line(new_line);
				break;
			case 'h':
				erase_line(new_line);
				--(new_line->x);
				move_line(new_line);
				break;
			case 'k':
				erase_line(new_line);
				(new_line->y)--;
				move_line(new_line);
				break;
			case 'j':
				erase_line(new_line);
				(new_line->y)++;
				move_line(new_line);
				break;
		}
	}

	endwin();
}

