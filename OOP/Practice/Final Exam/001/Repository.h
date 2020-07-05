#pragma once
# include <fstream>
# include <vector>
# include <string>
template <typename T>
class Repository
{
private:
	std::string _filename;
public:
	Repository(std::string filename) :_filename{ filename } {};

	void add(T element);

	void remove(T element);

	int getSize();

	std::vector<T> getAll();

};

template<typename T>
inline void Repository<T>::add(T element)
{
	std::vector<T> elems = this->getAll();
	for (auto elem : elems)
		if (elem.toString() == element.toString())
			throw std::exception("already existing element!");
	std::ofstream fout(this->_filename, std::ios::app);
	fout << element.toString() << "\n";
}

template<typename T>
inline void Repository<T>::remove(T element)
{
	std::vector<T> newElems;
	std::vector<T> elems = this->getAll();
	for (T t : elems) {
		if (!(t.toString() == element.toString()))
			newElems.push_back(t);
	}
	if (newElems.size() == elems.size())
		throw std::exception("No element found!");
}

template<typename T>
inline int Repository<T>::getSize()
{
	return this->getAll().size();
}

template<typename T>
inline std::vector<T> Repository<T>::getAll()
{
	T t;
	std::vector<T> elems;
	std::ifstream fin(this->_filename);
	std::vector<std::string> lines;
	while (fin >> t) {
		elems.push_back(t);
	}

	return elems;
}
