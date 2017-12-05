#include <cmath>
#include "line.hpp"
#include "allegro5/allegro_primitives.h"

line::line(coord position, float rad, float len): shape(position, rad), length{len} {

}

void line::draw() noexcept {
	al_draw_line(pos.first, pos.second, 
		pos.first+length.load()*std::cos(rad.load()), 
		pos.second+length.load()*std::sin(rad.load()), 
		al_map_rgb(255, 0, 0), 5);
}

void line::set_length(float len) noexcept {
	length.store(len);
}

float line::get_length() const noexcept {
	return length.load();
}