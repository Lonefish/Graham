/*
 * BigInt.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: lonefish
 */

#include "BigInt.h"
#include <iostream>
#include <string.h>

namespace Graham {

BigInt::BigInt() {
	// TODO Auto-generated constructor stub

}

BigInt::BigInt(char* str) {
	// TODO Auto-generated constructor stub
	int length = strlen(str);
	if (strlen(str) > 150) {
		throw "Value is too large. Maximum value is 32^100 \n";
	}
	for (int i = 0; i < length; i++) {
		std::cout << str[i];
		numberBase2[i] = str[i];
	}
	this->length = length;
	//std::cout << "\n";
}

BigInt::~BigInt() {
	// TODO Auto-generated destructor stub
}

BigInt BigInt::operator+(const BigInt& b) {
	BigInt c;
	//this->print();
	//c.print();
	//b.print();
	for (int i = 0; i < this->length; i++) {
		c.numberBase2[i] = this->numberBase2[i] + b.numberBase2[i];
		//std::cout << this->number[i] << " - " << b.number[i] << "\n";
	}
	//not true, but for testing purposes
	c.length = this->length;
	return c;
}


void BigInt::init(char* str) {
	int length = strlen(str);
	if (strlen(str) > 150) {
		throw "Value is too large. Maximum value is 32^100 \n";
	}
	for (int i = 0; i < length; i++) {
		//std::cout << str[i];
		// - 0 because otherwise it will store the ASCII value
		//by subtracting the ASCII of '0' it'll store the real int value
		this->numberBase2[i] = str[length-1-i] - '0';
	}
	this->length = length;
	//std::cout << "\n";
}

void BigInt::print() {
	for (int i = 0; i < this->length; i++) {
		std::cout << this->numberBase2[i] << "-";
	}
	std::cout << "\n";
}

int BigInt::isDivisibleBy2() {
	return (this->numberBase2[0] % 2 == 0 ? true : false);
}

int BigInt::isDivisibleBy3() {
	return 0;
}

int BigInt::isDivisibleBy4() {
	return 0;
}

int BigInt::isDivisibleBy5() {
	return (this->numberBase2[0] == 0 || this->numberBase2[0] == 5 ? true : false);
}

int BigInt::isDivisibleBy6() {
	return 0;
}

int BigInt::isDivisibleBy7() {
	return 0;
}

int BigInt::isDivisibleBy8() {
	return 0;
}

int BigInt::isDivisibleBy9() {
	return 0;
}

int BigInt::isDivisibleBy10() {
	return (this->numberBase2[0] == 0 ? true : false);
}

void BigInt::base2ToBase32Bit() {
	for(int i = 0; i < this->length; i++) {

	}
}



} // END NAMESPACE GRAHAM
