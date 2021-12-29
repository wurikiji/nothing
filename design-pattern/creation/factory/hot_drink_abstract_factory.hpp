#include <iostream>
#include <map>

using namespace std;
struct HotDrink
{
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	void prepare(int volume) override
	{
		cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << endl;
	}
};

struct Coffee : HotDrink
{
	void prepare(int volume) override
	{
		cout << "Take coffee bag, boil water, pour " << volume << "ml, add some milk" << endl;
	}
};

struct HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};

struct CoffeeFactory : HotDrinkFactory
{
	unique_ptr<HotDrink> make() const override
	{
		return make_unique<Coffee>();
	}
};

struct TeaFactory : HotDrinkFactory
{
	unique_ptr<HotDrink> make() const override
	{
		return make_unique<Tea>();
	}
};

class DrinkFactory
{
	map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
	DrinkFactory()
	{
		hot_factories["coffe"] = make_unique<CoffeeFactory>();
		hot_factories["tea"] = make_unique<TeaFactory>();
	}

	unique_ptr<HotDrink> make_drink(const string &name)
	{
		auto drink = hot_factories[name]->make();
		drink->prepare(200);
		return drink;
	}
};
