#include <string>
#include <vector>
#include <iostream>


class Activity
{
public:
    std::string _text;
    std::string _hour;
    Activity(std::string t, std::string h) : _text{ t }, _hour{ h }{};
    friend std::ostream& operator<<(std::ostream& os, Activity a);
};

std::ostream& operator<<(std::ostream& os, Activity a) {
    os << a._text << " " << a._hour;
    return os;
}
template <typename T>
class ToDo
{
public:
    std::vector<T> elems;
    ToDo() {};
    ToDo& operator+ (T a) {
        elems.push_back(a);
        return (*this);
    }

    auto begin() {
        return elems.begin();
    }

    auto end() {
        return elems.end();
    }

    std::ostream& reversePrint(std::ostream& os) {
        for (int i = elems.size() - 1; i >= 0; i--)
        {
            os << elems[i]<<"\n";
        }
        return os;
    }
   

};

void ToDoList()
{
    ToDo<Activity> todo{};
    Activity tiff{ "go to TIFF movie", "20:00" };
    todo = todo + tiff;
    Activity project{ "present project assignment", "09.20" };
    todo = todo + project;

    // iterates through the activities and prints them as follows:
    // Activity present project assignment will take place at 09.20.
    // Activity go to TIFF movie will take place at 20.00.
    for (auto a : todo)
        std::cout << a << '\n';

    // Prints the activities as follows:
    // Activity go to TIFF movie will take place at 20.00.
    // Activity present project assignment will take place at 09.20.
    todo.reversePrint(std::cout);
}
//
//int main()
//{
//    ToDoList();
//
//
//	return 0;
//}