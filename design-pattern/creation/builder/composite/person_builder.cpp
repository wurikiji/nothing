#include "person_builder.hpp"
#include "person_address_builder.hpp"
#include "person_job_builder.hpp"

PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder(person);
}
PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder(person);
}