#include <utility>
#include <string>
#include <vector>
#include <iostream>

struct Tag
{
	std::string name;
	std::string text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

	friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
	{
		os << "<" << tag.name;

		for (auto &a : tag.attributes)
		{
			os << " " << a.first << "=\"" << a.second << "\"";
		}

		os << ">" << tag.text;

		for (auto &t : tag.children)
		{
			os << t;
		}

		os << "</" << tag.name << ">";
		return os;
	}

protected:
	Tag(const std::string &name, const std::string &text) : name{name}, text{text} {}
	Tag(const std::string &name, const std::vector<Tag> &children) : name{name}, children{children} {}
};

struct P : Tag
{
	explicit P(const std::string &text) : Tag{"p", text} {}
	P(std::initializer_list<Tag> children) : Tag("p", children) {}
};

struct IMG : Tag
{
	explicit IMG(const std::string &url) : Tag("img", "")
	{
		attributes.emplace_back(std::make_pair("src", url));
	}
};