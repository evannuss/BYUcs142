/*
Evan Nuss, Section 1, nussevan@gmail.com
*/

#include<iostream>
#include<sstream>
#include<string>

using namespace std;


int main() {
	const int NUM_CONTESTANTS = 3;

	string contestant1;
	//string contestant2;
	//string contestant3;
	string firstName;
	string lastName;
	int score;

	string names[3];
	int scores[3];

	cout << "Enter \"firstname lastname score\" on each line for three contestants." << endl;
	
	for (int i = 0; i < NUM_CONTESTANTS; i++) {
		getline(cin, contestant1);

		istringstream contestants(contestant1);
		contestants >> firstName;
		contestants >> lastName;
		contestants >> score;

		names[i] = firstName;
		scores[i] = score;
	}
	
	for (int i = 0; i < NUM_CONTESTANTS; i++) {
		cout << names[i] << " " << scores[i] << endl;
	}

	return 0;
}