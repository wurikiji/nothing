
#ifndef SIMPLE_COPY_HPP
#define SIMPLE_COPY_HPP

#include <string>
using namespace std;
struct Address
{
	string street, city;
	int suite;
};

struct Contact
{
	string name;
	Address address;
};

void copyExample()
{
	Contact worker{"", Address{"123 East Dr", "London", 0}};
	Contact worker2 = worker;
	worker2.address.suite = 1;
}

#endif