// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "ConsoleApplication12.h"

using namespace std;

float addition(float number1, float number2);
float subtraction(float number1, float number2);
float multiplication(float number1, float number2);
float division(float number1, float number2);
void ClearScreen();
void WrongInput1();
void WrongInput2();

float number1;
float number2;
char choice;

int main()
{
	do
		{
		cout << "Choose operation: \n 1 = Addition \n 2 = Subtraction \n 3 = Multiplication \n 4 = Division \n Press Q to exit \n" << endl;
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(10000, '\n'); //skipping up to 10000 leftover characters


		if ((choice == 'Q') || (choice == 'q'))

		{
			return EXIT_SUCCESS;
		}


		if (choice == '1') //addition
		{
			//clearing window (console)
			ClearScreen();
			cout << "You are adding. Enter the first number you want to add. \n Number1: " ;
			cin >> number1;

			if (cin.fail()) //checking if data is of correct type

				do
				{

					WrongInput1();

				} while (cin.fail());

			cout << "Enter the second number you want to add. \n Number2 : " ;
			cin >> number2;

			if (cin.fail()) //checking if data is of correct type

				do
				{

					WrongInput2();

				} while (cin.fail());

			cout << "The answer is: " << addition(number1, number2) << endl << endl;
		}
		else
		{
			if (choice == '2') //subtraction
			{
				//clearing window (console)
				ClearScreen();
				cout << "You are subtracting. Enter the first number you want to subtract. \n Number1: ";
				cin >> number1;

				if (cin.fail()) //checking if data is of correct type

					do
					{

						WrongInput1();

					} while (cin.fail());

				cout << "Enter the second number you want to subtract. \n Number2 : ";
				cin >> number2;

				if (cin.fail()) //checking if data is of correct type

					do
					{

						WrongInput2();

					} while (cin.fail());

				cout << "The answer is: " << subtraction(number1, number2) << endl << endl;
			}

			else
			{
				if (choice == '3') //multiplication
				{
					//clearing window (console)
					ClearScreen();
					cout << "You are multiplying. Enter the first number you want to multiply. \n Number1: ";
					cin >> number1;

					if (cin.fail()) //checking if data is of correct type

						do
						{

							WrongInput1();

						} while (cin.fail());

					cout << "Enter the second number you want to multiply. \n Number2 : ";
					cin >> number2;

					if (cin.fail()) //checking if data is of correct type

						do
						{

							WrongInput2();

						} while (cin.fail());

					cout << "The answer is: " << multiplication(number1, number2) << endl << endl;
				}
				else
				{
					if (choice == '4') //division
					{
						//clearing window (console)
						ClearScreen();
						cout << "You are dividing. Enter the first number you want to divide. \n Number1: ";
						cin >> number1;

						if (cin.fail()) //checking if data is of correct type

							do
							{

								WrongInput1();

							} while (cin.fail());


						cout << "Enter the second number you want to divide. \n Number2 : ";
						cin >> number2;

						if (cin.fail()) //checking if data is of correct type

							do
							{

								WrongInput2();

							} while (cin.fail());

						if (number2 == 0)
						{
							cout << "Answer is undefined due to division by 0 \n" << endl;
						}
						else
						{
							cout << "The answer is: " << division(number1, number2) << endl << endl;
						}
					}
					else
					{
						ClearScreen();
						cout << "\n Wrong input. Please choose a number from 1 to 4." << endl << endl;
					}

				}
			}
		}

	} while ((choice != 'q') || (choice != 'Q'));

}

float addition(float number1, float number2)
{
	return number1 + number2;
}
float subtraction(float number1, float number2)
{
	return number1 - number2;
}
float multiplication(float number1, float number2)
{
	return number1 * number2;
}
float division(float number1, float number2)
{
	return number1 / number2;
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void WrongInput1()
{
	ClearScreen();
	cin.clear(); //This corrects the stream.
	cin.ignore(); //This skips the left over stream data.
	cout << " Please enter a Number only. \n Number1 : ";
	cin >> number1;
}

void WrongInput2()
{
	ClearScreen();
	cin.clear();
	cin.ignore();
	cout << " Please enter a Number only. \n Number2 : ";
	cin >> number2;
}
