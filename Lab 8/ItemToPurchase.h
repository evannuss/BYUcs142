#pragma once
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include<string>

class ItemToPurchase {
public:
	ItemToPurchase(std::string name = "none", std::string description = "none", double price = 0.0, int quantity = 0);
	void SetName(std::string userName);
	std::string GetName()const;
	void SetPrice(double userPrice);
	double GetPrice()const;
	void SetQuantity(int userQuantity);
	int GetQuantity()const;
	void SetDescription(std::string userDescription);
	std::string GetDescription()const;
	void PrintCost(double userPrice, int userQuantity, std::string userName);
	void PrintDescription();
private:
	std::string itemName;
	std::string itemDescription;
	double itemPrice;
	int itemQuantity;
};




#endif