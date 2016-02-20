#include "gl.hpp"
#include <ncurses.h>

int main() {

	line l(0, 0, 100, 100);
	line x(100, 100, 200, 500);
	line y(200, 500, 700, 300);

	l.draw();
	x.draw();
	y.draw();

	view v(270, 480, 400, 400);
	v.add_line(l);
	v.add_line(x);
	v.add_line(y);

	v.draw();

	canvas::get_instance()->render();
    return 0;
}