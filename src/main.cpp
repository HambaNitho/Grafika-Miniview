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

	p1.add_point(2*coef, 1*coef);
	p1.add_point(4*coef, 3*coef);
	p1.add_point(4*coef, 5*coef);
	p1.add_point(7*coef, 8*coef);
	p1.add_point(6*coef, 9*coef);
	p1.add_point(5*coef, 9*coef);
	p1.add_point(2*coef, 6*coef);
	p1.add_point(2*coef, 1*coef);

	polygon p2;
	p2.add_point(10*coef, 7*coef);
	p2.add_point(10*coef, 6*coef);
	p2.add_point(9*coef, 5*coef);
	p2.add_point(9*coef, 3*coef);
	p2.add_point(11*coef, 1*coef);
	p2.add_point(12*coef, 1*coef);
	p2.add_point(13*coef, 0*coef);
	p2.add_point(17*coef, 0*coef);
	p2.add_point(17*coef, 1*coef);
	p2.add_point(15*coef, 3*coef);
	p2.add_point(17*coef, 5*coef);
	p2.add_point(15*coef, 7*coef);
	p2.add_point(10*coef, 7*coef);

	polygon p3;
	p3.add_point(9*coef, 9*coef);  
	p3.add_point(15*coef, 9*coef);  
	p3.add_point(17*coef, 11*coef);  
	p3.add_point(10*coef, 11*coef);  
	p3.add_point(9*coef, 10*coef);  
	p3.add_point(9*coef, 9*coef);

	polygon p4;
	p4.add_point(20*coef, 7*coef);
	p4.add_point(20*coef, 3*coef);
	p4.add_point(22*coef, 1*coef);
	p4.add_point(26*coef, 1*coef);
	p4.add_point(26*coef, 2*coef);
	p4.add_point(25*coef, 3*coef);
	p4.add_point(24*coef, 3*coef);
	p4.add_point(23*coef, 4*coef);
	p4.add_point(25*coef, 6*coef);
	p4.add_point(25*coef, 7*coef);
	p4.add_point(26*coef, 8*coef);
	p4.add_point(26*coef, 9*coef);
	p4.add_point(24*coef, 9*coef);
	p4.add_point(22*coef, 7*coef);
	p4.add_point(20*coef, 9*coef);

	
	polygon p6;
	p6.add_point(37*coef, 10*coef);
	p6.add_point(36*coef, 9*coef);
	p6.add_point(35*coef, 9*coef);
	p6.add_point(32*coef, 6*coef);
	p6.add_point(31*coef, 6*coef);
	p6.add_point(30*coef, 5*coef);
	p6.add_point(28*coef, 3*coef);
	p6.add_point(28*coef, 2*coef);
	p6.add_point(31*coef, 2*coef);
	p6.add_point(33*coef, 4*coef);
	p6.add_point(36*coef, 1*coef);
	p6.add_point(40*coef, 1*coef);
	p6.add_point(40*coef, 10*coef);
	p6.add_point(37*coef, 10*coef);

	


	

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
        v.draw(p2);
        v.draw(p3);
        v.draw(p4);
        v.draw(p6);
		p1.draw_stroke(0, 0);
		p2.draw_stroke(0, 0);
		p3.draw_stroke(0, 0);
		p4.draw_stroke(0, 0);
		p6.draw_stroke(0,0);
		canvas::get_instance()->render();
        c = getch();   
        switch(c) {
            case 122:       // key z
                v.zoom(-1);
                break;
            case 120:       // key x
                v.zoom(1);
                break;
            case 65:       // key up
                v.move_clip(0, -4);
                break;
            case 66:       // key down
                v.move_clip(0, 4);     
                break;
            case 67:       // key right
                v.move_clip(4, 0);
                break;
            case 68:       // key left
                v.move_clip(-4, 0);
                break;
            default:
                v.move_clip(0, 0);
                break;
        }
		canvas::get_instance()->clear();
		//v.move_clip(1, 0);
		//v.draw(p1);	

		//usleep(100000);
	}

    return 0;
}