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
	std::cout << "test\n";
	//Graham::BigInt* a = new Graham::BigInt("1236");
	//Graham::BigInt* b = new Graham::BigInt("1111");
	Graham::BigInt a;
	a.init("123");
	Graham::BigInt z;
	z.init("4294967299");
	Graham::BigInt y;
	y.init("111111111");
	Graham::BigInt x;
	x = y + z;
	x.print();
	a.print();
	z.print();
	y.print();
	return 0;
}

TestClass::TestClass() {
	// TODO Auto-generated constructor stub

}

TestClass::~TestClass() {
	// TODO Auto-generated destructor stub
}

