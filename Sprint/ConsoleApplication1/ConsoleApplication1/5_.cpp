#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void PrintName(string name);

void PrintText();

void printAdult(int age);

void printAverage(int a, int b);

void PrintFour();

int main()
{
	cout << "�̸��� �Է��ϼ��� : ";
	string inputName;
	cin >> inputName;
	PrintName(inputName);

	PrintText();

	cout << "���̸� �Է��ϼ��� : ";
	int age;
	cin >> age;
	printAdult(age);

	cout << "ù��° ���� : ";
	int A;
	cin >> A;
	cout << "�ι�° ���� : ";
	int B;
	cin >> B;
	printAverage(A, B);

	PrintFour();
}

void PrintName(string name)
{
	cout << "\'" << name << "\'" << "�� ����ؿ�!" << endl;
}

void PrintText()
{
	cout << "\'��ȯ���� ��� ���� ���� ȯ���մϴ�\'" << endl;
}

void printAdult(int age)
{
	if (age <= 19)
	{
		cout << "�̼�����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

void printAverage(int a, int b)
{
	float avg = (float)(a + b) / 2;
	cout << avg << endl;
}

void PrintFour()
{
	cout << "ù��° ���� : ";
	int A;
	cin >> A;
	cout << "�ι�° ���� : ";
	int B;
	cin >> B;
	float avg = (float)(A + B) / 2;
	cout << avg << endl;
}
