#include "hot_drink_abstract_factory.hpp"
#include <map>

using namespace std;

class DrinkWithVolumeFactory
{
	map<string, function<unique_ptr<HotDrink>()>> factories;

public:
	DrinkWithVolumeFactory()
	{
		factories["tea"] = []
		{
			auto tea = make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};
		factories["coffee"] = []
		{
			auto tea = make_unique<Coffee>();
			tea->prepare(50);
			return tea;
		};
	}
	unique_ptr<HotDrink> make_drink(const string &name)
	{
		return factories[name]();
	}
};