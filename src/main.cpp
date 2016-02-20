#include "gl.hpp"

int main() {

	initscr();
	noecho();
	int ch;
	nodelay(stdscr, TRUE);

	point p(0,0);
	view v(600,800,p);

	while(true) {
		if ((ch = getch()) == ERR) {
			// user hasn't responded

		}
		else {
			//user has pressed a key ch
    		canvas::get_instance()->clear();
			switch(ch) {
				case 65: // key up
					v.scroll('u');
					break;
				case 66: // key down
					v.scroll('d');
					break;
				case 67: // key right
					v.scroll('r');
					break;
				case 68: // key left
					v.scroll('l');
					break;
				default:
					break;
			}
			canvas::get_instance()->render();
		}
	}
    return 0;
}