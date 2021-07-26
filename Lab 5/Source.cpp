/*
Evan Nuss, Section 1, nussevan@gmail.com
I successfully created the graph in excel using the file I created from my program.
cell[1][0]:
cell[1][1]: 
cell[1][2]:
cell[2][1]:
cell[2][2]: 

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	const int PLATE_SIZE = 10;
	double initialPlate[PLATE_SIZE][PLATE_SIZE];
	double newPlate[PLATE_SIZE][PLATE_SIZE];
	double tempPlate[PLATE_SIZE][PLATE_SIZE];

	const double INITIAL_TEMP_1 = 100.0;
	const double INITIAL_TEMP_2 = 0.0;

	const int TEMP_PRECISION = 3;
	const int OUTPUT_WIDTH = 9;

	int r;
	int c;

	const int DIVIDER = 4;

	double currentDifference = 0.0;
	double greatestDifference = 1.0;

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if ((r == 0) || (r == PLATE_SIZE - 1)) {
				if ((c == 0) || (c == PLATE_SIZE - 1)) {
					initialPlate[r][c] = INITIAL_TEMP_2;
				}
				else {
					initialPlate[r][c] = INITIAL_TEMP_1;
				}
			}
			else {
				initialPlate[r][c] = INITIAL_TEMP_2;
			}
		}
	}

	cout << "Hotplate simulator" << endl << endl;
	cout << "Printing initial plate..." << endl;

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if (c == PLATE_SIZE - 1) {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << initialPlate[r][c] << endl;
			}
			else {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << initialPlate[r][c] << ",";
			}
		}
	}

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if ((r == 0) || (r == PLATE_SIZE - 1)) {
				if ((c == 0) || (c == PLATE_SIZE - 1)) {
					newPlate[r][c] = INITIAL_TEMP_2;
				}
				else {
					newPlate[r][c] = INITIAL_TEMP_1;
				}
			}
			else {
				newPlate[r][c] = (initialPlate[r - 1][c] + initialPlate[r + 1][c] + initialPlate[r][c + 1] + initialPlate[r][c - 1]) / DIVIDER;
			}
		}
	}

	cout << endl << "Printing plate after one iteration..." << endl;

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if (c == 9) {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << endl;
			}
			else {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << ",";
			}
		}
	}

	while (greatestDifference > 0.1) {
		greatestDifference = 0.0;
		for (r = 0; r < PLATE_SIZE; r++) {
			for (c = 0; c < PLATE_SIZE; c++) {
				tempPlate[r][c] = newPlate[r][c];
			}
		}
		for (r = 0; r < PLATE_SIZE; r++) {
			for (c = 0; c < PLATE_SIZE; c++) {
				if ((r == 0) || (r == PLATE_SIZE - 1)) {
					if ((c == 0) || (c == PLATE_SIZE - 1)) {
						newPlate[r][c] = INITIAL_TEMP_2;
					}
					else {
						newPlate[r][c] = INITIAL_TEMP_1;
					}
				}
				else if ((c == 0) || (c == PLATE_SIZE - 1)) {
					newPlate[r][c] = INITIAL_TEMP_2;
				}
				else {
					newPlate[r][c] = (tempPlate[r - 1][c] + tempPlate[r + 1][c] + tempPlate[r][c + 1] + tempPlate[r][c - 1]) / DIVIDER;
				}
			}
		}
		for (r = 0; r < PLATE_SIZE; r++) {
			for (c = 0; c < PLATE_SIZE; c++) {
					currentDifference = fabs(newPlate[r][c] - tempPlate[r][c]);
					if (currentDifference > greatestDifference) {
						greatestDifference = currentDifference;
					}
			}
		}
	}

	cout << endl << "Printing final plate..." << endl;

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if (c == 9) {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << endl;
			}
			else {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << ",";
			}
		}
	}

	ofstream outputFile;
	outputFile.open("Hotplate.csv");

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if (c == PLATE_SIZE - 1) {
				outputFile << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << endl;
			}
			else {
				outputFile << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << ",";
			}
		}
	}

	ifstream inputFile;
	inputFile.open("Inputplate.txt");
	if (!inputFile.is_open()) {
		cout << "No file found." << endl;
	}

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			inputFile >> newPlate[r][c];
		}
	}


	for (int i = 0; i < 3; i++) {
		for (r = 0; r < PLATE_SIZE; r++) {
			for (c = 0; c < PLATE_SIZE; c++) {
				tempPlate[r][c] = newPlate[r][c];
			}
		}
		for (r = 0; r < PLATE_SIZE; r++) {
			for (c = 0; c < PLATE_SIZE; c++) {
				if ((r == 0) || (r == PLATE_SIZE - 1)) {
					if ((c == 0) || (c == PLATE_SIZE - 1)) {
						newPlate[r][c] = INITIAL_TEMP_2;
					}
					else {
						newPlate[r][c] = INITIAL_TEMP_1;
					}
				}
				else if ((c == 0) || (c == PLATE_SIZE - 1)) {
					newPlate[r][c] = INITIAL_TEMP_2;
				}
				else {
					newPlate[r][c] = (tempPlate[r - 1][c] + tempPlate[r + 1][c] + tempPlate[r][c + 1] + tempPlate[r][c - 1]) / DIVIDER;
				}
			}
		}
	}

	for (r = 0; r < PLATE_SIZE; r++) {
		for (c = 0; c < PLATE_SIZE; c++) {
			if (c == PLATE_SIZE - 1) {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << endl;
			}
			else {
				cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << newPlate[r][c] << ",";
			}
		}
	}
	
	inputFile.close();


	system("pause");

	return 0;
}