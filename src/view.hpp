#ifndef _VIEW_H
#define _VIEW_H

#include "point.hpp"
#include "line.hpp"
#include <vector>

class view {
public:
	// Constructor
	view();
	view(int height, int width, point position, point clip_position);
	view(int height, int width, point position, point clip_position, float scale);
	view(int height, int width, int xpos, int ypos);

	// Setter and getter
	int get_width() const;
	int get_height() const;
	
	point get_position() const;
	
	void set_width(int width);
	void set_height(int height);
	void set_position(int x, int y);

	void add_line(line l);

	void draw();

	// Transformation
	void scrollz(char direction);
	void zoom(char direction);

private:
	int height;
	int width;
	point position; // view position on screen
	// window = clipped area
	int window_height;
	int window_width;
	point clip_position; // clipping position on map

	std::vector<line> lines;
};

#endif
