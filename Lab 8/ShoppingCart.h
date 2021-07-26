#pragma once
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include<string>
#include<vector>
#include"ItemToPurchase.h"

class ShoppingCart {
public:
	ShoppingCart(std::string name = "none", std::string date = "none");
	void SetName(std::string name);
	std::string GetName()const;
	void SetDate(std::string date);
	std::string GetDate()const;
	void AddItem(ItemToPurchase item);
	void RemoveItem(ItemToPurchase item);
	void UpdateQuantity(std::string itemName, int quantity);
	void PrintDescription();
	void PrintCartInfo();
	int FindItem(ItemToPurchase item, std::vector<ItemToPurchase> cart);
private:
	std::vector<ItemToPurchase> itemList;
	std::string customerName;
	std::string todaysDate;
};


#endif