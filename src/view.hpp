#ifndef _VIEW_H
#define _VIEW_H

#include "point.hpp"
#include "line.hpp"
#include "polygon.hpp"
#include <vector>

class view {
public:
	// Constructor
	view();
	view(int height, int width, point position, point clip_position, float scale);

	// Setter and getter
	int get_width() const;
	int get_height() const;
	
	point get_position() const;
	
	void set_width(int width);
	void set_height(int height);
	void set_position(int x, int y);

	// Move clip position
	void move_clip(int delta_x, int delta_y);

	// Change scale of clip
	void zoom(float scale);


	void draw(polygon p);


private:
	int height;
	int width;
	point position; // view position on screen
	// window = clipped area
	int window_height;
	int window_width;
	point clip_position; // clipping position on map

	int width_ratio;
	int height_ratio;

	void set_ratio();
};

#endif
