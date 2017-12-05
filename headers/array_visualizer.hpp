#ifndef ARRAY_VISUALIZER_HPP
#define ARRAY_VISUALIZER_HPP

#include <array>
#include <algorithm>
#include <random>
#include "line.hpp"

namespace {
	template <class T>
	constexpr T pi = 3.14f;
}

template <int N>
class array_visualizer: public shape {
	static constexpr float data_scaling = 7.5f;
	static constexpr float margin_coef = 10.0f;

	class data_elem {
		int *const dataref;
		line *const lineref;
	public:
		data_elem(int *const d, line *const l);
	 	data_elem& operator=(int i);
	 	data_elem& operator=(const data_elem& d);
	 	operator int() const noexcept;
	};

	std::array<int, N> data;
	std::array<line, N> lines;

public:
	array_visualizer(coord pos = coord{100, 100});
	virtual void draw() noexcept override;

	data_elem at(size_t i);
	data_elem operator[](size_t i);
};


//////////////////////////////////////////////////////////
// -- implementation --
template <int N>
array_visualizer<N>::array_visualizer(coord pos): shape(pos, 0) {
	for (size_t i=0; data.size() > i; ++i) {
		data.at(i) = static_cast<int>(i);
	}
	std::shuffle(data.begin(), data.end(), std::mt19937{std::random_device{}()});
    for (size_t i=0; lines.size() > i; ++i) {
        lines.at(i).set_coord(coord(pos.first+static_cast<int>(static_cast<int>(i)*margin_coef), pos.second));
        lines.at(i).set_angle(-pi<float>/2);
        lines.at(i).set_length(static_cast<int>(data.at(i)*data_scaling));
    }
}

template <int N>
void array_visualizer<N>::draw() noexcept {
	for (auto&& i : lines) {
		i.set_rgb(r, g, b);
		i.draw();
	}
}

template <int N>
typename array_visualizer<N>::data_elem array_visualizer<N>::at(size_t i) {
	return data_elem{&data.at(i), &lines.at(i)};
}

template <int N>
typename array_visualizer<N>::data_elem array_visualizer<N>::operator[](size_t i) {
	return at(i);
}

template <int N>
array_visualizer<N>::data_elem::data_elem(int *const d, line *const l): dataref{d}, lineref{l} { }

template <int N>
typename array_visualizer<N>::data_elem& array_visualizer<N>::data_elem::operator=(int i) {
	*dataref = i;
	lineref->set_length(static_cast<int>(i*data_scaling));
	return *this;
}

template <int N>
typename array_visualizer<N>::data_elem& array_visualizer<N>::data_elem::operator=(const data_elem& d) {
	*dataref = static_cast<int>(d);
	lineref->set_length(static_cast<int>(static_cast<int>(d)*data_scaling));
	return *this;
}

template <int N>
array_visualizer<N>::data_elem::operator int() const noexcept {
	return *dataref;
}

#endif // ARRAY_VISUALIZER_HPP
