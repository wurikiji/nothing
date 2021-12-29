#include <cmath>

enum class PointType
{
	cartesian,
	polar,
};

struct Point
{
	// with orthogonal coordinate system
	Point(const float x, const float y)
			: x{x}, y{y} {}
	float x, y;

	// BAD: with polar coordinate system
	// Can not determine what to use when build `Point`
	// because an orthogonal constructor also has a
	// same interface with this constructor.
	Point(const float r, const float theta)
	{
		x = r * cos(theta);
		y = r * sin(theta);
	}

	// BAD: with enumeration to distinguish construction
	// Can not imply the meaning of arguments.
	Point(float a, float b, PointType type = PointType::cartesian)
	{
		if (type == PointType::cartesian)
		{
			x = a;
			y = b;
		}
		else
		{
			x = a * cos(b);
			y = a * sin(b);
		}
	}
};