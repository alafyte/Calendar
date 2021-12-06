#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996)


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
	cout << endl;
	cout << " ---------------" << endl;
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);

	int day = local_time->tm_wday;
	int month = local_time->tm_mon;
	int mday = local_time->tm_mday;

	if (mday < 10)
	{
		cout << "�������:" << '0' << mday << ".";
		if (month < 10)
		{
			cout << '0' << month << "." << year << endl;
		} else cout << month << "." << year << endl;;

	} else cout << "�������:" << mday << "." << month << "." << year << endl;
	
	return;
}