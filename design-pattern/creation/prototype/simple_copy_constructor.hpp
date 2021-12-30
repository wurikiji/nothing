#ifndef COPY_CONSTRUCTOR_HPP
#define COPY_CONSTRUCTOR_HPP

#include <string>

using namespace std::string;

struct Address
{
	string street, city;
	int suite;
	Address(const string &street, const string &city, const int suite)
			: street{street}, city{city}, suite{suite}
	{
	}
};

struct Contact
{
	string name;
	Address *address;

	// **PROBLEM**
	// Can't adjust to the change of the members in `struct Address`
	Contact(const Contact &other) : name{other.name}
	{
		address = new Address(
				other.address->street,
				other.address->city,
				other.address->suite);
	}
};

#endif