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
	//long long numberBase32Bit[100] = {};
	int MAXLENGTH = 150;
	long long numberBase10[150] = {};
	int lengthBase10 = 0;
	//int lengthBase32Bit = 0;
	BigInt(char* str);
	BigInt();
	void init(char* str);
	void resetToZero();
	void copy(BigInt b);
	void copyReverse(BigInt b);
	void print(char* str);
	void add(const BigInt& b);
	void subtract(const BigInt& b);
	void shiftMoreSignificant(int addition);
	void checkLength();
	void multiply(const BigInt& b);
	void divide(const BigInt& b);
	void divide2(const BigInt& b);
	int compare(const BigInt& b);
	virtual ~BigInt();
	BigInt operator*(const BigInt& b);
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
	//long long BIT32 = 4294967296; //Make const
	//long long LENGTHBIT32 = 10; //make const
	//void base2ToBase32Bit();
};


#endif /* BIGINT_H_ */
}
