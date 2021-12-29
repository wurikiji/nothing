#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct HtmlElement
{
	string name;
	string text;
	vector<HtmlElement> elements;
	HtmlElement() {}
	HtmlElement(const string &name, const string &text) : name(name), text(text)
	{
	}

	string str(int indent = 0) const
	{
		ostringstream oss;
		oss << "<" << name << ">" << text;
		for (auto &w : elements)
		{
			for (int i = 0; i < indent; ++i)
				oss << " ";
			oss << w.str();
		}
		oss << "</" << name << ">";
		return oss.str();
	}
};