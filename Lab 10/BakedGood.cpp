#include"BakedGood.h"
#include<sstream>
#include<iomanip>

BakedGood::BakedGood() {
	basePrice = 0.0;
}

string BakedGood::ToString() {
	const int PRICE_PRECISION = 2;
	string priceString;
	ostringstream priceOSS;
	priceOSS << "($" << fixed << setprecision(PRICE_PRECISION) << basePrice << ")";
	priceString = priceOSS.str();

	return priceString;
}