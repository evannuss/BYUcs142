/* Evan Nuss and Noah Pittenger, Section 1, nussevan@gmail.com and noahap@byu.edu
We exclusively used Visual Studio to build this program.
We used pair programming to build this program.
Test Case # 1:
Inputs: Selection-1, slot number-4

*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double singleChipWinnings = 0.0;
double winnings = 0.0;
int userSelection = 0;

const int DROP_ONE_CHIP = 1;
const int DROP_MULTIPLE_CHIPS = 2;
const int DROP_MULTIPLE_EACH_SLOT = 3;
const int SHOW_MENU = 4;
const int QUIT_GAME = 5;

const int RIGHT_EDGE = 8;
const int LEFT_EDGE = 0;

const int PATH_PRECISION = 1;
const int WINNINGS_PRECISION = 2;
const int SLOT_PRECISION = 0;

const int NUM_ROWS = 12;
const int NUM_SLOTS = 9;

const int RANDOM_RIGHT = 1;
const int RANDOM_PATH_NUMBER = 2;

const int END_OF_PATH_OUTPUT = 11;

const double SHIFT_LEFT = -.5;
const double SHIFT_RIGHT = .5;

const int CHIP_MIN = 0;
const int CHIP_MAX = 10000;

double ComputeWinnings(int slot) {
	const double PRIZES[NUM_SLOTS] = { 100, 500, 1000, 0, 10000, 0, 1000, 500, 100 };
	return PRIZES[slot];
}
double DropSingleChip(double slotNum, bool isSingle) {
	if (isSingle == true) {
		cout << "*** Dropping chip into slot " << fixed << setprecision(SLOT_PRECISION) << slotNum << " ***" << endl;
		cout << "Path: [" << fixed << setprecision(PATH_PRECISION) << slotNum << ", ";
	}

	double chipPosition = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		double randomNumber = 0;
		if (slotNum == LEFT_EDGE) {
			chipPosition = slotNum + SHIFT_RIGHT;
		}
		else if (slotNum == RIGHT_EDGE) {
			chipPosition = slotNum + SHIFT_LEFT;
		}
		else {
			randomNumber = (rand() % RANDOM_PATH_NUMBER);
			if (randomNumber < RANDOM_RIGHT) {
				chipPosition = slotNum + SHIFT_LEFT;
			}
			else {
				chipPosition = slotNum + SHIFT_RIGHT;
			}
		}
		
		slotNum = chipPosition;
		if (isSingle == true) {
			cout << fixed << setprecision(PATH_PRECISION) << chipPosition;
			if (i < END_OF_PATH_OUTPUT) {
				cout << ", ";
			}
		
		}
	}
	if (isSingle == true) {
		cout << "]" << endl;
	}
	return ComputeWinnings(static_cast<int>(slotNum));
}

double DropMultipleOneSlot(int chipNum, double slotNum1) {
	double totalWinnings = 0.0;
	for (int j = 0; j < chipNum; j++) {
		totalWinnings += DropSingleChip(slotNum1, false);
	}

	return totalWinnings;
}

int ErrorCheck(string prompt, string error, int min, int max) {
	cout << prompt << endl;
	cin >> userSelection;
	while ((min >= userSelection) || (max <= userSelection) || cin.fail()) {
		cin.clear();
		cin.ignore(CHIP_MAX, '\n');
		cout << error << endl;
		cout << prompt << endl;
		cin >> userSelection;
	}
	return userSelection;
}
void DropMultipleEachSlot(int chipNum) {
	for (int i = 0; i < NUM_SLOTS; i++) {
		winnings = DropMultipleOneSlot(chipNum, initialSlotNum);
		cout << "Total winnings on slot " << i << ": $" << fixed << setprecision(WINNINGS_PRECISION) << winnings << endl;

		cout << "Average winnings per chip: $";
		double averageChipWinnings = 0.0;
		averageChipWinnings = (winnings / chipNum);
		cout << fixed << setprecision(WINNINGS_PRECISION) << averageChipWinnings << endl;
		cout << endl;
	}
}


int main() {
	const int CONSTANT_SEED = 42;
	srand(CONSTANT_SEED);

	cout << "Welcome to the Plinko simulator! Enter 4 to see options." << endl;
	cout << endl;
	userSelection = ErrorCheck("Enter your selection now:", "Invalid selection. Enter 4 to see options.", DROP_ONE_CHIP - 1, QUIT_GAME + 1);
	cout << endl;
	while (userSelection != QUIT_GAME) {
		int numChips = 0;

		if (userSelection == DROP_ONE_CHIP) {
			double slotNum = 0.0;
			cout << "*** Drop a single chip ***" << endl;
			cout << endl;
			slotNum = ErrorCheck("Which slot do you want to drop the chip in(0 - 8)?", "Invalid slot.", LEFT_EDGE - 1, RIGHT_EDGE + 1);
			cout << endl;
			cout << "Winnings: $" << fixed << setprecision(WINNINGS_PRECISION) << DropSingleChip(slotNum, true); 
			cout << endl << endl;
			userSelection = ErrorCheck("Enter your selection now:", "Invalid selection. Enter 4 to see options.", DROP_ONE_CHIP - 1, QUIT_GAME + 1);
		}

		else if (userSelection == DROP_MULTIPLE_CHIPS) {
			double initialSlotNum = 0.0;
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			numChips = ErrorCheck("How many chips do you want to drop (>0)?", "Invalid number of chips.", CHIP_MIN, CHIP_MAX);
			initialSlotNum = ErrorCheck("Which slot do you want to drop the chip in(0 - 8)?", "Invalid slot.", LEFT_EDGE - 1, RIGHT_EDGE + 1);
			cout << endl << endl;
					
			winnings = DropMultipleOneSlot(numChips, initialSlotNum);
			cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(WINNINGS_PRECISION) << winnings << endl;

			cout << "Average winnings per chip: $";
			double averageChipWinnings = 0.0;
			averageChipWinnings = (winnings / numChips);
			cout << fixed << setprecision(WINNINGS_PRECISION) << averageChipWinnings << endl;
			cout << endl;

			userSelection = ErrorCheck("Enter your selection now:", "Invalid selection. Enter 4 to see options.", DROP_ONE_CHIP - 1, QUIT_GAME + 1);
			cout << endl;
		}

		else if (userSelection == DROP_MULTIPLE_EACH_SLOT) {
			cout << "*** Sequentially drop multiple chips ***" << endl << endl;
			numChips = ErrorCheck("How many chips do you want to drop (>0)?", "Invalid number of chips.", CHIP_MIN, CHIP_MAX);

			DropMultipleEachSlot(numChips);

			userSelection = ErrorCheck("Enter your selection now:", "Invalid selection. Enter 4 to see options.", DROP_ONE_CHIP - 1, QUIT_GAME + 1);
			cout << endl;
		}

		else {
			cout << "Menu: Please select one of the following options :" << endl;
			cout << endl;

			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Drop multiple chips into each slot" << endl;
			cout << "4 - Show the options menu" << endl;
			cout << "5 - Quit the program" << endl;
			cout << endl;

			userSelection = ErrorCheck("Enter your selection now:", "Invalid selection. Enter 4 to see options.", DROP_ONE_CHIP - 1, QUIT_GAME + 1);

		}
	}
	if (userSelection == QUIT_GAME) {
		cout << "Goodbye!" << endl;
	}
	system("pause");


	return 0;
}
