/*
Evan Nuss, Section 1, nussevan@gmail.com
Test case 1:
input:
add: a, s, d, f
display
battle: 1, 1, 1
quit
output:
restaurants added and displayed correctly
winner: a
Test case 2:
input:
add: s, s, d, f
battle
turkey
quit
output:
s, d, f added correctly
correct error messages displayed for second s, battle (not power of 2), and "turkey"
Test case 3:
input:
add: a, s, d, f, q, w, e, r
display
cut: 98, 4
display
shuffle
display
battle: 1, 2, 2, 3, 2, 2, 1, 0, 1
quit
output:
restaurants added and displayed successfully
correct cut error message for 98 displayed
display shows cut was successful
shuffle poperly executed and displayed
battle selection error messages properly displayed
winner: r
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<string> restaurantNames;
string restaurantName;
int numRestaurants = 0;

int FindName(string addName) {
	for (int i = 0; i < restaurantNames.size(); i++) {
		if (addName == restaurantNames.at(i)) {
			return i;
		}
	}
	return -1;
}

void AddRestaurant() {
	cout << "What is the name of the restaurant you want to add?" << endl;
	cin.ignore();
	getline(cin, restaurantName);
	if (FindName(restaurantName) != -1) {
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}
	else {
		restaurantNames.push_back(restaurantName);
		cout << restaurantName << " has been added." << endl << endl;
		numRestaurants++;
	}
}

void DisplayRestaurants() {
	cout << "Here are the current restaurants: " << endl << endl;
	for (int i = 0; i < restaurantNames.size(); i++) {
		cout << "\t\"" << restaurantNames.at(i) << "\"" << endl;
	}
}

void RemoveRestaurant() {
	cout << "What is the name of the restaurant you want to remove?" << endl;
	cin.ignore();
	getline(cin, restaurantName);
	int remove = FindName(restaurantName);
	if (remove != -1) {
		restaurantNames.erase(restaurantNames.begin() + remove);
		cout << restaurantName << " has been removed." << endl << endl;
		numRestaurants--;
	}
	else {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}
}

int ErrorCheck(string prompt, string error, int min, int max, int i) {
	int userOption = 0;
	if (prompt == "Type \"1\" if you prefer ") {
		cout << prompt << restaurantNames.at(i) << " or" << endl;
		cout << "type \"2\" if you prefer " << restaurantNames.at(i + 1) << endl;
		cout << "Choice : ";
	}
	else {
		cout << prompt << endl << endl;
	}
	cin >> userOption;
	while ((min > userOption) || (max < userOption) || cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		if (error == "The cut number must be between 0 and ") {
			cout << error << numRestaurants << endl;
		}
		else {
			cout << error << endl;
		}
		if (prompt == "Type \"1\" if you prefer ") {
			cout << prompt << restaurantNames.at(i) << " or" << endl;
			cout << "type \"2\" if you prefer " << restaurantNames.at(i + 1) << endl;
			cout << "Choice: ";
		}
		else {
			cout << prompt << endl;
		}
		cin >> userOption;
	}
	return userOption;
}

vector<string> CutNames() {
	vector<string> cutList;
	int cutNum = 0;
	cutNum = ErrorCheck("How many restaurants should be taken from the top and put on the bottom?", "The cut number must be between 0 and ", 0, numRestaurants, 0);
	int remainderInList = numRestaurants - cutNum;
	for (int i = remainderInList; i > 0; i--) {
		cutList.push_back(restaurantNames.at(numRestaurants - i));
	}
	for (int j = 0; j < cutNum; j++) {
		cutList.push_back(restaurantNames.at(0 + j));
	}
	return cutList;
}

vector<string> ShuffleNames() {
	vector<string> shuffledList;
	const int IS_EVEN = 2;
	int spacer1 = 0;
	int spacer2 = 0;
	int halfwayPoint = (numRestaurants / 2);
	for (int i = IS_EVEN; i < numRestaurants + IS_EVEN; i++) {
		if ((i % IS_EVEN) == 0) {
			shuffledList.push_back(restaurantNames.at(halfwayPoint + spacer1));
			spacer1++;
		}
		else {
			shuffledList.push_back(restaurantNames.at(0 + spacer2));
			spacer2++;
		}

	}

	return shuffledList;
}

vector<string> Battle() {
	int roundNum = 1;
	int size = numRestaurants;
	int preference = 0;
	vector<string> battleContestants;
	while (size > 1) {
		cout << "Round: " << roundNum << endl << endl;
		for (int i = 0; i < size; i++) {
			preference = ErrorCheck("Type \"1\" if you prefer ", "Invalid choice", 1, 2, i);
			cout << endl;
			if (preference == 1) {
				battleContestants.push_back(restaurantNames.at(i));
			}
			else {
				battleContestants.push_back(restaurantNames.at(i + 1));
			}
			i++;
		}
		restaurantNames = battleContestants;
		while (battleContestants.size() > 1) {
			battleContestants.clear();
		}
		roundNum++;
		size /= 2;
	}
	return battleContestants;
}



int main() {
	string userSelection;
	const int POWER_CHECKER = 11;
	bool isPowerOf2 = false;
	const int BASE = 2;

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;
	cout << "Enter your selection: " << endl;
	cin >> userSelection;

	while (userSelection != "quit") {
		if (userSelection == "options") {
			cout << "Please select one of the following options: " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl;
		}
		else if (userSelection == "display") {
			DisplayRestaurants();
		}
		else if (userSelection == "add") {
			AddRestaurant();
		}
		else if (userSelection == "remove") {
			RemoveRestaurant();
		}
		else if (userSelection == "cut") {
			restaurantNames = CutNames();
		}
		else if (userSelection == "shuffle") {
			for (int i = 0; i < POWER_CHECKER; i++) {
				if (numRestaurants == pow(BASE, i)) {
					restaurantNames = ShuffleNames();
					isPowerOf2 = true;
				}
			}
			if (isPowerOf2 == false) {
				cout << "The current tournament size (" << numRestaurants << ") is not a power of two (2, 4, 8...)." << endl;
				cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
			}
		}
		else if (userSelection == "battle") {
			for (int i = 0; i < POWER_CHECKER; i++) {
				if (numRestaurants == pow(BASE, i)) {
					restaurantNames = Battle();
					cout << "The winning restaurant is " << restaurantNames.at(0) << ".";
					cout << endl << endl;
					isPowerOf2 = true;
				}
			}
			if (isPowerOf2 == false) {
				cout << "The current tournament size (" << numRestaurants << ") is not a power of two (2, 4, 8...)." << endl;
				cout << "A battle is not possible. Please add or remove restaurants." << endl;
			}
		}
		else {
			cout << "Invalid selection" << endl;
			cout << "Please select one of the following options: " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl;
		}
		cout << "Enter your selection: " << endl;
		cin >> userSelection;
	}

	if (userSelection == "quit") {
		cout << "Goodbye!" << endl;
	}

	//system("pause");
	return 0;
}