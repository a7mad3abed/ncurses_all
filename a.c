#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int keytype;
enum {
	NOT_DIRECTION,
	IS_DIRECTION
};

	


struct punkt{
	int y;
	int x;
	struct punkt *punkt_next;
};

typedef struct punkt PUNKT;

PUNKT p_first;


PUNKT *find_last()
{
	PUNKT *p;
	if(p_first.punkt_next == NULL)
		return &p_first;
	else
	{
		for(p = &p_first; p->punkt_next != NULL; p = p->punkt_next)
			;
	}
	return p;
}
		
	



void new_punkt(int direction)
{
	PUNKT p;
	PUNKT *p_last = find_last();
	switch (direction)
	{
		case KEY_UP:
			keytype = IS_DIRECTION;
			p.y = --(p_last->y);
			p.x = p_last->x;
			p.punkt_next = NULL;
			break;
		case KEY_DOWN:
			keytype = IS_DIRECTION;
			p.y = ++(p_last->y);
			p.x = p_last->x;
			p.punkt_next = NULL;
			break;
		case KEY_RIGHT:
			keytype = IS_DIRECTION;
			p.y = p_last->y;
			p.x = ++(p_last->x);
			p.punkt_next = NULL;
			break;
		case KEY_LEFT:
			keytype = IS_DIRECTION;
			p.y = p_last->y;
			p.x = --(p_last->x);
			p.punkt_next = NULL;
			break;
		default:
			keytype = NOT_DIRECTION;
			break;
	}


	if (keytype == IS_DIRECTION)
		mvaddch(p.y, p.x, '*');
}

int main(int argc, char *argv[])
{


	int c;
	initscr();
	start_color();
	init_pair(1, 1, COLOR_BLACK);
	init_pair(2, 2, COLOR_BLACK);
	init_pair(3, 3, COLOR_BLACK);
	init_pair(4, 4, COLOR_BLACK);
	init_pair(5, 5, COLOR_BLACK);
	init_pair(6, 6, COLOR_BLACK);
	init_pair(7, 7, COLOR_BLACK);
			
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	p_first.y = LINES/2;
	p_first.x = COLS/2;
	p_first.punkt_next = NULL;
	mvaddch(p_first.y, p_first.x, '*');

	int i = 1;
	while((c = getch()) != 'q')
	{
		if(i == 8)
			i = 1;
		attron(COLOR_PAIR(i));
		new_punkt(c);
		i++;

		
	}
	endwin();

	return 0;
}

