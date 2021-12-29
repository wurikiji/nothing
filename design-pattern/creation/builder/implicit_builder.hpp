#include "string"
#include <vector>
#include <memory>
#include <sstream>

using namespace std;
struct HtmlBuilder;

struct HtmlElement
{
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;
	friend class HtmlBuilder;
	// 사용자가 사용할 빌더
	static unique_ptr<HtmlBuilder> build(const string &root_name)
	{
		return make_unique<HtmlBuilder>(root_name);
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

protected:
	// 생성자를 숨겨서 강제로 builder 를 호출하게 만듬.
	HtmlElement() {}
	HtmlElement(const string &name, const string &text)
			: name{name}, text{text} {}
};

struct HtmlBuilder
{
	HtmlElement root;
	HtmlBuilder(string root_name) { root.name = root_name; }

	operator HtmlElement() const { return root; }

	HtmlBuilder &add_child(string child_name, string child_text)
	{
		HtmlElement e{child_name, child_text};
		root.elements.emplace_back(e);
		return *this;
	}

	string str() { return root.str(); }
};
