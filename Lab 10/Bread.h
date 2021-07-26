#pragma once
#include"BakedGood.h"

using namespace std;

class Bread : public BakedGood {
public:
	Bread(string type = "none");
	virtual string ToString();
	virtual double DiscountedPrice(int quantity);
private:
	string breadType;
	double discountedPrice;
};
