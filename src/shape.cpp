#include "shape.hpp"

shape::shape(coord position, float rad): rad{rad}, pos{position} {
	
}

void shape::set_coord(const coord& c) noexcept {
	pos = c;
}

void shape::set_coord(float x, float y) noexcept {
	pos.first = x;
	pos.second = y;
}

shape::coord shape::get_coord() const noexcept {
	return pos;
} 

void shape::set_angle(float r) noexcept {
	rad.store(r);
}

float shape::get_angle() const noexcept {
	return rad.load();
}