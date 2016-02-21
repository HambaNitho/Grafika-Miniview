#include "view.hpp"
#include "polygon.hpp"

/*
 * 
 * Constructor
 *
 */

view::view() {
	this->height = 0;
	this->width = 0;
	this->position.set_coord(0,0);
	this->clip_position.set_coord(0,0);
	this->window_height = canvas::get_instance()->get_var_info().yres;
	this->window_width = canvas::get_instance()->get_var_info().xres;
	set_ratio();
}

view::view(int height, int width, point position, point clip_position, float scale) {
	this->height = height;
	this->width = width;
	this->position.set_coord(position.get_x(),position.get_y());
	this->clip_position.set_coord(clip_position.get_x(),clip_position.get_y());
	this->window_height = height * scale;
	this->window_width = width * scale;
	set_ratio();
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


void view::draw(polygon p) {

	// Draw map
	int x1 = position.get_x();
	int y1 = position.get_y();

	int x2 = x1 + width;
	int y2 = y1 + height;

	line l1(x1, y1, x2, y1);
	line l2(x2, y1, x2, y2);
	line l3(x2, y2, x1, y2);
	line l4(x1, y2, x1, y1);

	l1.draw(); l2.draw(); l3.draw(); l4.draw();
	
	// Draw clipped area
	int cx1 = clip_position.get_x();
	int cy1 = clip_position.get_y();
	int cx2 = cx1 + window_width;
	int cy2 = cy1 + window_height;

	line cl1(cx1, cy1, cx2, cy1);
	line cl2(cx2, cy1, cx2, cy2);
	line cl3(cx2, cy2, cx1, cy2);
	line cl4(cx1, cy2, cx1, cy1);

	cl1.draw(0xffff0000); cl2.draw(0xffff0000); cl3.draw(0xffff0000); cl4.draw(0xffff0000);

	std::vector<point> points = p.get_points();
	
	for (int i = 0; i < points.size(); i++) {
		
		point p1 = points[i];
		point p2 = points[(i + 1) % points.size()];


		int x1 = p1.get_x();
		int y1 = p1.get_y();
		int x2 = p2.get_x();
		int y2 = p2.get_y();

		fb_var_screeninfo vinfo = canvas::get_instance()->get_var_info();


		// Get view-clipped ratio, save scale instead?
		float ratio_x = (float)this->width /  this->window_width;
		float ratio_y = (float)this->height / this->window_height;
		
		//view.y = (map.y - view.project_position_y) * view.ratio_y + view.position_y;
		//view.x = (map.x - view.project_position_x) * view.ratio_x + view.position_x;
		
		// ______________________________________________________
		//|                                                      |
		//| ________________                                     |
		//||                |                                    |
		//||   clipped      |                                    |        _____________________
		//||                |                                    |       |                     |
		//||________________|     MAP                            |       |                     |
		//|                                                      |       |        view         |
		//|                                                      |       |                     |
		//|                                                      |       |                     |
		//|                                                      |       |_____________________|
		//|                                                      |
		//|______________________________________________________|

		int v1x = (x1 - clip_position.get_x()) * ratio_x + position.get_x();
		int v1y = (y1 - clip_position.get_y()) * ratio_y + position.get_y();

		int v2x = (x2 - clip_position.get_x()) * ratio_x + position.get_x();
		int v2y = (y2 - clip_position.get_y()) * ratio_y + position.get_y();

		line new_l(v1x, v1y, v2x, v2y);

		new_l.draw();
	}
}

void view::move_clip(int delta_x, int delta_y) {
	clip_position.set_x(clip_position.get_x() + delta_x);
	clip_position.set_y(clip_position.get_y() + delta_y);
}

void view::zoom(float scale) {
	this->window_height += height_ratio*scale;
	this->window_width += width_ratio*scale;
}

void view::set_ratio() {
	
	int a,b,c;
	a = width;
	b = height;
	while ( a != 0 ) {
	   c = a; a = b%a;  b = c;
	}
	width_ratio = width/b;
	height_ratio = height/b;
}