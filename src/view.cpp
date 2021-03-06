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

		//line new_l(v1x, v1y, v2x, v2y);

		//new_l.draw();
		int l1,r1,b1,t1,l2,r2,b2,t2;

		if (v1x >= position.get_x()) l1=0; else l1=1;
		if (v1x > position.get_x()+width) r1=1; else r1=0; 
		if (v1y > position.get_y()+height) b1=1; else b1=0;
		if (v1y >= position.get_y()) t1=0; else t1=1;

		if (v2x >= position.get_x()) l2=0; else l2=1;
		if (v2x > position.get_x()+width) r2=1; else r2=0; 
		if (v2y > position.get_y()+height) b2=1; else b2=0;
		if (v2y >= position.get_y()) t2=0; else t2=1;
		

		if (l1==0 && r1==0 && b1==0 && t1==0 && l2==0 && r2==0 && b2==0 && t2==0) {
			// garis visible
			line new_l(v1x, v1y, v2x, v2y);
			new_l.draw();
		}
		else {
			int logicbit[4];
			logicbit[0] = l1 && l2;
			logicbit[1] = r1 && r2;
			logicbit[2] = b1 && b2;
			logicbit[3] = t1 && t2;

			if ((logicbit[0] || logicbit[1] || logicbit[2] || logicbit[3]) == 0) {
				// clipping
				int new_v1x, new_v1y, new_v2x, new_v2y;

				// cek point 1
				if (l1==1 && r1==0 && b1==0 && t1==1) {
					// perpotongannya ada di left atau top
					// anggap di left
					new_v1x = position.get_x();
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
					if (new_v1y<position.get_y() || new_v1y>position.get_y()+height) {
						// ternyata ada di top
						new_v1y = position.get_y();
						new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
					}
				}
				else if (l1==0 && r1==0 && b1==0 && t1==1) {
					// perpotongannya ada di top
					new_v1y = position.get_y();
					new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
				}
				else if (l1==0 && r1==1 && b1==0 && t1==1) {
					// perpotongannya ada di right atau top
					// anggap di right
					new_v1x = position.get_x() + width;
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
					if (new_v1y<position.get_y() || new_v1y>position.get_y()+height) {
						// ternyata ada di top
						new_v1y = position.get_y();
						new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
					}
				}
				else if (l1==1 && r1==0 && b1==0 && t1==0) {
					// perpotongannya ada di left
					new_v1x = position.get_x();
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
				}
				else if (l1==0 && r1==1 && b1==0 && t1==0) {
					// perpotongannya ada di right
					new_v1x = position.get_x() + width;
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
				}
				else if (l1==1 && r1==0 && b1==1 && t1==0) {
					// perpotongannya ada di left atau bottom
					// anggap di left
					new_v1x = position.get_x();
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
					if (new_v1y<position.get_y() || new_v1y>position.get_y()+height) {
						// ternyata ada di bottom
						new_v1y = position.get_y() + height;
						new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
					}
				}
				else if (l1==0 && r1==0 && b1==1 && t1==0) {
					// perpotongannya ada di bottom
					new_v1y = position.get_y() + height;
					new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
				}
				else if (l1==0 && r1==1 && b1==1 && t1==0) {
					// perpotongannya ada di right atau bottom
					// anggap di right
					new_v1x = position.get_x() + width;
					new_v1y = ((v2y - v1y)/(v2x - v1x)) * (new_v1x - v1x) + v1y;
					if (new_v1y<position.get_y() || new_v1y>position.get_y()+height) {
						// ternyata ada di bottom
						new_v1y = position.get_y() + height;
						new_v1x = ((v2x - v1x)/(v2y - v1y)) * (new_v1y - v1y) + v1x;
					}
				}
				else {
					new_v1y = v1y;
					new_v1x = v1x;
				}



				//cek point 2
				if (l2==1 && r2==0 && b2==0 && t2==1) {
					// perpotongannya ada di left atau top
					// anggap di left
					new_v2x = position.get_x();
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
					if (new_v2y<position.get_y() || new_v2y>position.get_y()+height) {
						// ternyata ada di top
						new_v2y = position.get_y();
						new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
					}
				}
				else if (l2==0 && r2==0 && b2==0 && t2==1) {
					// perpotongannya ada di top
					new_v2y = position.get_y();
					new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
				}
				else if (l2==0 && r2==1 && b2==0 && t2==1) {
					// perpotongannya ada di right atau top
					// anggap di right
					new_v2x = position.get_x() + width;
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
					if (new_v2y<position.get_y() || new_v2y>position.get_y()+height) {
						// ternyata ada di top
						new_v2y = position.get_y();
						new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
					}
				}
				else if (l2==1 && r2==0 && b2==0 && t2==0) {
					// perpotongannya ada di left
					new_v2x = position.get_x();
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
				}
				else if (l2==0 && r2==1 && b2==0 && t2==0) {
					// perpotongannya ada di right
					new_v2x = position.get_x() + width;
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
				}
				else if (l2==1 && r2==0 && b2==1 && t2==0) {
					// perpotongannya ada di left atau bottom
					// anggap di left
					new_v2x = position.get_x();
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
					if (new_v2y<position.get_y() || new_v2y>position.get_y()+height) {
						// ternyata ada di bottom
						new_v2y = position.get_y() + height;
						new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
					}
				}
				else if (l2==0 && r2==0 && b2==1 && t2==0) {
					// perpotongannya ada di bottom
					new_v2y = position.get_y() + height;
					new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
				}
				else if (l2==0 && r2==1 && b2==1 && t2==0) {
					// perpotongannya ada di right atau bottom
					// anggap di right
					new_v2x = position.get_x() + width;
					new_v2y = ((v2y - v1y)/(v2x - v1x)) * (new_v2x - v1x) + v1y;
					if (new_v2y<position.get_y() || new_v2y>position.get_y()+height) {
						// ternyata ada di bottom
						new_v2y = position.get_y() + height;
						new_v2x = ((v2x - v1x)/(v2y - v1y)) * (new_v2y - v1y) + v1x;
					}
				}
				else {
					new_v2y = v2y;
					new_v2x = v2x;
				}

				line new_l(new_v1x, new_v1y, new_v2x, new_v2y);
				new_l.draw();
			}
		}
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