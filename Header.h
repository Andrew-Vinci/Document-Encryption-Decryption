

/*

Author: Andrew Vinci
Class: CSI-281 Data Structures and Algorithms
Assignment: Final Lab
Date Assigned: 04/18/2022
Due Date: 04/28/2022 @ 12:45 p.m.
Description:
This file contains all of the header information for the different classes used in the project.

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
#include <windows.h>

using namespace std;

/*Cite: This is ANother Students Timer System that I'm Using for This Project.*/

#ifndef TIMER_SYSTEM_H
#define TIMER_SYSTEM_H

class TimerSystem
{
private:
	LARGE_INTEGER start, finish, freq;  //For frequency and high speed timers

public:
	TimerSystem();

	double getTime();  //gets current time since top of frame
	void   startClock();  //Starts the frame counter
};

#endif


class LineCount {
private:
	int mValue = 0;
public:
	
	void operator ++ (int);

	int returnValue();

};

struct TestingAlgorithms {

	template <typename T>
	void merge(T list[], int lowerBound, int midElement, int upperBound);

	template <typename T>
	void mergeSort(T list[], int lowerBound, int upperBound);

	template <typename T>
	int binarySearch(T list[], T searchKey, int lowerBound, int upperBound);

	template <typename T>
	int sequentialSearch(T arr[], int size, T searchKey);

	void sortCodex();
	
	void encrypt();

	void encryptUnsorted();
	void decryptUnsorted();

	void menu();

	string inputFile();
	string outputFile();

};
