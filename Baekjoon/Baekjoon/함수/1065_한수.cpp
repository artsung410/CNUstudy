/*
���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�.
ex) 123 -> �Ѽ� 
	369 -> �Ѽ�

ù°�� �ڿ��� N (1000���� �۰ų� ����)
��� �Է¼����� �۰ų� ���� �Ѽ��� ���� ���
*/
#include <iostream>

using namespace std;

void ArithmeticNumber(int n)
{
	int cnt = 0;

	int action = n;
	int digitNum = n;

	for(int i = 0; i < action; i++)
	{
		int digit[4] = { 0 };
		// �ڿ����� �ڸ������� 
		int idx = 0;
		while(digitNum != 0)
		{
			digit[idx] = digitNum % 10;
			digitNum /= 10;
			idx++;
		}

		digitNum = --n;

		// [i] - [i + 1] = [j]
		// [j] == [j+1]

		// �� �ڸ��� ���̰� ������ ++cnt
		// ���ڸ����� ���ڸ����� �Ѽ���
		if ((digit[0] - digit[1] == digit[1] - digit[2] || digitNum < 99) && (digit[3] != 1))
		{
			++cnt;
		}
	}

	cout << cnt;
}

int main()
{
	int inputNum;
	cin >> inputNum;

	ArithmeticNumber(inputNum);
}