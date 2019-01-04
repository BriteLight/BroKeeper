#include <ncurses.h>
#include <iostream>

int main(int argc, char * argv) {
	WINDOW *w;
	w=initscr();
	mvaddstr(10, 10, "Messages goes here...");
	getch();
	endwin();
	return 0;
}

