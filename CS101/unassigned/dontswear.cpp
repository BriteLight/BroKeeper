#include <ncurses.h>
#include <string>

using namespace std;
void start_ncurses(bool useRaw, bool useNoecho);
void printMenu(WINDOW * menu, string choices[], int size, int highlight);

int main(int argc, char ** argv) {
	initscr();
	noecho();
	cbreak();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW * inputwin = newwin(1, xMax-12, yMax-5, 5);
	box(inputwin, 0, 0);
	refresh();
	wrefresh(inputwin);
	getch();
	endwin();
	return 0;
}

