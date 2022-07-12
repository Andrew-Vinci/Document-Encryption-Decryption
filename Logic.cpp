
/*

Author: Andrew Vinci
Class: CSI-281 Data Structures and Algorithms
Assignment: Final Lab
Date Assigned: 04/18/2022
Due Date: 04/28/2022 @ 12:45 p.m.
Description:
This file contains all of the logic for the project. It contains logic for
the differnt algorithms used, as well as the logic for encrypting and decrypting a
document using the provided Codex.txt file.

***This Project uses code from another student in the form of a timer system.***

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)

*/

#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <string>

#include "Header.h"

using namespace std;


/* Cite: This is Another Students Timer System that I'm using for this project.*/

/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  Default constructor for the TimerSystem
******************************************************************************/
TimerSystem::TimerSystem()
{
	start.QuadPart = 0;
	finish.QuadPart = 0;

	//Sets the clock frequency for the system we are running on
	QueryPerformanceFrequency(&freq);
}


/*      Pre:  The stopwatch must be initialized and started
 *     Post:  The elapse time is returned to the caller
 *  Purpose:  Gets time in seconds since the stopwatch has started
 ******************************************************************************/
double TimerSystem::getTime()
{
	QueryPerformanceCounter(&finish);  //get end cpu cycles

   // return the amount of time elapsed
	return static_cast<double>((finish.QuadPart - start.QuadPart) / static_cast<double>(freq.QuadPart));
}


/*      Pre:  The stopwatch must be initialized
 *     Post:  The start private member is reset
 *  Purpose:  To start the stopwatch
 ******************************************************************************/
void TimerSystem::startClock()
{
	//get the top of the frames CPU count
	QueryPerformanceCounter(&start);
}



/*
Pre: Takes in a list, lower bound, upper bound, and the middle element of the array.

Post: Performs a merge operation on the array.

Purpose: This function is used in merge sort to merge the contents
of the array.
*/

template <typename T>
void TestingAlgorithms::merge(T list[], int lowerBound, int midElement, int upperBound) {

	int i, j, k, size1, size2;

	size1 = midElement - lowerBound + 1;
	size2 = upperBound - midElement;

	T* tmp1 = new T[size1];
	T* tmp2 = new T[size2];

	for (i = 0; i < size1; i++) {
		tmp1[i] = list[lowerBound + i];
	}

	for (j = 0; j < size2; j++) {
		tmp2[j] = list[midElement + j + 1];
	}

	i = 0;
	j = i;

	for (k = lowerBound; k <= upperBound && i < size1 && j < size2; k++) {
		if (tmp1[i] <= tmp2[j]) {
			list[k] = tmp1[i];
			i += 1;
		}
		else {
			list[k] = tmp2[j];
			j += 1;
		}
	}

	while (i < size1) {
		list[k] = tmp1[i];
		i += 1;
		k += 1;
	}

	while (j < size2) {
		list[k] = tmp2[j];
		j += 1;
		k += 1;
	}

	delete[] tmp1;
	delete[] tmp2;
}


/*
Pre: Takes in a list, lower bound, and an upper bound.

Post: Performs merge sort on the array.

Purpose: This function is called recursively to sort the contents
of an array.
*/

template <typename T>
void TestingAlgorithms::mergeSort(T list[], int lowerBound, int upperBound) {

	int mid;

	if (lowerBound < upperBound) {
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}

}

/*
Pre: Takes in a list, a search key, a lower bound, and an upper bound.

Post: Performs binary search to find a search ket on an array.

Purpose: This function returns the location of a given element in an array.
*/


template <typename T>
int TestingAlgorithms::binarySearch(T list[], T searchKey, int lowerBound, int upperBound) {

	int mid;

	if (lowerBound <= upperBound) {

		mid = (lowerBound + upperBound) / 2;

		if (list[mid] == searchKey) {
			return mid;
		}
		else if (list[mid] > searchKey) {
			return binarySearch(list, searchKey, lowerBound, mid - 1);
		}
		else {
			return binarySearch(list, searchKey, mid + 1, upperBound);
		}
	}

	return -1;

}


/*
Pre: Takes in an array, the size of an array, and a search key.

Post: Performs sequential search for a search key on an array.

Purpose: This function returns the location of a given search key
in an array.
*/


template <typename T>
int TestingAlgorithms::sequentialSearch(T arr[], int size, T searchKey)
{
	int i;

	for (i = 0; i < size; i++)
		if (arr[i] == searchKey)
			return i;
	return -1;
}


