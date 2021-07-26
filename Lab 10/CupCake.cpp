#include"CupCake.h"
#include<string>
#include<sstream>

CupCake::CupCake(string type, string frosting, string sprinkles) {
	const double CUPCAKE_PRICE = 1.95;
	const double CREAM_CHEESE_FROSTING = 0.20;

	basePrice = CUPCAKE_PRICE;
	cakeFlavor = type;
	frostingFlavor = frosting;
	sprinkleColor = sprinkles;
	
	if (frostingFlavor == "cream-cheese") {
		basePrice += CREAM_CHEESE_FROSTING;
	}
}

string CupCake::ToString() {
	string cupcakeString;
	ostringstream cupcakeOSS;

	cupcakeOSS << cakeFlavor << " cupcake with " << frostingFlavor << " frosting and "
		<< sprinkleColor << " sprinkles " << BakedGood::ToString();
	
	cupcakeString = cupcakeOSS.str();

	return cupcakeString;
}

double CupCake::DiscountedPrice(int quantity) {
	const double BIG_DISCOUNT = 0.4;
	const double SMALL_DISCOUNT = 0.3;
	const int DISCOUNT_THRESHOLD_1 = 4;
	const int DISCOUNT_THRESHOLD_2 = 2;

	discountedPrice = basePrice * quantity;
	if (quantity >= DISCOUNT_THRESHOLD_1) {
		discountedPrice -= quantity * BIG_DISCOUNT;
	}
	else if (quantity >= DISCOUNT_THRESHOLD_2) {
		discountedPrice -= quantity * SMALL_DISCOUNT;
	}

	return discountedPrice;
}