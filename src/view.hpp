#ifndef _VIEW_H
#define _VIEW_H

#include "point.hpp"

class view {
public:
	// Constructor
	view();
	view(int height, int width, point position);

	// Setter and getter
	int get_width() const;
	int get_height() const;
	point get_position() const;
	void set_width(int width);
	void set_height(int height);
	void set_position(int x, int y);

	// Transformation
	void scroll(char direction);
	void zoom(char direction);

private:
	int height;
	int width;
	int window_height;
	int window_width;
	point position;
};

#endif
