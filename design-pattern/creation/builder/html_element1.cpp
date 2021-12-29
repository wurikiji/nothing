#include "html_element.hpp"
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string words[] = {"hello", "world"};

	HtmlElement list{"ul", ""};
	for (auto &w : words)
		list.elements.emplace_back(HtmlElement{"li", w});
	printf("%s\n", list.str().c_str());
	return 0;
}