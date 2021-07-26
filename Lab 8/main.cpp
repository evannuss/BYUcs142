/*
Evan Nuss, Section 1, nussevan@gmail.com
Test Case 1:
	input: Jim, Sep 7th 2018, options, quit
	output: prompted user for name and date, showed menu options correctly, the quit
Test Case 2:
	input: Jim, Sep 7th 2018, add, chicken, boneless breast, 4.5, 5, add, beans, refried, 1.43, 7,
	descriptions, cart, quit
	output: prompted name, date, and item information all correctly.
	Jim's Shopping cart - Sep 7th 2018
	Item descriptions
	chicken: boneless breast
	beans: refried
	Jim's Shopping cart - Sep 7th 2018
	Number of Items: 12

	chicken 5 @ $4.50 = $22.50
	beans 7 @ $1.43 = $10.01

	Total: $32.51
Test Case 3:
	input: Blake Fisher, 11/13/12, computer, add, chicken, boneless, 4.5, 5, add, beans, refried, 1.43, 7,
	cart, remove, chicken, add, bagels, maple french toast, 3.99, 3, change, beans, 5, cart, quit
	output: prompted for name and date, displayed options menu, prompted info for first 2 items,
	Blake Fisher's Shopping cart - 11/13/12
	Number of Items: 12

	chicken 5 @ $4.50 = $22.50
	beans 7 @ $1.43 = $10.01

	Total: $32.51
	prompted removal info, info for new item, and new quantity,
	Blake Fisher's Shopping cart - 11/13/12
	Number of Items: 8

	beans 5 @ $1.43 = $7.15
	bagels 3 @ $3.99 = $11.97

	Total: $19.12
*/

#include<iostream>
#include<string>
#include<sstream>
#include"ItemToPurchase.h"
#include"ShoppingCart.h"

int main() {
	std::string inputName;
	std::string inputDescription;
	double inputPrice = 0.0;
	int inputQuantity = 0;
	std::string inputDate;
	std::string menuOption;
	ItemToPurchase item1;
	ShoppingCart usersCart;

	std::cout << "Enter Customer's Name: " << std::endl;
	std::getline(std::cin, inputName);
	usersCart.SetName(inputName);

	std::cout << "Enter Today's Date: " << std::endl << std::endl;
	std::getline(std::cin, inputDate);
	usersCart.SetDate(inputDate);
	
	while (menuOption != "quit") {
		std::cout << "Enter option: " << std::endl;
		std::cin >> menuOption;
		
		if (menuOption == "quit") {
			std::cout << "Goodbye.";
		}
		else if (menuOption == "add") {
			std::cout << "Enter the item name: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, inputName);
			std::cout << "Enter the item description: " << std::endl;
			std::getline(std::cin, inputDescription);
			std::cout << "Enter the item price: " << std::endl;
			std::cin >> inputPrice;
			std::cout << "Enter the item quantity: " << std::endl << std::endl;
			std::cin >> inputQuantity;

			item1.SetName(inputName);
			item1.SetDescription(inputDescription);
			item1.SetPrice(inputPrice);
			item1.SetQuantity(inputQuantity);

			usersCart.AddItem(item1);
		}
		else if (menuOption == "remove") {
			std::cout << "Enter name of the item to remove: " << std::endl << std::endl;
			std::string itemToRemove;
			std::cin.ignore();
			std::getline(std::cin, itemToRemove);
			item1.SetName(itemToRemove);
			usersCart.RemoveItem(item1);
		}
		else if (menuOption == "change") {
			std::string itemToChange;
			int newQuantity = 0;
			std::cout << "Enter the item name: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, itemToChange);
			std::cout << "Enter the new quantity: " << std::endl;
			std::cin >> newQuantity;

			usersCart.UpdateQuantity(itemToChange, newQuantity);
			std::cout << std::endl;
		}
		else if (menuOption == "descriptions") {
			usersCart.PrintDescription();  
		}
		else if (menuOption == "cart") {
			usersCart.PrintCartInfo();
		}
		else {
			std::cout << "MENU" << std::endl;
			std::cout << "add - Add item to cart" << std::endl;
			std::cout << "remove - Remove item from cart" << std::endl;
			std::cout << "change - Change item quantity" << std::endl;
			std::cout << "descriptions - Output items' descriptions" << std::endl;
			std::cout << "cart - Output shopping cart" << std::endl;
			std::cout << "options - print the options menu" << std::endl;
			std::cout << "quit - Quit" << std::endl << std::endl;
		}
	}


	//system("pause");
	return 0;
}