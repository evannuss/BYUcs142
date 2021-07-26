#pragma once
#include"Cake.h"
#include<string>

using namespace std;

class LayerCake : public Cake {
public:
	LayerCake(string type = "none", string frosting = "none", int layers = 0);
	virtual string ToString();
	virtual double DiscountedPrice(int quantity);
private:
	int numLayers;
	double discountedPrice;
};