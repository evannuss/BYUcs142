#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"ShoppingCart.h"

ShoppingCart::ShoppingCart(std::string name, std::string date) {
	name = "none";
	date = "none";
}

void ShoppingCart::SetName(std::string name) {
	customerName = name;
	return;
}

std::string ShoppingCart::GetName()const {
	return customerName;
}

void ShoppingCart::SetDate(std::string date) {
	todaysDate = date;
	return;
}

std::string ShoppingCart::GetDate()const {
	return todaysDate;
}

int ShoppingCart::FindItem(ItemToPurchase item, std::vector<ItemToPurchase> cart) {
	for (int i = 0; i < cart.size(); i++) {
		if (item.GetName() == cart.at(i).GetName()) {
			return i;
		}
	}
	return -1;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
	int add = FindItem(item, itemList);
	if (add != -1) {
		std::cout << "Item is already in cart. Nothing added." << std::endl;
	}
	else {
		itemList.push_back(item);
	}
	return;
}

void ShoppingCart::RemoveItem(ItemToPurchase item) {
	int remove = FindItem(item, itemList);
	if (remove != -1) {
		itemList.erase(itemList.begin() + remove);
		return;
	}
	else {
		std::cout << "Item not found in cart. Nothing removed." << std::endl << std::endl;
	}
	return;
}

void ShoppingCart::UpdateQuantity(std::string itemName, int quantity) {
	for (int i = 0; i < itemList.size(); i++) {
		if (itemName == itemList.at(i).GetName()) {
			itemList.at(i).SetQuantity(quantity);
			return;
		}
	}
	std::cout << "Item not found in cart. Nothing modified." << std::endl;
	return;
}

void ShoppingCart::PrintDescription() {
	std::cout << customerName << "'s Shopping cart - " << todaysDate << std::endl;
	
	if (itemList.size() == 0) {
		std::cout << "Shopping cart is empty." << std::endl;
	}
	else {
		std::cout << "Item descriptions" << std::endl;
		for (int i = 0; i < itemList.size(); i++) {
			std::cout << itemList.at(i).GetName() << ": " << itemList.at(i).GetDescription() << std::endl;
		}
	}
	std::cout << std::endl;
	return;
}

void ShoppingCart::PrintCartInfo() {
	const int COST_PRECISION = 2;
	double totalCartCost = 0.0;
	int totalNumItems = 0;
	for (int i = 0; i < itemList.size(); i++) {
		totalNumItems += itemList.at(i).GetQuantity();
	}
	std::cout << customerName << "'s Shopping cart - " << todaysDate << std::endl;
	if (itemList.size() == 0) {
		std::cout << "Shopping cart is empty." << std::endl;
	}
	else {
		std::cout << "Number of Items: " << totalNumItems;
		std::cout << std::endl << std::endl;
		for (int i = 0; i < itemList.size(); i++) {
			std::cout << itemList.at(i).GetName() << " " << itemList.at(i).GetQuantity() << " @ $" << std::fixed << std::setprecision(COST_PRECISION)
				<< itemList.at(i).GetPrice() << " = $" << (itemList.at(i).GetQuantity() * itemList.at(i).GetPrice()) << std::endl;
			totalCartCost += (itemList.at(i).GetQuantity() * itemList.at(i).GetPrice());
		}
		std::cout << std::endl;
		std::cout << "Total: $" << totalCartCost << std::endl << std::endl;
	}
	return;
}
