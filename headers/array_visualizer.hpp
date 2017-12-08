#ifndef ARRAY_VISUALIZER_HPP
#define ARRAY_VISUALIZER_HPP

#include <array>
#include <algorithm>
#include <random>
#include <memory>
#include "line.hpp"

namespace {
	template <class T>
	constexpr T pi = 3.14f;
}

template <int N>
class array_visualizer: public shape {
	static constexpr float data_scaling = 7.5f;
	static constexpr float margin_coef = 10.0f;
	
	const std::shared_ptr<std::array<int, N>> data_m;
	std::array<line, N> lines;

public:
	array_visualizer(const std::shared_ptr<std::array<int, N>>& data, coord pos = coord{100, 100});
	virtual void draw() noexcept override;

protected:
	int fixed_line_length(size_t data_index) const noexcept;
};


//////////////////////////////////////////////////////////
// -- implementation --
template <int N>
array_visualizer<N>::array_visualizer(const std::shared_ptr<std::array<int, N>>& data, coord pos): 
	shape(pos, 0), data_m{data} {

	for (size_t i=0; data_m->size() > i; ++i) {
		data_m->at(i) = static_cast<int>(i);
	}
	std::shuffle(data->begin(), data->end(), std::mt19937{std::random_device{}()});
    for (size_t i=0; lines.size() > i; ++i) {
        lines.at(i).set_coord(coord(pos.first+static_cast<int>(i*margin_coef), pos.second));
        lines.at(i).set_angle(-pi<float>/2);
        lines.at(i).set_length(fixed_line_length(i));
    }
}

template <int N>
void array_visualizer<N>::draw() noexcept {
	for(unsigned i = 0; i < N; ++i) {
		lines.at(i).set_length(fixed_line_length(i));
		lines.at(i).set_rgb(r, g, b);
		lines.at(i).draw();
	}
}

template <int N>
int array_visualizer<N>::fixed_line_length(size_t data_index) const noexcept {
	return static_cast<int>(data_m->at(data_index)*data_scaling);
}

#endif // ARRAY_VISUALIZER_HPP
