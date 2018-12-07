#ifndef MATCHING_H
#define MATCHING_H

#include "Customer.h"
#include "Driver.h"

class Matching : public Driver, Customer
{
public:

	queue<int> smallSize;

	queue<int> middleSize;

	queue<int> bigSize;

	void linked_driver(int & id);

	void matching(int & id);

	void unmatching(int & id);

};
#endif