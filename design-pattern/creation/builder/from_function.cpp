#include <memory>

class Foo
{
public:
	explicit Foo(int _n) : n{_n} {};
	int n;
};

Foo make_foo(int n)
{
	return Foo{n};
}

std::unique_ptr<Foo> make_foo_smart_ptr(int n)
{
	return std::make_unique<Foo>(n);
}

Foo *make_foo_trivial_pointer(int n)
{
	return new Foo(n);
}

int main()
{
	return 0;
}