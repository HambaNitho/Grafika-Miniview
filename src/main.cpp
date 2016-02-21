#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "gl.hpp"
//#include <ncurses.h>
using namespace std;

int main() {

	polygon p1;
	int coef = 30;

	p1.add_point(2*coef, 0*coef);
	p1.add_point(4*coef, 2*coef);
	p1.add_point(4*coef, 4*coef);
	p1.add_point(7*coef, 7*coef);
	p1.add_point(6*coef, 8*coef);
	p1.add_point(5*coef, 8*coef);
	p1.add_point(2*coef, 5*coef);
	p1.add_point(2*coef, 0*coef);
	
	

	int width = 480;
	int height = 270;

	int xPos = canvas::get_instance()->get_var_info().xres - width - 10;
	int yPos = canvas::get_instance()->get_var_info().yres - height - 10;
	point view_pos(xPos,yPos);

	point clipping_pos(0,0);
	view v(height, width, view_pos, clipping_pos, 0.5);
	
	initscr();
    noecho();
    timeout(-1);
    int c;

	while (true) {
        v.draw(p1);
		p1.draw_stroke(0, 0);
		canvas::get_instance()->render();
		canvas::get_instance()->clear();
        c = getch();   
        switch(c) {
            case 122:       // key z
                v.zoom(-1);
                break;
            case 120:       // key x
                v.zoom(1);
                break;
            case 65:       // key up
                v.move_clip(0, -1);
                break;
            case 66:       // key down
                v.move_clip(0, 1);     
                break;
            case 67:       // key right
                v.move_clip(1, 0);
                break;
            case 68:       // key left
                v.move_clip(-1, 0);
                break;
            default:
                v.move_clip(0, 0);
                break;
        }
		//v.move_clip(1, 0);
		//v.draw(p1);	

		//usleep(100000);
	}

    return 0;
}