#include <string>
#include "person.hpp"
#include "person_builder.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
	typedef PersonJobBuilder self;

public:
	explicit PersonJobBuilder(Person &person) : PersonBuilderBase(person) {}
	self &at(std::string company_name)
	{
		person.company_name = company_name;
		return *this;
	}
	self &as_a(std::string job_name)
	{
		person.position = job_name;
		return *this;
	}
	self &earning(int earning)
	{
		person.annual_income = earning;
		return *this;
	}
};