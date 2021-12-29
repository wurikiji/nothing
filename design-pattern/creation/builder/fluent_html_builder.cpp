#include "fluent_html_builder.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	HtmlBuilder builder("ul");
	builder.add_child("li", "hello").add_child("li", "world");
	cout << builder.str() << endl;
	return 0;
}