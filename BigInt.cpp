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

//deprecated
BigInt::BigInt(char* str) {
	// TODO Auto-generated constructor stub
	int length = strlen(str);
	//if the length is bigger than the maximum length, throw error
	if (strlen(str) > MAXLENGTH) {
		throw "Value is too large. Maximum value is 32^100 \n";
	}
	//Save all digits in array
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

/*
 * Deprecated, updated function is add.
 */
BigInt BigInt::operator+(const BigInt& b) {
	BigInt c;
	for (int i = 0; i < this->lengthBase10; i++) {
		c.numberBase10[i] = this->numberBase10[i] + b.numberBase10[i];
		if (i < MAXLENGTH) {
			c.numberBase10[i + 1] = c.numberBase10[i] / 10;
			c.numberBase10[i] = c.numberBase10[i] % 10;
		}
		//std::cout << this->number[i] << " - " << b.number[i] << "\n";
	}

	c.checkLength();
	return c;
}

//haven't figured the operator overloading out, so returning to what I know to check/optimize the algorithm
/*
 * Adds 2 Bigintegers together
 */
void BigInt::add(const BigInt& b) {
	//Check which number is the biggest, length of the loop based on the outcome
	int length = (
			this->lengthBase10 > b.lengthBase10 ?
					this->lengthBase10 : b.lengthBase10);
	//for each digit, add the corresponding significant digit to the digit,
	//if it's bigger than 10, add to the more significant digit and do modulo 10
	for (int i = 0; i < length; i++) {
		this->numberBase10[i] = this->numberBase10[i] + b.numberBase10[i];
		if (i < MAXLENGTH) {
			this->numberBase10[i + 1] += this->numberBase10[i] / 10;
			this->numberBase10[i] = this->numberBase10[i] % 10;
		}
	}

	checkLength();
}

/*
 * Method to subtract 2 bigintegers
 */
void BigInt::subtract(const BigInt& b) {
	int compare = this->compare(b);

	/*
	 * If the number to subtract is bigger, throw an error.
	 * If the number is equal, the result will be 0, so reset 'this' and return
	 */
	if (compare == 2) {
		throw "Number to subtract is too big. BigInt is not built for negative numbers";
	} else if (compare == 0) {
		this->resetToZero();
		return;
	}

	/*
	 * Starting from the least significant digit, subtract each digit from it's corresponding significant digit
	 * subtracting digit is bigger than the current digit, lend 10 from the more significant digit.
	 */
	for (int i = 0; i < this->lengthBase10; i++) {
		if (this->numberBase10[i] < b.numberBase10[i]) {
			this->numberBase10[i + 1] -= 1;
			this->numberBase10[i] += 10;
		}
		this->numberBase10[i] -= b.numberBase10[i];
	}

	checkLength();
}

//Multiplying algorithm
void BigInt::multiply(const BigInt& b) {
	BigInt temp;
	//int length = (this->lengthBase10 > b.lengthBase10 ? this->lengthBase10 : b.lengthBase10);

	/*
	 *Double loop that multiplies each digit with eachother and saves the result in an array
	 */
	for (int i = 0; i < this->lengthBase10; i++) {
		for (int j = 0; j < b.lengthBase10; j++) {
			temp.numberBase10[j + i] += this->numberBase10[i]
					* b.numberBase10[j];
		}
	}

	/*
	 * Normalises the array to base 10
	 */
	for (int i = 0; i < MAXLENGTH; i++) {
		if (i < MAXLENGTH) {
			temp.numberBase10[i + 1] += temp.numberBase10[i] / 10;
			temp.numberBase10[i] = temp.numberBase10[i] % 10;
		}
	}

	checkLength();
}

/*
 * Method to shift the complete number 1 position to the more significant side.
 * 999 becomes 9990
 *
 * Addition is the number that is put in the space that frees up at the end of the number
 * This number will be done modulo the base.
 */
void BigInt::shiftMoreSignificant(int addition) {
	addition %= 10;
	for (int i = MAXLENGTH - 1; i > 0; i--) {
		this->numberBase10[i] = this->numberBase10[i - 1];
	}
	this->numberBase10[0] = addition;
	this->lengthBase10++;
}

void BigInt::checkLength() {
	//Check the new length of the number
	for (int i = MAXLENGTH - 1; i >= 0; i--) {
		if (this->numberBase10[i] != 0) {
			this->lengthBase10 = i + 1;
			return;
		}
	}
}

/*
 * Division algorithm
 * Divide 'this' by 'b'
 */
void BigInt::divide(const BigInt& b) {
	int compare = this->compare(b);

	/*
	 * If the number to divide is bigger, throw an error.
	 * If the number is equal, the result will be 1, so set 'this' and return
	 */
	if (compare == 2) {
		throw "Number to divide is too big. BigInt is not built for decimal numbers";
	} else if (compare == 0) {
		this->init("1");
		return;
	}
	BigInt temp; //Contains the smallest number divisible by divisor
	BigInt result; //Contains the result in opposite direction. Most significant digit = 0;
	result.lengthBase10 = 1;
	int counterResult = 0; //Contains counter for the position in the result
	int counterThis = this->lengthBase10 - 1; //Contains counter for the position in 'this' bigint

	//add first number to temp
	temp.numberBase10[0] = this->numberBase10[counterThis];	//placeholder for the current number to divide
	temp.lengthBase10 = 1;
	counterThis--;

	//While the divisor is bigger than temp, add numbers.
	while (temp.compare(b) == 2) {
		temp.shiftMoreSignificant(this->numberBase10[counterThis]);
		counterThis--;
	}

	temp.print("Temp first");

	/*
	 * Until the full BigInt is added to the temp variable,
	 * divide by subtraction.
	 *
	 * When temp is smaller than the divisor, add a number and
	 * do it again.
	 */
	while (counterThis >= 0) {
		temp.subtract(b);
		result.numberBase10[0] += 1;

		temp.print("Temp ");
		result.print("Result ");
		std::cout << "counterThis :" << counterThis << "\n";

		//When this BigInt is empty and subtraction is at an end, break loop
		if (temp.compare(b) == 2 && counterThis < 0) {
			result.print("result finished");
			break;
		}
		if (temp.compare(b) == 2) {
			std::cout << "shift" << counterThis;
			temp.print("Temp Shift");
			result.print("Result Shift");
			temp.shiftMoreSignificant(this->numberBase10[counterThis]);
			result.shiftMoreSignificant(0);
			counterThis--;
		}
	}
	std::cout << "Division done, rest is";
	temp.print("");
	std::cout << "Division done, result is";
	result.print("");
	this->copy(result);
	//checkLength();
}

/*
 * Division algorithm
 * Divide 'this' by 'b'
 */
void BigInt::divide2(const BigInt& b) {
	int compare = this->compare(b);

	/*
	 * If the number to divide is bigger, throw an error.
	 * If the number is equal, the result will be 1, so set 'this' and return
	 */
	if (compare == 2) {
		throw "Number to divide is too big. BigInt is not built for decimal numbers";
	} else if (compare == 0) {
		this->init("1");
		return;
	}
	BigInt temp; //Contains the smallest number divisible by divisor
	BigInt result; //Contains the result in opposite direction. Most significant digit = 0;
	result.lengthBase10 = 1;
	int counterResult = 0; //Contains counter for the position in the result
	int counterThis = this->lengthBase10 - 1; //Contains counter for the position in 'this' bigint

	//While the divisor is bigger than temp, add numbers.
	while (temp.compare(b) == 2) {
		temp.shiftMoreSignificant(this->numberBase10[counterThis]);
		counterThis--;
	}

	while (temp.compare(b) != 2) {
		temp.subtract(b);
		result.numberBase10[0] += 1;
		temp.print("Remainder first");
	}
	while (counterThis >= 0) {
		result.shiftMoreSignificant(0);
		temp.shiftMoreSignificant(this->numberBase10[counterThis]);
		temp.print("Temp");
		result.print("Result");
		counterThis--;
		while (temp.compare(b) != 2) {
			temp.subtract(b);
			result.numberBase10[0] += 1;
			std::cout << counterThis;
			temp.print(" Remainder");
		}
	}
	temp.print("Remainder");
	result.print("Result");
	this->copy(result);
}

/*
 * Comparing algorithm
 * Returns 0 if they are equal
 * Returns 1 if the object on which the function is called is bigger
 * Returns 2 if the parameter object is bigger
 */
int BigInt::compare(const BigInt& b) {
	if (this->lengthBase10 > b.lengthBase10) {
		return 1;
	} else if (this->lengthBase10 < b.lengthBase10) {
		return 2;
	} else {
		//Starting a loop from the most significant digit.
		//The length of "this" can be used because both lengths
		//are equal at this stage
		for (int i = this->lengthBase10; i >= 0; i--) {
			if (this->numberBase10[i] > b.numberBase10[i]) {
				return 1;
			} else if (this->numberBase10[i] < b.numberBase10[i]) {
				return 2;
			}
		}
	}
	//if the function reaches this point both are equal
	return 0;
}

/*
 *
 */
void BigInt::copy(BigInt b) {
	for (int i = 0; i < MAXLENGTH; i++) {
		this->numberBase10[i] = b.numberBase10[i];
	}
	this->lengthBase10 = b.lengthBase10;
}

/*
 *
 */
void BigInt::copyReverse(BigInt b) {
	b.print("Reverse b");
	this->print("Reverse this");
	this->resetToZero();
	for (int i = 0; i < b.lengthBase10; i++) {
		this->numberBase10[i] = b.numberBase10[this->lengthBase10 - 1 - i];
	}
	this->lengthBase10 = b.lengthBase10;
}

/*
 * Initialize the value in base 10. Saved in an array of length 150
 * This can and will be optimized, but for testing and developing purposes
 * base 10 is easier to work with for the basic algorithms.
 */
void BigInt::resetToZero() {
	int length = 0;
	for (int i = 0; i < MAXLENGTH; i++) {
		this->numberBase10[i] = 0;
	}
}

/*
 * Initialize the value in base 10. Saved in an array of length 150
 * This can and will be optimized, but for testing and developing purposes
 * base 10 is easier to work with for the basic algorithms.
 */
void BigInt::init(char* str) {
	int length = strlen(str);
	if (strlen(str) > 150) {
		throw "Value is too large. Maximum value is 32^100 \n";
	}

	for (int i = 0; i < length; i++) {
		//check whether it's a number or not
		int asci = str[i];
		if (asci < 48 || asci > 57) {
			throw "NaN";
		}
		// - 0 because otherwise it will store the ASCII value
		//by subtracting the ASCII of '0' it'll store the real int value
		this->numberBase10[i] = str[length - 1 - i] - '0';
	}
	this->lengthBase10 = length;
}

void BigInt::print(char* str) {
	std::cout << str << " in base10 : ";
	for (int i = this->lengthBase10 - 1; i >= 0; i--) {
		std::cout << this->numberBase10[i] << "";
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

}// END NAMESPACE GRAHAM
