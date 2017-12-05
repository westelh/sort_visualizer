#ifndef LINE_HPP
#define LINE_HPP

#include <atomic>
#include "shape.hpp"

class line: public shape {
	std::atomic<float> length;
public:
	line(coord position = std::make_pair(300, 300), float radian = 0, float len = 500);

	virtual void draw() noexcept override;
	void set_length(float len) noexcept;
	float get_length() const noexcept;
};

#endif // LINE_HPP
