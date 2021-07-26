#include"LayerCake.h"
#include<string>
#include<sstream>

using namespace std;

LayerCake::LayerCake(string type, string frosting, int layers) {
	const double CAKE_PRICE = 9.0;
	const double CREAM_CHEESE_FROSTING = 1.0;
	const double EXTRA_LAYERS = 3.0;

	basePrice = CAKE_PRICE;
	cakeFlavor = type;
	frostingFlavor = frosting;
	numLayers = layers;

	if (frostingFlavor == "cream-cheese") {
		basePrice += CREAM_CHEESE_FROSTING*numLayers;
	}
	if (numLayers > 1) {
		basePrice += EXTRA_LAYERS * (numLayers - 1);
	}
}

string LayerCake::ToString() {
	string cakeString;
	ostringstream cakeOSS;
	
	cakeOSS << numLayers << "-layer " << cakeFlavor << " cake with " << frostingFlavor
		<< " frosting " << BakedGood::ToString();
	cakeString = cakeOSS.str();

	return cakeString;
}

double LayerCake::DiscountedPrice(int quantity) {
	const int CAKE_DISCOUNT = 2;
	const int DISCOUNT_THRESHOLD = 3;

	discountedPrice = basePrice * quantity;
	if (quantity >= DISCOUNT_THRESHOLD) {
		discountedPrice -= quantity * CAKE_DISCOUNT;
	}

	return discountedPrice;
}