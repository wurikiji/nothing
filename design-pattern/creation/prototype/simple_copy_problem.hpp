#ifndef SIMPLE_COPY_PROBLEM_HPP
#define SIMPLE_COPY_PROBLEM_HPP

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
	// **BAD**
	// When copy from others, all of the insatnace will point same memory address.
	Address *address;
};

#endif