#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	int resultNum = 1 + rand() % 10;

	std::cout << "���ڸ� �Է��ϼ��� : ";
	int myNum;
	std::cin >> myNum;

	if (myNum == resultNum)
	{
		std::cout << "true" << "\n";
	}
	else if (myNum < resultNum)
	{
		std::cout << "�� ū�� �Դϴ�." << "\n";
	}
	else if (myNum > resultNum)
	{
		std::cout << "�� ������ �Դϴ�." << "\n";
	}

	std::cout << "������ " << resultNum << "�̾����ϴ�!!" << "\n";
}