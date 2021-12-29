#include "groovy.hpp"
#include <iostream>
using namespace std;
int main()
{
	cout << P{
							IMG{"http://pokemon.com/pikachu.png"}}
			 << endl;
	return 0;
}