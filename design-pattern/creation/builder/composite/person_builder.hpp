#pragma once
#include "person.hpp"
class PersonJobBuilder;
class PersonAddressBuilder;

class PersonBuilderBase
{
protected:
	Person &person;
	explicit PersonBuilderBase(Person &person) : person{person}
	{
	}

public:
	operator Person()
	{
		return std::move(person);
	}

	PersonAddressBuilder lives() const;
	PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
	Person p;

public:
	PersonBuilder() : PersonBuilderBase(p) {}
};
