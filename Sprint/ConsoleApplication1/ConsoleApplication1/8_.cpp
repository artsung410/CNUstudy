/*
"���ӿ� ������ ������ ���� �Է��ϸ� �Է��� ����ŭ ������ ����(����,������,������ �� 1 )�� ������ ���� ( ���ݷ�, ����, ����, ġ���� �� �����̸� 1~10 ���� ���� )�� ���� ������ �����ǵ��� �Ͻÿ�.
������ ��� ������ ȭ�鿡 ǥ���Ͻÿ�

��� ����)
������ ���� �Է��Ͻÿ� : 2
1������ : ������ , ���ݷ� 3 ���� 2 ���� 8 ġ���� 5
2������ : ����  , ���ݷ� 6 ���� 5 ���� 3 ġ���� 1"

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main()
{
	srand(time(NULL));

	cout << "������ ���� �Է��Ͻÿ� : ";
	int InputHeroCount;
	cin >> InputHeroCount; // 2

	// ������ ����
	string* heroPtr = new string[3] {"����", "������", "������"};

	for (int i = 0; i < InputHeroCount; i++)
	{
		int randHero = rand() % 3;
		cout << randHero + 1 << "�� ���� : " << heroPtr[randHero] << ", ";

		// ������ ����
		int* statPtr = new int[5]; // ���ݷ�, ����, ����, ġ����

		for (int i = 0; i < 4; i++) // ���� �������� �ֱ�
		{
			statPtr[i] = rand() % 10 + 1;
		}
		cout << "���ݷ� : " << statPtr[0] << " ���� : " << statPtr[1] << " ���� : " << statPtr[2] << " ġ���� : " << statPtr[3] << endl;

		delete[] statPtr;
	}

	delete[] heroPtr;
}
*/

#include <iostream>

using namespace std;
// ���������� ���ڷ� ��Ƶα����� enum��� swich ���� �ַ� ���

// �Լ��� ����
//struct HeroStat
//{
//	int ATK;
//	int DEF;
//	int MP;
//	int HEAL;
//};

void HeroStat(int* arr);

void MakeHero(int* hero, int num);

int main()
{
	// 11:10
	srand(time(NULL));

	cout << "������ ���� �Է��Ͻÿ� : ";
	int num;
	cin >> num;
	int* heroArr = new int[num];
	MakeHero(heroArr, num);

	delete[] heroArr;
}


void MakeHero(int* hero, int num)
{
	int statArr[4] = { 0 };

	// �� �迭�� ������ ���ڰ� ����. (0 ~ 2)
	for (int i = 0; i < num; i++)
	{
		int randHero = rand() % 3;
		hero[i] = randHero;
		if (hero[i] == 0)
		{
			// ����
			cout << "���� ,";
			HeroStat(statArr);
		}
		else if (hero[i] == 1)
		{
			// ������
			cout << "������ ,";
			HeroStat(statArr);
		}
		else
		{
			// ������
			cout << "������ ,";
			HeroStat(statArr);
		}
	}
}

void HeroStat(int* arr)
{
	// ���ȹ迭�� ������ ���� �Ҵ�
	// statArr[0] - ���ݷ�
	// statArr[1] - ����
	// statArr[2] - ����
	// statArr[3] - ġ����
	for (int i = 0; i < 4; i++)
	{
		int randStat = 1 + rand() % 10;
		arr[i] = randStat;
	}
	cout << "���ݷ� : " << arr[0] << ", ���� : " << arr[1] << ", ���� : " << arr[2] << ", ġ���� : " << arr[3] << endl;
}