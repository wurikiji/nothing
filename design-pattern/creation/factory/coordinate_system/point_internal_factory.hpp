#include <cmath>

// Easy to access private members
// It's good to use when the factory only depends on
// one class.
// And also it's useful to imply auto-completion,
// when user types `Point::`.
struct Point
{
private:
	Point(float x, float y) : x{x}, y{y} {}

	struct PointFactory
	{
	private:
		PointFactory() {}

	public:
		static Point NewCartesian(float x, float y)
		{
			return {x, y};
		}
		static Point NewPolar(float x, float y)
		{
			return {r * cos(theta), r * siin(theta)};
		}
	};

public:
	float x, y;
	static PointFactory Factory;
};

// Create `Point` using
// `Point::Factory.NewCartesian()`
