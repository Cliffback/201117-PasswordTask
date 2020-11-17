// 201117 PasswordTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;

bool GameWon = false;
int position = 0;
const int passLength{ 6 };
char positionArray[6]{};
char password[passLength]{ 'A','B','C','D','E','F' };
char correctPass[passLength];

void setPass()
{
	std::string pass = "AAAAAA";
	for (int i = 0; i < passLength; i++)
	{
		correctPass[i] = pass[i];
	}
}
void updateTable()
{
	for (int i = 0; i < passLength; i++)
	{
		positionArray[i] = ' ';
	}
	positionArray[position] = 'V';

}
void printTable()
{
	for (int i = 0; i < passLength; i++)
	{
		std::cout << " | " << positionArray[i];

	}
	std::cout << " | \n";
	for (int i = 0; i < passLength; i++)
	{
		std::cout << " | " << password[i];
	}
	std::cout << " | ";
}
void move()
{
	int input;
		input = _getch();

		switch (input)
		{
		case KEY_UP:
			std::cout << "Key up";
			if (password[position]!='A')
			{
				password[position]--;
			}
			break;
		case KEY_DOWN:
			std::cout << "Key down";
			if (password[position] != 'Z')
			{
				password[position]++;
			}
			break;
		case KEY_LEFT:
			std::cout << "Key left";
			if (position>0)
			{
				position--;
			}
			break;
		case KEY_RIGHT:
			std::cout << "Key right";
			if (position < 5)
			{
				position++;
			}
			break;
		default:
			break;
		}

}
void checkCorrect()
{
	int correct;
	correct = 0;
	for (int i = 0; i < passLength; i++)
	{

			if (password[i] == correctPass[i])
			{
				correct++;

			}	
	}
	std::cout << "\nCorrect: " << correct;
	if (correct==6)
	{
		GameWon = true;
	}
}
int main()
{
	setPass();
	while (GameWon == false)
	{
		system("CLS");
		updateTable();
		printTable();
		move();
		checkCorrect();

	}
	system("CLS");
	std::cout << "Congratulations\n";
	system("PAUSE");
   
}
