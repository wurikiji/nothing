#include "html_element.hpp"
struct HtmlBuilder
{
	HtmlElement root;
	HtmlBuilder(string root_name) { root.name = root_name; }

	void add_child(string child_name, string child_text)
	{
		HtmlElement e{child_name, child_text};
		root.elements.emplace_back(e);
	}

	string str() { return root.str(); }
};