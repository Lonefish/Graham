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
		//number[i] = str[i];
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
		c.number[i] = this->number[i] + b.number[i];
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
		this->number[i] = str[i] - '0';
	}
	this->length = length;
	//std::cout << "\n";
}

void BigInt::print() {
	for (int i = 0; i < this->length; i++) {
		std::cout << this->number[i] << "-";
	}
	std::cout << "\n";
}

} // END NAMESPACE GRAHAM
