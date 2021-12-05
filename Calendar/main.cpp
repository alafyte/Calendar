#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

void printCalendar(int year);

int main()
{
	system("cls");
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);

	int year = 1900 + local_time->tm_year;

	char option;

	do
	{
		system("cls");	
		printCalendar(year);

		cout << endl << endl;
		cout << "Нажмите " << endl;
		cout << "n для переключения на следующий год" << endl;
		cout << "p для предыдущего года" << endl;
		cout << "e для выхода" << endl;
		cout << "h для выбора года" << endl;

		option = getche();
		cout << endl;
		
		switch (option) {
		case 'n':
			year++;
			break;
		case 'p':
			year--;
			break;
		case 'e':
			exit(0);
		case 'h':
			printf("Введите год\n");
			scanf_s("%i", &year);
			printCalendar(year);
			break;
		}
	}
		while (option != 'e' && option != 'E');
		return 0;
}