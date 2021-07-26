/*
Evan Nuss, Section 1, nussevan@gmail.com
Test Case
	input:
		Bob Dylan -32
		Jimi Hendrix 64
		Marcus Mumford 32
	output:
		First name: Bob
		Last  name: Dylan
		Score:  -32
		
		First name: Jimi
		Last  name: Hendrix
		Score:  64
		
		First name: Marcus
		Last  name: Mumford
		Score:  32

		Jimi is the winner, with a score of 64	
*/

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

const int NUM_CONTESTANTS = 3;

void NameWinner(string names[NUM_CONTESTANTS], int scores[NUM_CONTESTANTS]) {
	const int MINIMUM_SCORE = -100000;
	string winner;
	int winningScore = MINIMUM_SCORE;
	for (int i = 0; i < NUM_CONTESTANTS; i++) {
		if (scores[i] > winningScore) {
			winningScore = scores[i];
			winner = names[i];
		}
	}
	cout << winner << " is the winner, with a score of " << winningScore << "." << endl;
}

int main() {
	string contestant;
	string firstName;
	string lastName;
	int score = 0;

	string firstNames[NUM_CONTESTANTS];
	int userScores[NUM_CONTESTANTS];

	cout << "Enter \"firstname lastname score\" on each line for three contestants." << endl;

	for (int i = 0; i < NUM_CONTESTANTS; i++) {
		getline(cin, contestant);

		istringstream contestants(contestant);
		contestants >> firstName;
		contestants >> lastName;
		contestants >> score;

		firstNames[i] = firstName;
		userScores[i] = score;

		cout << "First name: " << firstNames[i] << endl;
		cout << "Last  name: " << lastName << endl;
		cout << "Score:	" << userScores[i] << endl << endl;
	}

	NameWinner(firstNames, userScores);

	system("pause");
	return 0;
}