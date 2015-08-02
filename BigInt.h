/*
 * BigInt.h
 *
 *  Created on: Aug 1, 2015
 *      Author: lonefish
 */

#ifndef BIGINT_H_
#define BIGINT_H_

namespace Graham {
class BigInt {
public:
	//start to implement algorithms with fixed maximum size of 32^100. Array in base 32.
	//0 is least significant bit
	int numberBase32Bit[100] = {};
	int numberBase2[100] = {};
	int length = 0;
	BigInt(char* str);
	BigInt();
	void init(char* str);
	void print();
	virtual ~BigInt();
	BigInt operator+(const BigInt& b);
	int isDivisibleBy2();
	int isDivisibleBy3();
	int isDivisibleBy4();
	int isDivisibleBy5();
	int isDivisibleBy6();
	int isDivisibleBy7();
	int isDivisibleBy8();
	int isDivisibleBy9();
	int isDivisibleBy10();
private:
	//const int BIT32 = 4294967296;
	void base2ToBase32Bit();
};


#endif /* BIGINT_H_ */
}
