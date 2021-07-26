/*
Evan Nuss, Section 1, nussevan@gmail.com
Test Case:
	input:
		5 questions
		first person: 12 23 34 45 56
		second person: -12 -23 -34 -45 -56
	output:
		normalized first person: 0.14 0.28 0.41 0.54 0.67
		normalized second person: -0.14 -0.28 -0.41 -0.54 -0.67
		compatibility: -1.00 Strongly incompatible
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>

using namespace std;

int numQuestions = 0;

double DotProduct(vector<double>& applicant1, vector<double>& applicant2) {
	double dotProduct = 0.0;
	for (int i = 0; i < numQuestions; i++) {
		double product = 0.0;
		product = applicant1.at(i) * applicant2.at(i);
		dotProduct += product;
	}
	return dotProduct;
}

double VctrMagnitude(vector<double>& applicant) {
	double magnitude = 0.0;
	magnitude = sqrt(DotProduct(applicant, applicant));
	return magnitude;
}


int main() {
	vector<double> firstApplicant;
	vector<double> secondApplicant;
	vector<double> normalized1stApplicant;
	vector<double> normalized2ndApplicant;

	double responses = 0.0;
	double compatibilityScore = 0.0;
	string compatibility;

	const int OUTPUT_PRECISION = 2;
	const double VERY_INCOMPATIBLE_LIMIT = -1.0;
	const double INCOMPATIBLE_LIMIT = -0.5;
	const double INDIFFERENT_LIMIT = -0.1;
	const double COMPATIBLE_LIMIT = 0.1;
	const double VERY_COMPATIBLE_LOWER_LIMIT = 0.5;
	const double VERY_COMPATIBLE_UPPER_LIMIT = 1.0;

	
	cout << "How many questions on the survey?" << endl;
	cin >> numQuestions;
	cout << "I will look for " << numQuestions << " responses from the survey for each applicant." << endl;
	cout << endl;
	cout << "Enter the survey responses from the first applicant: " << endl << endl;

	for (int i = 0; i < numQuestions; i++) {
		cin >> responses;
		firstApplicant.push_back(responses);
	}

	cout << "Enter the survey responses from the second applicant: " << endl << endl;	

	for (int i = 0; i < numQuestions; i++) {
		cin >> responses;
		secondApplicant.push_back(responses);
	}

	cout << "Normalized responses from applicant 1: " << endl;

	for (int i = 0; i < numQuestions; i++) {
		normalized1stApplicant.push_back(firstApplicant.at(i) / VctrMagnitude(firstApplicant));
		cout << fixed << setprecision(OUTPUT_PRECISION) << normalized1stApplicant.at(i) << " ";
	}
	
	cout << endl << endl;
	cout << "Normalized responses from applicant 2: " << endl;

	for (int i = 0; i < numQuestions; i++) {
		normalized2ndApplicant.push_back(secondApplicant.at(i) / VctrMagnitude(secondApplicant));
		cout << fixed << setprecision(OUTPUT_PRECISION) << normalized2ndApplicant.at(i) << " ";
	}
	cout << endl << endl;
	
	compatibilityScore = DotProduct(normalized1stApplicant, normalized2ndApplicant);

	if (compatibilityScore >= VERY_INCOMPATIBLE_LIMIT && compatibilityScore < INCOMPATIBLE_LIMIT) {
		compatibility = "strongly incompatible";
	}
	else if (compatibilityScore >= INCOMPATIBLE_LIMIT && compatibilityScore < INDIFFERENT_LIMIT) {
		compatibility = "incompatible";
	}
	else if (compatibilityScore >= INDIFFERENT_LIMIT && compatibilityScore <= COMPATIBLE_LIMIT) {
		compatibility = "indifferent";
	}
	else if (compatibilityScore > COMPATIBLE_LIMIT && compatibilityScore <= VERY_COMPATIBLE_LOWER_LIMIT) {
		compatibility = "compatible";
	}
	else if (compatibilityScore > VERY_COMPATIBLE_LOWER_LIMIT && compatibilityScore <= VERY_COMPATIBLE_UPPER_LIMIT) {
		compatibility = "strongly compatible";
	}

	cout << "We find these applicants to be " << compatibility << " with a compatibility score of " << fixed << setprecision(OUTPUT_PRECISION) << compatibilityScore << ".";
	cout << endl;

	system("pause");

	return 0;
}