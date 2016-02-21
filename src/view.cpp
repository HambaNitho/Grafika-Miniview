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

/*
 * 
 * Transformation
 *
 */

void view::scroll(char direction) {
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