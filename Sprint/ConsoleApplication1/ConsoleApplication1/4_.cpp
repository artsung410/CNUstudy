#include <iostream>

using namespace std;

int main()
{
	int guguResult[8][9] = { 0 };

	// �Է¿� ������ ���� �ʴ� �κ��� ������ ������.
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			guguResult[i - 2][j - 1] = i * j;
		}
	}
	
	// 0 0		2 * 1
	// 0 1		2 * 2
	// 0 2		2 * 3
	// 0 3		2 * 4

	int firstNum;
	cin >> firstNum;

	int secondNum;
	cin >> secondNum;
	
	cout << firstNum << " ���ϱ� " << secondNum << "��(��) " << guguResult[firstNum - 2][secondNum - 1] << " �Դϴ�.";
}