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
	//Graham::BigInt* a = new Graham::BigInt("1236");
	//Graham::BigInt* b = new Graham::BigInt("1111");
	//std::cout << "test";
	Graham::BigInt z;
	z.init("99999");
	//std::cout << "test";
	Graham::BigInt y;
	y.init("111");
	Graham::BigInt x;


	y.print("y");
	y.multiply(z);
	z.print("z");
	y.print("y");


	return 0;

}

TestClass::TestClass() {
	// TODO Auto-generated constructor stub

}

TestClass::~TestClass() {
	// TODO Auto-generated destructor stub
}

