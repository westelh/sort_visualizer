#include "shape.hpp"

coord pos(int x, int y) {
	return coord{x, y};
}

shape::shape(coord position, float rad, int red, int green, int blue): rad{rad}, pos{position},
	r{red}, g{green}, b{blue} {
	
}

void shape::set_coord(const coord& c) noexcept {
	pos = c;
}

void shape::set_coord(int x, int y) noexcept {
	pos.first = x;
	pos.second = y;
}

coord shape::get_coord() const noexcept {
	return pos;
} 

void shape::set_angle(float r) noexcept {
	rad.store(r);
}

float shape::get_angle() const noexcept {
	return rad.load();
}

void shape::set_rgb(int red, int green, int blue) noexcept {
	r = red;
	g = green;
	b = blue;
}