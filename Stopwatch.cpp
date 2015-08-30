/*
 * Stopwatch.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: lonefish
 */

#include "Stopwatch.h"
#include<stdio.h>


Stopwatch::Stopwatch() {
	// TODO Auto-generated constructor stub

}

Stopwatch::~Stopwatch() {
	// TODO Auto-generated destructor stub
}

void Stopwatch::startClock() {
	this->start = clock();
}

void Stopwatch::stopClock() {
	this->stop = clock();
}

void Stopwatch::reset() {
	this->start = 0;
	this->stop = 0;
	this->diff = 0;
}

float Stopwatch::difference() {
	this->diff = (((float) stop - (float) start) / CLOCKS_PER_SEC) * 1000;
	return diff;
}
