#pragma once
#include"Cake.h"
#include<string>

using namespace std;

class CupCake : public Cake {
public:
	CupCake(string type = "none", string frosting = "none", string sprinkles = "none");
	virtual string ToString();
	virtual double DiscountedPrice(int quantity);
private:
	string sprinkleColor;
	double discountedPrice;
};