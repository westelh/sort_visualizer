#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <map>
#include <atomic>

class shape {
public:
	using coord = std::pair<float, float>;
protected:
	std::atomic<float> rad;
	coord pos;

public:
	shape(coord position = std::make_pair(0, 0), float radian = 0);
	virtual ~shape() = default;

	void set_coord(const coord& c) noexcept;
	void set_coord(float x, float y) noexcept;
	coord get_coord() const noexcept;

	void set_angle(float r) noexcept;
	float get_angle() const noexcept;

	virtual void draw() noexcept = 0;
};

#endif // SHAPE_HPP