/*
 * TestClass.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: lonefish
 */

#include "TestClass.h"
//Include Graham header
#include "Graham.h"
#include <iostream>

/*
 * TODO
 * Check input for numbers only
 * Fix constructor/init method
 * Convert input to base 32
 * Try vector maybe?
 * malloc to make a dynamic array
 * bigint in different bases, standard 32
 */


int main() {
	Stopwatch s;
	s.startClock();
	Graham::BigInt z;
	z.init("11");
	Graham::BigInt y;
	y.init("9999");
	z.print("z");
	y.print("y");
	y.divide2(z);

	z.print("z");
	y.print("y");
	s.stopClock();
	std::cout << "Time taken in ms :" << s.difference();
	return 0;

}

TestClass::TestClass() {
	// TODO Auto-generated constructor stub

}

TestClass::~TestClass() {
	// TODO Auto-generated destructor stub
}

