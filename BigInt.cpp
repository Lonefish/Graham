/*
 * BigInt.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: lonefish
 */

#include "BigInt.h"
#include <iostream>
#include <string.h>
#include <tgmath.h>

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
		numberBase10[i] = str[i];
	}
	this->lengthBase10 = length;
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
	for (int i = 0; i < this->lengthBase10; i++) {
		c.numberBase10[i] = this->numberBase10[i] + b.numberBase10[i];
		if(i+1 < MAXLENGTH -1) {
			c.numberBase10[i+1] = c.numberBase10[i] / 10;
			c.numberBase10[i] = c.numberBase10[i] % 10;
		}
		//std::cout << this->number[i] << " - " << b.number[i] << "\n";
	}
	//not true, but for testing purposes
	for (int i = MAXLENGTH - 1; i > 0 ; i++) {
		if(c.numberBase10[i] != 0) {
			c.lengthBase10 = i+1;
			return c;
		}
	}

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
		this->numberBase10[i] = str[length - 1 - i] - '0';
	}
	this->lengthBase10 = length;
	//std::cout << "\n";
}

void BigInt::print() {
	std::cout << "Base10 : ";
	for (int i = 0; i < this->lengthBase10; i++) {
		std::cout << this->numberBase10[i] << " ";
	}
	std::cout << "\n";

	/*std::cout << "Base32Bit : ";
	for (int i = 0; i < this->lengthBase32Bit; i++) {
		std::cout << this->numberBase32Bit[i] << " ";
	}
	std::cout << "\n";*/
}

int BigInt::isDivisibleBy2() {
	return (this->numberBase10[0] % 2 == 0 ? true : false);
}

int BigInt::isDivisibleBy3() {
	return 0;
}

int BigInt::isDivisibleBy4() {
	return 0;
}

int BigInt::isDivisibleBy5() {
	return (this->numberBase10[0] == 0 || this->numberBase10[0] == 5 ?
			true : false);
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
	return (this->numberBase10[0] == 0 ? true : false);
}

//Probably buggy, focussing on base 2 first
/*void BigInt::base2ToBase32Bit() {
	long long quotient[150] = { }; //initial value is 0, most significant bit is 0.
	int quotientCounter = 0; //keep track of the spot in the quotient, change in pointer?
	bool quotientIsZero = true;
	int number32bitcounter = 0; // keep track of where we are in the 32bitnumber array, change in pointer?

	//if length of the number is smaller than 2^32, it will always be only 1 'digit'
	if (lengthBase2 < LENGTHBIT32 - 1) {
		long long multiplier = 1; //multiply by 10 for each step
		for (int i = 0; i < lengthBase2; i++) {
			this->numberBase32Bit[0] += this->numberBase2[i] * multiplier;
			multiplier *= 10;
			lengthBase32Bit = 1;
		}
		return;
	}
	//initial division
	long long dividend = 0;
	long long multiplier = 1;
	int quotientLength = 0; //length of the quotient
	int whileCounter = 1; //needed to check where we are in the array, change in pointer?

	//long long division of numberBase2
	while (lengthBase2 - whileCounter >= 0) {
		//form number in int
		while (dividend < BIT32 && lengthBase2 >= whileCounter) {
			dividend *= 10;
			dividend += numberBase2[lengthBase2 - whileCounter];
			whileCounter++;
		}
		quotient[quotientCounter] = dividend / BIT32;

		//if not zero make sure it'll enter the loop
		//else save the dividend, because this is the last value
		if (quotient[quotientCounter] != 0) {
			quotientIsZero = false;
		} else {

			numberBase32Bit[number32bitcounter] += dividend;
			lengthBase32Bit = number32bitcounter + 1;
			return;
		}
		quotientCounter++;
		dividend = dividend % BIT32;
	}
	//form the quotient in base10 form for saving in number32bit array
	multiplier = pow10(quotientCounter - 1);
	quotientLength = quotientCounter + 1;
	while (quotientCounter > 0) {
		quotientCounter--;
		numberBase32Bit[number32bitcounter] += quotient[quotientCounter]
				* multiplier;
		multiplier /= 10;
	}
	number32bitcounter++;

	//loop for next divisions
	while (quotientIsZero != true) {
		quotientIsZero = true;
		whileCounter = 0;
		multiplier = 1;
		dividend = 0;
		while (whileCounter < quotientLength) {
			while (dividend < BIT32) {
				dividend *= 10;
				dividend += quotient[whileCounter];
				whileCounter++;
			}
			quotient[quotientCounter] = dividend / BIT32;
			if (quotient[quotientCounter] != 0) {
				quotientIsZero = false;
			}
			quotientCounter++;
		}
		//form the quotient in base10 form for saving in number32bit array
		multiplier = pow10(quotientCounter - 1);
		while (quotientCounter >= 0) {
			quotientCounter--;
			numberBase32Bit[number32bitcounter] += quotient[quotientCounter]
					* multiplier;
			multiplier /= 10;
			lengthBase32Bit = number32bitcounter + 1;
		}
		number32bitcounter++;
	}
}*/

} // END NAMESPACE GRAHAM
