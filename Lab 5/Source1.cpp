/*




#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	const int HOT_PLATE_ROWS = 10;
	const int HOT_PLATE_COLUMNS = 10;
	double hotPlateInitialTemp[HOT_PLATE_ROWS][HOT_PLATE_COLUMNS];
	const int HOT_PLATE_AREA = pow(HOT_PLATE_ROWS, 2);
	const double INITIAL_TEMP_1 = 100.0;
	const double INITIAL_TEMP_2 = 0.0;
	const int TEMP_PRECISION = 3;
	const int OUTPUT_WIDTH = 9;
	int i = 0;
	int j = 0;

	cout << "Hotplate simunlator" << endl << endl;
	cout << "Printing initial plate..." << endl;

	/*for (i = 0, j = 0; i < HOT_PLATE_ROWS, j < HOT_PLATE_COLUMNS; i++, j++) {
	if ((i == 0) && (j > 0) && (j < (HOT_PLATE_COLUMNS - 1))) {
	hotPlateInitialTemp[i][j] = INITIAL_TEMP_1;
	i--;
	}
	if ((i == 9) && (j > 0) && (j < (HOT_PLATE_COLUMNS - 1))) {
	hotPlateInitialTemp[i][j] = INITIAL_TEMP_1;
	i--;
	}
	else {
	hotPlateInitialTemp[i][j] = INITIAL_TEMP_2;
	}
	}
	for (i = 0; i < HOT_PLATE_COLUMNS; i++) {
		if ((i == 0) || (i == 9)) {
			hotPlateInitialTemp[j][i] = INITIAL_TEMP_2;
		}
		else {
			hotPlateInitialTemp[j][i] = INITIAL_TEMP_1;
		}
		for (j = 0; j < HOT_PLATE_ROWS; j++) {
			if ((j == 0) && (i > 0) && (i < (HOT_PLATE_COLUMNS - 1))) {
				hotPlateInitialTemp[j][i] = INITIAL_TEMP_1;
				j--;
			}
			if ((j == 9) && (i > 0) && (i < (HOT_PLATE_COLUMNS - 1))) {
				hotPlateInitialTemp[j][i] = INITIAL_TEMP_1;
				j--;
			}
			else {
				hotPlateInitialTemp[j][i] = INITIAL_TEMP_2;
			}
		}
	}

	for (i = 0, j = 0; i < HOT_PLATE_ROWS, j < HOT_PLATE_COLUMNS; i++, j++) {
		if ((i == 0) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 1) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 2) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 3) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 4) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 5) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 6) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 7) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 8) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
		if ((i == 9) && (j < HOT_PLATE_COLUMNS)) {
			cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[j][i] << "," << endl;
			i--;
		}
	}

	for (i = 0; i < HOT_PLATE_ROWS; i++) {
	for (j = 0; j < HOT_PLATE_COLUMNS; j++) {
	if ((i == 0) && (j < HOT_PLATE_COLUMNS)) {
	cout << setw(OUTPUT_WIDTH) << fixed << setprecision(TEMP_PRECISION) << hotPlateInitialTemp[i][j] << "," << endl;
	i--;
	}
	}
	}

	system("pause");

	return 0;
}*/