#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <map>
#include <atomic>

using coord = std::pair<int, int>;
coord pos(int x, int y);

class shape {
protected:
	std::atomic<float> rad;
	coord pos;
	int r, g, b;

public:
	shape(coord position = coord{0, 0}, float radian = 0, int red = 255, int green = 0, int blue = 0);
	virtual ~shape() = default;

	void set_coord(const coord& c) noexcept;
	void set_coord(int x, int y) noexcept;
	coord get_coord() const noexcept;

	void set_angle(float r) noexcept;
	float get_angle() const noexcept;

	void set_rgb(int red, int green, int blue) noexcept;

	virtual void draw() noexcept = 0;
};

#endif // SHAPE_HPP