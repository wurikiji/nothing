#include "better_copy_constructor.hpp"

#include <cstdio>

int main()
{
	Contact worker1{"", new Address{"123 East Dr", "London", 0}};
	Contact worker2 = worker1;
	worker2.address->suite = 1;
	printf("Worker1 Room No: %d\n", worker1.address->suite);
	printf("Worker2 Room No: %d\n", worker2.address->suite);
	Contact worker3{worker2};
	worker3.address->suite = 3;
	printf("Worker3 Room No: %d\n", worker3.address->suite);
}