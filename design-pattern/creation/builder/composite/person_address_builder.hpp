#include <string>
#include "person.hpp"
#include "person_builder.hpp"

class PersonAddressBuilder : public PersonBuilderBase
{
	typedef PersonAddressBuilder self;

public:
	explicit PersonAddressBuilder(Person &person) : PersonBuilderBase(person) {}
	self &at(std::string street_address)
	{
		person.street_address = street_address;
		return *this;
	}
	self &with_postcode(std::string post_code)
	{
		person.post_code = post_code;
		return *this;
	}
	self &in(std::string city)
	{
		person.city = city;
		return *this;
	}
};
