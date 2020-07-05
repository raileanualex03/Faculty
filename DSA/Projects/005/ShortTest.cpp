#include <assert.h>
#include "Matrix.h"
#include "ShortTest.h"
#include <iostream>

using namespace std;

void handmadeTest()
{
	std::cout << "Test handmade \n";
	Matrix m(10, 10);
	int result = m.modify(1, 1, 2);
	
	assert(result == NULL_TELEM);
}

void testAll() {
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
}