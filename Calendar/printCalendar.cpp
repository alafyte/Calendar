#include <iostream>
#include <iomanip>
#include <conio.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

void printCalendar(int year) {
	setlocale(LC_ALL, "Rus");
	int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string monthList[] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };

	cout << " -------------------------------------" << endl;
	cout << "            Calendar - " << year << endl;
	cout << " -------------------------------------" << endl << endl;
	int days;
	int current;

	//�������� �������� �������� ��� ������(01.01.xxxx)
	int y = year - 1;
	current = (y + y / 4 - y / 100 + y / 400) % 7;

	//������������ ������� (i - ����� ������)
	for (int i = 0; i < 12; i++)
	{
		//�������� �������(�������� �� ������������)
		if (i == 1)
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				days = 29;
			else
				days = mDays[i];
		else
			days = mDays[i];

		cout << endl << " ------------------- " << monthList[i] << " ---------------" << endl;

		cout << "  ���   ��   ��   ��   ��   ��   ��" << endl;

		//������������ ������� ������� ��� � ������ (k - ����� ���)
		int k;
		for (k = 0; k < current; k++)
			cout << "     ";
		//���������� ������ �������
		for (int j = 1; j <= days; j++)
		{
			k++;
			cout << setw(5) << j;
			//���� ���� �����������(7� ����), �� ������� ������, � ����� ��� ������������ � 0;
			if (k > 6)
			{
				k = 0;
				cout << endl;
			}
		}
		//������� ������
		if (k)
			cout << endl;
		//������� ����
		current = k;
	}
	return;
}