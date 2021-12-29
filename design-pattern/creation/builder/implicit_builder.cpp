#include "implicit_builder.hpp"
#include <iostream>

using namespace std;
int main()
{
	HtmlElement e = (HtmlElement::build("ul")->add_child("li", "hello")).add_child("li", "world");
	cout << e.str() << endl;
	return 0;
}