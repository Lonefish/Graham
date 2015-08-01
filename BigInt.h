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
	int number[100] = {};
	int length = 0;
	BigInt(char* str);
	BigInt();
	void init(char* str);
	void print();
	virtual ~BigInt();
	BigInt operator+(const BigInt& b);
};

#endif /* BIGINT_H_ */
}