#include "simple_html_builder.hpp"
#include <iostream>

using namespace std;
int main()
{
	HtmlBuilder builder{"ul"};

	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	cout << builder.str() << endl;
	return 0;
}