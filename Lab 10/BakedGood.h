#pragma once
#include<iostream>
using namespace std;

class BakedGood {
public:
	BakedGood();
	virtual string ToString();
	virtual double DiscountedPrice(int quantity) = 0;
protected:
	double basePrice;
};