/*
Pre: None.

Post: Performs merge sort on a list of codes.

Purpose: This function sorts a list of codes to be used with
binary search.
*/


void TestingAlgorithms::sortCodex() {

	fstream fin;
	fin.open("Codex.txt");

	string test;

	const int LOWER_BOUND = 0;
	const long int NUM = 398483;
	const long int TOTAL = 398484;
	string* newArray = new string[TOTAL];


	if (fin.good()) {

		for (int i = 0; i <= NUM; i++) {
			getline(fin, test);
			newArray[i] = test;
		}

		mergeSort(newArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (int j = 0; j <= NUM; j++) {
			fin << newArray[j] << endl;
		}

		fin.close();

		delete[] newArray;

	}
}


/*
Pre: Takes in an integer to use to record a count.

Post: Adds 1 to an integer.

Purpose: This function is used to demonstrate operator overloading
and to help keep track of word count and line count.
*/

void LineCount::operator ++ (int) {
	mValue++;
}

/*
Pre: None.

Post: Returns the value that was used to demonstrate operator overloading.

Purpose: This function returns the value of the integer passed to it
and used to help with word count and line count.
*/


int LineCount::returnValue() {
	return mValue;
}


/*
Pre: None.

Post: Returns the Input File.

Purpose: This function returns the input file as a string.
*/

string TestingAlgorithms::inputFile() {


	string userInput;
	string text = "";
	string txt = ".txt";

	string exit = "exit";
	string Exit = "Exit";

	bool flag = false;
	bool flag2 = false;

	int count = 0;

	do {

		if (flag) {
			cout << "Error. Text File Was Not Entered.\n";
			cout << "Please Enter a Text File for Input.\n";
			cout << endl;
			flag = false;
		}

		cout << "Please Enter the Name of the Input File: \n";
		cout << "To Close the Program, Type 'Exit' or 'exit'.\n";
		
		getline(cin, userInput);
		cin.clear();

		int length = userInput.length();

		char period = userInput[length - 4];
		char ch = userInput[length - 3];
		char ch2 = userInput[length - 2];
		char ch3 = userInput[length - 1];
		text += period;
		text += ch;
		text += ch2;
		text += ch3;

		if (text == Exit || text == exit) {
			break;
		}

		if (text != txt) {
			flag = true;
			text = "";
		}


	} while (text != txt);

	count++;

	return userInput;

}



/*
Pre: None.

Post: Returns the Output File.

Purpose: This function returns the output file as a string.
*/

string TestingAlgorithms::outputFile() {

	string userInput;
	string text = "";
	string txt = ".txt";

	bool flag = false;

	do {

		if (flag) {
			cout << "Error. Text File Was Not Entered.\n";
			cout << "Please Enter a Text File to Ouput.\n";
			cout << endl;
			flag = false;
		}

		cout << "Please Enter the Name of the Output File: \n";
		getline(cin, userInput);
		cin.clear();

		int length = userInput.length();

		char period = userInput[length - 4];
		char ch = userInput[length - 3];
		char ch2 = userInput[length - 2];
		char ch3 = userInput[length - 1];
		text += period;
		text += ch;
		text += ch2;
		text += ch3;

		if (text != txt) {
			flag = true;
			text = "";
		}


	} while (text != txt);

	return userInput;

}



/*
Pre: None.

Post: Performs encryption on a text file.

Purpose: This function performs encryption on a text file.
*/

void TestingAlgorithms::encrypt() {

	string N = "N";
	string userInput = "Y";

	TestingAlgorithms obj;

	TimerSystem time;

	LineCount count;
	LineCount count2;

	bool flag = true;

	while (flag) {

		string Exit = "Exit";
		string exit = "exit";

		string inputFile = obj.inputFile();

		if (inputFile == Exit || inputFile == exit) {
			return;
		}

		string outputFile = obj.outputFile();

		fstream fin;
		fstream fin2;
		fstream fin3;
		fin.open(inputFile);
		fin2.open("Codex.txt");
		fin3.open(outputFile);


		string test;
		bool periodFlag = false;
		bool commaFlag = false;
		bool colonFlag = false;
		bool semicolonFlag = false;
		bool exclamationFlag = false;
		bool questionFlag = false;
		bool dashFlag = false;
		bool quoteFlag = false;
		bool parFlag = false;
		bool brackFlag = false;
		bool curlyFlag = false;
		bool atFlag = false;
		bool hashFlag = false;

		char period = '.';
		char comma = ',';
		char colon = ':';
		char semicolon = ';';
		char exclamation = '!';
		char question = '?';
		char dash = '-';
		char at = '@';
		char hashTag = '#';

		char quote = '"';

		char leftPar = '(';
		char rightPar = ')';

		char leftBrack = '[';
		char rightBrack = ']';

		char leftCurly = '{';
		char rightCurly = '}';

		const int LOWER_BOUND = 0;
		const long int NUM = 398483;
		const long int TOTAL = 398484;

		string* newArray = new string[TOTAL];
		string* newArray2 = new string[TOTAL];


		if (fin.good()) {

			time.startClock();

			cout << "Sorting Codex." << endl;
			sortCodex();
			cout << "Encrypting Document." << endl;

			for (int i = 0; i <= NUM; i++) {
				fin2 >> newArray[i] >> newArray2[i];
			}

			fin2.clear();
			fin2.seekg(0);

			for (int i = 0; i <= NUM; i++) {
				fin2 << newArray[i] << " " << newArray2[i] << endl;
			}

			fin.ignore();
			fin.seekg(0);

			while (getline(fin, test)) {

				istringstream ss(test);
				string test2;

				while (ss >> test2) {

					if (test2.back() == period) {
						periodFlag = true;
						test2.pop_back();
					}

					if (test2.front() == leftPar && test2.back() == rightPar) {
						parFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftBrack && test2.back() == rightBrack) {
						brackFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftCurly && test2.back() == rightCurly) {
						curlyFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == quote && test2.back() == quote) {
						quoteFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == hashTag) {
						hashFlag = true;
						test2.erase(0, 1);
					}

					if (test2.front() == at) {
						atFlag = true;
						test2.erase(0, 1);
					}

					if (test2.back() == comma) {
						commaFlag = true;
						test2.pop_back();
					}

					if (test2.back() == colon) {
						colonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == semicolon) {
						semicolonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == exclamation) {
						exclamationFlag = true;
						test2.pop_back();
					}

					if (test2.back() == question) {
						questionFlag = true;
						test2.pop_back();
					}

					if (test2.back() == dash) {
						dashFlag = true;
						test2.pop_back();
					}

					long int testNumber = binarySearch(newArray, test2, LOWER_BOUND, NUM);

					if (testNumber != -1) {

						test2 = newArray2[testNumber];

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += semicolon;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}
					else if (testNumber == -1) {

						test2 = test2;

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += question;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}

					fin3 << test2 << " ";
					count2++;

				}

				fin3 << endl;
				count++;

			}

			cout << "\n";
			cout << "Time: " << time.getTime() << endl;
			cout << "Line Count: " << count.returnValue() << endl;
			cout << "Word Count: " << count2.returnValue() << endl;
			cout << "\n";

		}

		fin.close();
		fin2.close();
		fin3.close();

		delete[] newArray;
		delete[] newArray2;

	}

}


/*
Pre: None.

Post: Performs encryption on a text file using an unsorted codex.

Purpose: This function performs encryption on a text file using an
unsorted codex.
*/

void TestingAlgorithms::encryptUnsorted() {

	string N = "N";
	string userInput = "Y";

	TestingAlgorithms obj;

	TimerSystem time;

	LineCount count;
	LineCount count2;

	bool flag = true;

	while (flag) {

		string Exit = "Exit";
		string exit = "exit";

		string inputFile = obj.inputFile();

		if (inputFile == Exit || inputFile == exit) {
			return;
		}

		string outputFile = obj.outputFile();

		fstream fin;
		fstream fin2;
		fstream fin3;
		fin.open(inputFile);
		fin2.open("Codex.txt");
		fin3.open(outputFile);


		string test;
		bool periodFlag = false;
		bool commaFlag = false;
		bool colonFlag = false;
		bool semicolonFlag = false;
		bool exclamationFlag = false;
		bool questionFlag = false;
		bool dashFlag = false;
		bool quoteFlag = false;
		bool parFlag = false;
		bool brackFlag = false;
		bool curlyFlag = false;
		bool atFlag = false;
		bool hashFlag = false;

		char period = '.';
		char comma = ',';
		char colon = ':';
		char semicolon = ';';
		char exclamation = '!';
		char question = '?';
		char dash = '-';
		char at = '@';
		char hashTag = '#';

		char quote = '"';

		char leftPar = '(';
		char rightPar = ')';

		char leftBrack = '[';
		char rightBrack = ']';

		char leftCurly = '{';
		char rightCurly = '}';

		const int LOWER_BOUND = 0;
		const long int NUM = 398483;
		const long int TOTAL = 398484;

		string* newArray = new string[TOTAL];
		string* newArray2 = new string[TOTAL];


		if (fin.good()) {

			time.startClock();

			cout << "Encrypting Document." << endl;

			for (int i = 0; i <= NUM; i++) {
				fin2 >> newArray[i] >> newArray2[i];
			}

			fin2.clear();
			fin2.seekg(0);

			for (int i = 0; i <= NUM; i++) {
				fin2 << newArray[i] << " " << newArray2[i] << endl;
			}

			fin.ignore();
			fin.seekg(0);

			while (getline(fin, test)) {

				istringstream ss(test);
				string test2;

				while (ss >> test2) {

					if (test2.back() == period) {
						periodFlag = true;
						test2.pop_back();
					}

					if (test2.front() == leftPar && test2.back() == rightPar) {
						parFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftBrack && test2.back() == rightBrack) {
						brackFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftCurly && test2.back() == rightCurly) {
						curlyFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == quote && test2.back() == quote) {
						quoteFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == hashTag) {
						hashFlag = true;
						test2.erase(0, 1);
					}

					if (test2.front() == at) {
						atFlag = true;
						test2.erase(0, 1);
					}

					if (test2.back() == comma) {
						commaFlag = true;
						test2.pop_back();
					}

					if (test2.back() == colon) {
						colonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == semicolon) {
						semicolonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == exclamation) {
						exclamationFlag = true;
						test2.pop_back();
					}

					if (test2.back() == question) {
						questionFlag = true;
						test2.pop_back();
					}

					if (test2.back() == dash) {
						dashFlag = true;
						test2.pop_back();
					}

					long int testNumber = sequentialSearch(newArray, TOTAL, test2);

					if (testNumber != -1) {

						test2 = newArray2[testNumber];

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += semicolon;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}
					else if (testNumber == -1) {

						test2 = test2;

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += question;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}

					fin3 << test2 << " ";
					count2++;

				}

				fin3 << endl;
				count++;

			}

			cout << "\n";
			cout << "Time: " << time.getTime() << endl;
			cout << "Line Count: " << count.returnValue() << endl;
			cout << "Word Count: " << count2.returnValue() << endl;
			cout << "\n";

		}

		fin.close();
		fin2.close();
		fin3.close();

		delete[] newArray;
		delete[] newArray2;

	}

}



/*
Pre: None.

Post: Performs decryption on a text file with an unsorted or sorted codex.

Purpose: This function performs decryption on a text file using an
unsorted or sorted codex.
*/


void TestingAlgorithms::decryptUnsorted() {

	string N = "N";
	string userInput = "Y";

	TestingAlgorithms obj;

	TimerSystem time;

	LineCount count;
	LineCount count2;

	bool flag = true;

	while (flag) {

		string Exit = "Exit";
		string exit = "exit";

		string inputFile = obj.inputFile();

		if (inputFile == Exit || inputFile == exit) {
			return;
		}

		string outputFile = obj.outputFile();

		fstream fin;
		fstream fin2;
		fstream fin3;
		fin.open(inputFile);
		fin2.open("Codex.txt");
		fin3.open(outputFile);


		string test;
		bool periodFlag = false;
		bool commaFlag = false;
		bool colonFlag = false;
		bool semicolonFlag = false;
		bool exclamationFlag = false;
		bool questionFlag = false;
		bool dashFlag = false;
		bool quoteFlag = false;
		bool parFlag = false;
		bool brackFlag = false;
		bool curlyFlag = false;
		bool atFlag = false;
		bool hashFlag = false;

		char period = '.';
		char comma = ',';
		char colon = ':';
		char semicolon = ';';
		char exclamation = '!';
		char question = '?';
		char dash = '-';
		char at = '@';
		char hashTag = '#';

		char quote = '"';

		char leftPar = '(';
		char rightPar = ')';

		char leftBrack = '[';
		char rightBrack = ']';

		char leftCurly = '{';
		char rightCurly = '}';

		const int LOWER_BOUND = 0;
		const long int NUM = 398483;
		const long int TOTAL = 398484;

		string* newArray = new string[TOTAL];
		string* newArray2 = new string[TOTAL];


		if (fin.good()) {

			time.startClock();

			cout << "Decrypting Document." << endl;

			for (int i = 0; i <= NUM; i++) {
				fin2 >> newArray[i] >> newArray2[i];
			}

			fin2.clear();
			fin2.seekg(0);

			for (int i = 0; i <= NUM; i++) {
				fin2 << newArray[i] << " " << newArray2[i] << endl;
			}

			fin.ignore();
			fin.seekg(0);

			while (getline(fin, test)) {

				istringstream ss(test);
				string test2;

				while (ss >> test2) {

					if (test2.back() == period) {
						periodFlag = true;
						test2.pop_back();
					}

					if (test2.front() == leftPar && test2.back() == rightPar) {
						parFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftBrack && test2.back() == rightBrack) {
						brackFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == leftCurly && test2.back() == rightCurly) {
						curlyFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == quote && test2.back() == quote) {
						quoteFlag = true;
						test2.erase(0, 1);
						test2.pop_back();
					}

					if (test2.front() == hashTag) {
						hashFlag = true;
						test2.erase(0, 1);
					}

					if (test2.front() == at) {
						atFlag = true;
						test2.erase(0, 1);
					}

					if (test2.back() == comma) {
						commaFlag = true;
						test2.pop_back();
					}

					if (test2.back() == colon) {
						colonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == semicolon) {
						semicolonFlag = true;
						test2.pop_back();
					}

					if (test2.back() == exclamation) {
						exclamationFlag = true;
						test2.pop_back();
					}

					if (test2.back() == question) {
						questionFlag = true;
						test2.pop_back();
					}

					if (test2.back() == dash) {
						dashFlag = true;
						test2.pop_back();
					}

					long int testNumber = sequentialSearch(newArray2, TOTAL, test2);

					if (testNumber != -1) {

						test2 = newArray[testNumber];

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += semicolon;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}
					else if (testNumber == -1) {

						test2 = test2;

						if (atFlag) {
							test2.insert(0, 1, at);
							atFlag = false;
						}

						if (hashFlag) {
							test2.insert(0, 1, hashTag);
							hashFlag = false;
						}

						if (quoteFlag) {
							test2 += quote;
							test2.insert(0, 1, quote);
							quoteFlag = false;
						}

						if (parFlag) {
							test2 += rightPar;
							test2.insert(0, 1, leftPar);
							parFlag = false;
						}

						if (brackFlag) {
							test2 += rightBrack;
							test2.insert(0, 1, leftBrack);
							brackFlag = false;
						}

						if (curlyFlag) {
							test2 += rightCurly;
							test2.insert(0, 1, leftCurly);
							curlyFlag = false;
						}

						if (periodFlag) {
							test2 += period;
							periodFlag = false;
						}

						if (commaFlag) {
							test2 += comma;
							commaFlag = false;
						}

						if (colonFlag) {
							test2 += colon;
							colonFlag = false;
						}

						if (semicolonFlag) {
							test2 += question;
							semicolonFlag = false;
						}

						if (exclamationFlag) {
							test2 += exclamation;
							exclamationFlag = false;
						}

						if (questionFlag) {
							test2 += question;
							questionFlag = false;
						}

						if (dashFlag) {
							test2 += dash;
							dashFlag = false;
						}

					}

					fin3 << test2 << " ";
					count2++;

				}

				fin3 << endl;
				count++;

			}

			cout << "\n";
			cout << "Time: " << time.getTime() << endl;
			cout << "Line Count: " << count.returnValue() << endl;
			cout << "Word Count: " << count2.returnValue() << endl;
			cout << "\n";

		}

		fin.close();
		fin2.close();
		fin3.close();

		delete[] newArray;
		delete[] newArray2;

	}

}


/*
Pre: None.

Post: Shows a Menu for Encrypting a document.

Purpose: This function shows a menu for the user to encrypt a document.
*/


void TestingAlgorithms::menu() {

	int userInput;

	cout << "[1] Encrypt - Sorted Codex.\n";
	cout << "[2] Encrypt - Unsorted Codex.\n";
	cout << "[3] Decrypt.\n";
	cout << "[4] Exit Program.\n";
	cin.clear();
	cin >> userInput;
	cin.ignore();

	switch (userInput) {
	case 1:
		encrypt();
		break;
	case 2:
		encryptUnsorted();
		break;
	case 3:
		decryptUnsorted();
		break;
	case 4:
		break;
	}

}
