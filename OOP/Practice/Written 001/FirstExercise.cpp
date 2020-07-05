
#include <cassert>
#pragma once
# include <vector>
# include <iostream>
# include <algorithm>
# include <string>

template <typename T1, typename T2>
bool sortByFirstComponent(std::pair<T1, T2> first, std::pair<T1, T2> second) {
	return first.second < second.second;
};
template <typename T1, typename T2>
class List
{
private:
	std::vector<std::pair<T1, T2>> elements;
public:
	List() {};

	void add(T1 t1, T2 t2) {
		std::pair<T1, T2> p(t1, t2);
		elements.push_back(p);
	};
	void sortByFirstComponent() {
		if (elements.size() == 0) {
			throw std::runtime_error("List is empty!");
		}
		std::sort(elements.begin(), elements.end(), [](std::pair<T1, T2> p1, std::pair<T1, T2> p2) {return p1.first.getNumber() < p2.first.getNumber(); });
	}

	std::ostream& printReverse(std::ostream& os) {
		for (int index = elements.size() - 1; index >= 0; index--) {
			os << elements[index].first.toString() << "->" << std::to_string(elements[index].second) << "\n";
		}
		return os;
	}
	void sortBySecondComponent() {
		if (elements.size() == 0) {
			throw(std::runtime_error("List is empty!"));
		}
		std::sort(elements.begin(), elements.end(), [](std::pair<T1, T2>p1, std::pair<T1, T2> p2) {
			return p1.second < p2.second;
			});
	}


};



class Car
{
	std::string _name;
	int _number;
public:
	Car(std::string name, int number) :_name{ name }, _number{ number }{};
	int getNumber() { return _number; };
	std::string getName() { return _name; };
	std::string toString() {
		std::string s;
		s += std::to_string(_number) + "->";
		s += _name;
		return s;
	}

};



void function1() {
	List<Car, int> list1;
	try {
		list1.sortByFirstComponent();
		assert(false);
	}
	catch (std::runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0); }

	list1.add(Car{ "Audi", 20 }, 8);
	list1.add(Car{ "Volkswagen", 10 }, 9);
	list1.add(Car{ "Bentley", 300 }, 10);

	list1.sortByFirstComponent();
	list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9 
	list1.sortBySecondComponent();
	list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}
//
//int main()
//{
//	function1();
//	return 0;
//}