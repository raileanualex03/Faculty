# pragma once

# include "Star.h"
# include "Controller.h"
#include <cassert>

void testAddRepository() {
	remove("test.txt");
	Star s{ "star", "constellation", 10, 10, 20 };
	Repository<Star> r{ "test.txt" };
	r.add(s);
	assert(r.getSize() == 1);
	r.remove(s);
	assert(r.getSize() == 0);
	r.add(s);
	try {
		r.add(s);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void testAddController()
{
	remove("starsTest.txt");
	remove("astronomersTest.txt");
	Repository<Star> rS{ "starsTest.txt" };
	Repository<Astronomer> rA{ "astronomersTest.txt" };
	Controller c{ rA, rS };
	c.addStar("alex", "constellation", "10", "20", "30");
	assert(c.getStars().size() == 1);

	try {
		c.addStar("alex", "constellation", "10", "20", "30");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
	try {
		c.addStar("alexds", "constellation", "10", "20", "-1");
		assert(false);
	}
	catch (...) {
		assert(true);
	}

	
}