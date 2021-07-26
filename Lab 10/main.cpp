/*
Evan Nuss, Section 1, nussevan@gmail.com
Test Case 1:
	input: Bread White 2, Layer-cake vanilla chocolate 3 2, Bread White 1, done
	
	output: 
	Order Confirmations:
	White bread ($4.50)
	White bread ($4.50)
	3-layer vanilla cake with chocolate frosting ($15.00)
	3-layer vanilla cake with chocolate frosting ($15.00)
	White bread ($4.50)

	Invoice:
	Baked Good                                                 Quantity    Total
	White bread ($4.50)                                               3     9.00
	3-layer vanilla cake with chocolate frosting ($15.00)             2    30.00
	Totals                                                            5    39.00
	Good Bye
Test Case 2:
	input: Cupcake vanilla cream-cheese green 5, Layer-cake red-velvet cream-cheese 5 2, Bread Wheat 2, Bread Rye 2, done
	
	output: 
	Order Confirmations:
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)
	5-layer red-velvet cake with cream-cheese frosting ($26.00)
	5-layer red-velvet cake with cream-cheese frosting ($26.00)
	Wheat bread ($4.50)
	Wheat bread ($4.50)
	Rye bread ($4.50)
	Rye bread ($4.50)

	Invoice:
	Baked Good                                                                   Quantity    Total
	vanilla cupcake with cream-cheese frosting and green sprinkles ($2.15)              5     8.75
	5-layer red-velvet cake with cream-cheese frosting ($26.00)                         2    52.00
	Wheat bread ($4.50)                                                                 2     9.00
	Rye bread ($4.50)                                                                   2     9.00
	Totals                                                                             11    78.75
	Good Bye
Test Case 3:
	input: Cupcake red-velvet cream-cheese red 2, Bread white 1, Cupcake red-velvet cream-cheese red 1, Bread wheat 1, 
	Cupcake red-velvet cream-cheese green 1, done
	
	output: 
	Order Confirmations:
	red-velvet cupcake with cream-cheese frosting and red sprinkles ($2.15)
	red-velvet cupcake with cream-cheese frosting and red sprinkles ($2.15)
	white bread ($4.50)
	red-velvet cupcake with cream-cheese frosting and red sprinkles ($2.15)
	wheat bread ($4.50)
	red-velvet cupcake with cream-cheese frosting and green sprinkles ($2.15)

	Invoice:
	Baked Good                                                                   Quantity    Total
	red-velvet cupcake with cream-cheese frosting and red sprinkles ($2.15)             3     5.55
	white bread ($4.50)                                                                 1     4.50
	wheat bread ($4.50)                                                                 1     4.50
	red-velvet cupcake with cream-cheese frosting and green sprinkles ($2.15)           1     2.15
	Totals                                                                              6    16.70
	Good Bye

*/

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"BakedGood.h"
#include"Bread.h"
#include"Cake.h"
#include"CupCake.h"
#include"LayerCake.h"

using namespace std;


int main() {
	string inputItemType;
	string inputBreadType;
	string inputCakeFlavor;
	string inputCakeFrosting;
	string inputSprinklesColor;
	vector<BakedGood*> bakedGoods;

	int inputQuantity = 0;
	int inputLayers = 0;
	int specificItemQuantity = 0;
	int totalItems = 0;
	double totalPrice = 0.0;

	const int COLUMN_WIDTH_1 = 75;
	const int COLUMN_WIDTH_2 = 9;
	const int PRICE_PRECISION = 2;

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	do {
		cout << "Sub-order: " << endl;
		cin >> inputItemType;
		if (inputItemType == "Bread") {
			cin >> inputBreadType;
			cin >> inputQuantity;
			for (int i = 0; i < inputQuantity; i++) {
				bakedGoods.push_back(new Bread(inputBreadType));
			}
		}
		else if (inputItemType == "Cupcake") {
			cin >> inputCakeFlavor;
			cin >> inputCakeFrosting;
			cin >> inputSprinklesColor;
			cin >> inputQuantity;
			for (int i = 0; i < inputQuantity; i++) {
				bakedGoods.push_back(new CupCake(inputCakeFlavor, inputCakeFrosting, inputSprinklesColor));
			}
		}
		else if (inputItemType == "Layer-cake") {
			cin >> inputCakeFlavor;
			cin >> inputCakeFrosting;
			cin >> inputLayers;
			cin >> inputQuantity;
			for (int i = 0; i < inputQuantity; i++) {
				bakedGoods.push_back(new LayerCake(inputCakeFlavor, inputCakeFrosting, inputLayers));
			}
		}
	} while (inputItemType != "done");

	cout << endl;
	cout << "Order Confirmations:" << endl;

	for (int i = 0; i < bakedGoods.size(); i++) {
		cout << bakedGoods.at(i)->ToString() << endl;
	}

	cout << endl << "Invoice:" << endl;
	cout << "Baked Good" << setw(COLUMN_WIDTH_1) << "Quantity" << setw(COLUMN_WIDTH_2) << "Total" << endl;

	for (int i = 0; i < bakedGoods.size(); i++) {
		specificItemQuantity = 0;
		for (int j = 0; j < bakedGoods.size(); j++) {
			if (bakedGoods.at(i)->ToString() == bakedGoods.at(j)->ToString()) {
				specificItemQuantity++;
				if (j != i) {
					delete bakedGoods.at(j);
					bakedGoods.erase(bakedGoods.begin() + j);
					j--;
				}
			}
		}
		cout << bakedGoods.at(i)->ToString() << setw(COLUMN_WIDTH_1) << specificItemQuantity << setw(COLUMN_WIDTH_2) << fixed << setprecision(PRICE_PRECISION)
			<< bakedGoods.at(i)->DiscountedPrice(specificItemQuantity) << endl;
		totalItems += specificItemQuantity;
		totalPrice += bakedGoods.at(i)->DiscountedPrice(specificItemQuantity);
	}
	cout << "Totals" << setw(COLUMN_WIDTH_1) << totalItems << setw(COLUMN_WIDTH_2) << totalPrice << endl;
	cout << "Good Bye" << endl;

	//system("pause");
	return 0;
}