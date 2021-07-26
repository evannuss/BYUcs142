#include"Bread.h"
#include<sstream>


Bread::Bread(string type) {
	const double BREAD_PRICE = 4.50;
	basePrice = BREAD_PRICE;
	breadType = type;
}

string Bread::ToString() {
	string breadString;
	ostringstream breadOSS;

	breadOSS << breadType << " bread " << BakedGood::ToString();
	breadString = breadOSS.str();

	return breadString;
}

double Bread::DiscountedPrice(int quantity) {
	const int DISCOUNT_THRESHOLD = 3;
	discountedPrice = basePrice * quantity;
	for (int i = 1; i <= quantity; i++) {
		if (i % DISCOUNT_THRESHOLD == 0) {
			discountedPrice -= basePrice;
		}
	}
	return discountedPrice;
}

