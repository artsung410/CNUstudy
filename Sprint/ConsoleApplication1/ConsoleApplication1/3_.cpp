/*
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

	srand(time(NULL));
	int answer;
	answer = rand() % 100;		<=  0 �� ���ԵǼ� ��µȴ�

	cout << "1 ~ 100 ������ ���ڸ� �ϳ� �Է��Ͻÿ�" << endl;
	int mynum = 0;
	cin >> mynum;

	if (answer == mynum)
	{
		cout << "�¸�" << endl;
	}
	int chance;
	for (chance = 5; chance > 0; chance--)
	{
		cout << "�����Դϴ�" << endl;
		cout << "���� ��ȸ�� " << chance << "�� �Դϴ�";
		cin >> mynum;
		if (answer > mynum)
		{
			cout << "���亸�� �����ϴ�" << endl;
		}
		else if (answer < mynum)
		{
			cout << "���亸�� �����ϴ�" << endl;
		}
		if (chance == 1)
		{
			cout << "��ǻ�� ��! ������ " << answer << endl;
		}
	}
}
*/

#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	int result = 1 + rand() % 100;
	int myNum;
	for (int i = 5; i > 0; i--)
	{
		std::cout << "���ڸ� �Է��Ͻÿ� : ";
		std::cin >> myNum;

		if (myNum > result)
		{
			std::cout << "���亸�� �����ϴ�. (���� ��ȸ " << i << " )" << std::endl;
		}
		else if (myNum < result)
		{
			std::cout << "���亸�� �����ϴ�. (���� ��ȸ " << i << " )" << std::endl;
		}
		else if (myNum == result)
		{
			std::cout << "�����Դϴ�." << std::endl;
			break;
		}
	}

	if (myNum != result)
	{
		std::cout << "��ǻ�� ��! �ΰ��й� ������ " << result << "�̾����ϴ�." << std::endl;
	}
}