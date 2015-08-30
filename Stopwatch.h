/*
 * Stopwatch.h
 *
 *  Created on: Aug 30, 2015
 *      Author: lonefish
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#include<time.h>


class Stopwatch {
public:
	clock_t start;
	clock_t stop;
	float diff;
	float difference();
	void startClock();
	void stopClock();
	void reset();
	Stopwatch();
	virtual ~Stopwatch();
};

#endif /* STOPWATCH_H_ */
