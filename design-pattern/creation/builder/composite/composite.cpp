#include "person.hpp"
#include "person_builder.hpp"
#include "person_address_builder.hpp"
#include "person_job_builder.hpp"

int main()
{
	Person p = Person::create().lives().at("jj").with_postcode("399").in("kjkj").works().at("jjj").as_a("programmer").earning(10e7);

	return 0;
}