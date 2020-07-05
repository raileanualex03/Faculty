#include <string>
#include <iostream>



class Beverage {
	std::string description;
public:
	Beverage() { description = ""; };
	Beverage(std::string d) :description{ d } {};
	virtual double price() = 0;
	virtual void print() {
		std::cout << description << "-> " << std::to_string(price()) << "\n";
	};
};


class Coffee : public Beverage
{
public:
	Coffee() : Beverage{ "Coffee" } {};
	double price() override {
		return 2.5;
	};

};

class Tea : public Beverage
{
public:
	Tea() : Beverage{ "Tea" } {};
	double price() override {
		return 1.5;
	}
};

class BeverageWithMilk : public Beverage
{
	int milkCount;
	Beverage* beverage;
public:
	BeverageWithMilk(int milkCount, Beverage* b) : beverage{b}, milkCount{ milkCount } {};
	double price() override {
		return beverage->price() + 0.5 * milkCount;
	};
	void print() override {
		beverage->print();
		std::cout << "with " << milkCount << "milk: ";
	}
};


class BeverageMachine {
public:
	BeverageMachine() {};
	void prepare(std::string beverageType, int milkCount) {
		if (beverageType == "Coffee") {
			Beverage* b = new Coffee();
			BeverageWithMilk* bm = new BeverageWithMilk(milkCount, b);

			bm->print();
			std::cout << bm->price() << "RON \n";
		}
		else if (beverageType == "Tea") {
			Beverage* b = new Tea();
			BeverageWithMilk* bm = new BeverageWithMilk(milkCount, b);
			bm->print();
			std::cout << bm->price() << "RON \n";
		}
		else
			std::cout << "Wrong type received!\n";
	}
};


int main()
{
	BeverageMachine bm{};
	bm.prepare("Tea", 0);
	bm.prepare("Coffee", 1);
	bm.prepare("Coffee", 2);
	return 0;
}