
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <cassert>

using namespace std;
void handmadeTest() {
	Matrix m = Matrix(10, 10);
	 m.modify(1, 0, 100);
	 m.modify(0, 1, 200);
	 m.modify(2, 0, 300);
	 m.modify(3, 0, 500);
	
	m.transpose();
	assert(m.element(0, 1) == 200);
	assert(m.element(1, 0) == 100);
	std::cout << "handmadeTest passed \n";

}

int main() 
{

	handmadeTest();
	testAll();
	testAllExtended();
	cout << "Test End" << endl;
	system("pause");
}