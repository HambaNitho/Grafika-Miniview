#include "view.hpp"

/*
 * 
 * Constructor
 *
 */

view::view() {
	this->height = 0;
	this->width = 0;
	this->position.set_coord(0,0);
	this->window_height = 600;
	this->window_width = 800;
}

view::view(int height, int width, point position) {
	this->height = height;
	this->width = width;
	this->position.set_coord(position.get_x(),position.get_y());
	this->window_height = 600;
	this->window_width = 800;
}

view::view(int height, int width, int xpos, int ypos) {
	this->height = height;
	this->width = width;
	this->position.set_coord(xpos,ypos);
	this->window_height = 600;
	this->window_width = 800;
}

/*
 * 
 * Setter and Getter
 *
 */

int view::get_width() const {
	return width;
}

int view::get_height()const {
	return height;
}

point view::get_position() const {
	return position;
}

void view::set_width(int width) {
	this->width = width;
}

void view::set_height(int height) {
	this->height = height;
}

void view::set_position(int x, int y) {
	this->position.set_coord(x,y);
}


void view::add_line(line l) {
	lines.push_back(l);
}

void view::draw() {

	int x1 = position.get_x();
	int y1 = position.get_y();

	int x2 = x1 + width;
	int y2 = y1 + height;

	line l1(x1, y1, x2, y1);
	line l2(x2, y1, x2, y2);
	line l3(x2, y2, x1, y2);
	line l4(x1, y2, x1, y1);

	l1.draw(); l2.draw(); l3.draw(); l4.draw();

	for (int i = 0; i < lines.size(); i++) {
		point p1 = lines[i].get_first_point();
		point p2 = lines[i].get_last_point();

		int x1 = p1.get_x();
		int y1 = p1.get_y();
		int x2 = p2.get_x();
		int y2 = p2.get_y();

		fb_var_screeninfo vinfo = canvas::get_instance()->get_var_info();

		float ratio_x = (float)this->width /  vinfo.xres;
		float ratio_y = (float)this->height / vinfo.yres;


		// PENTING!!!!!!!!!!!!!!!!!! 
		// ASUMSI ORIGIN 0, 0
		int v1x = (x1 - 0) * ratio_x + position.get_x();
		int v1y = (y1 - 0) * ratio_y + position.get_y();

		int v2x = (x2 - 0) * ratio_x + position.get_x();
		int v2y = (y2 - 0) * ratio_y + position.get_y();

		line new_l(v1x, v1y, v2x, v2y);

		new_l.draw();
	}
}

/*
 * 
 * Transformation
 *
 */

void view::scrollz(char direction) {
	int x = get_position().get_x();
	int y = get_position().get_y();
	switch (direction) {
		case 'u': set_position(x,y-10); break;
		case 'd': set_position(x,y+10); break;
		case 'l': set_position(x-10,y); break;
		case 'r': set_position(x+10,y); break;
	}
}

void view::zoom(char direction) {

}