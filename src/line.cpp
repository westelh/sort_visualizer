#include <cmath>
#include "line.hpp"
#include "allegro5/allegro_primitives.h"

line::line(coord position, float rad, int len): shape(position, rad), length{len} {

}

void line::draw() noexcept {
	al_draw_line(pos.first, pos.second, 
		pos.first+length.load()*std::cos(rad.load()), 
		pos.second+length.load()*std::sin(rad.load()), 
		al_map_rgb(static_cast<unsigned char>(r),
					static_cast<unsigned char>(g),
					static_cast<unsigned char>(b)), 5);
}

void line::set_length(int len) noexcept {
	length.store(len);
}

int line::get_length() const noexcept {
	return length.load();
}