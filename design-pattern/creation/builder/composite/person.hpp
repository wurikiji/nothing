#pragma once
#ifndef MY_PERSON_H
#define MY_PERSON_H

#include <string>

class PersonBuilderBase;
class PersonBuilder;
class PersonJobBuilder;
class PersonAddressBuilder;

class Person
{
	std::string street_address, post_code, city;
	std::string company_name, position;
	int annual_income = 0;

	explicit Person() {}

public:
	static PersonBuilder create();
	friend class PersonBuilder;
	friend class PersonBuilderBase;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
};

#endif