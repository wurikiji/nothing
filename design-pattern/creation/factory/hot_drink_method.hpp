#include <iostream>

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

unique_ptr<HotDrink> make_drink(string type)
{
	unique_ptr<HotDrink> drink;
	if (type == "tea")
	{
		drink = make_unique<Tea>();
		drink->prepare(200);
	}
	else
	{
		drink = make_unique<Coffee>();
		drink->prepare(50);
	}
	return drink;
}