#ifndef LINE_HPP
#define LINE_HPP

#include <atomic>
#include "shape.hpp"

class line: public shape {
	std::atomic_int length;
public:
	line(coord position = coord(300, 300), float radian = 0, int len = 500);

	virtual void draw() noexcept override;
	void set_length(int len) noexcept;
	int get_length() const noexcept;
};

#endif // LINE_HPP
