#include "ItemToPurchase.h"
#include<string>
#include<iomanip>
#include<iostream>

ItemToPurchase::ItemToPurchase(std::string name, std::string description, double price, int quantity) {
	name = "none";
	description = "none";
	price = 0.0;
	quantity = 0;
}

void ItemToPurchase::SetName(std::string userName) {
	itemName = userName;
	return;
}

std::string ItemToPurchase::GetName()const {
	return itemName;
}

void ItemToPurchase::SetPrice(double userPrice) {
	itemPrice = userPrice;
	return;
}

double ItemToPurchase::GetPrice()const {
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int userQuantity) {
	itemQuantity = userQuantity;
	return;
}

int ItemToPurchase::GetQuantity()const {
	return itemQuantity;
}

void ItemToPurchase::SetDescription(std::string userDescription) {
	itemDescription = userDescription;
	return;
}

std::string ItemToPurchase::GetDescription()const {
	return itemDescription;
}

void ItemToPurchase::PrintCost(double userPrice, int userQuantity, std::string userName){
	const int COST_PRECISION = 2;
	itemPrice = userPrice;
	itemQuantity = userQuantity;
	double totalCost = itemPrice * itemQuantity;
	std::cout << itemName << " " << itemQuantity << " @ $" << std::fixed << std::setprecision(COST_PRECISION) << itemPrice
		<< " = $" << std::fixed << std::setprecision(COST_PRECISION) << totalCost << std::endl;
	return;
}

void ItemToPurchase::PrintDescription() {
	std::cout << itemName << ": " << itemDescription << std::endl;
	return;
}