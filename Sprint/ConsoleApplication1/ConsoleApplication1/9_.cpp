/*

10X10 Ÿ�� ������ ����Ǵ� ������ ���� ����
- ȭ���� �ʴ� 30���������� ���ŵ˴ϴ�. pass

- ������ ���۵Ǹ� ������ �»�ܿ�, Ż������ ���ϴܿ�, ������ �� ������ ������ ������ �����Ǹ� ��ü ���� 4������ �� �������� ������ ��ġ�� �Ѱ��� �����˴ϴ�.
- ������ WASD�� ������ �����¿�� �� ĭ�� �̵��մϴ�.
- ������ �� �̵��ϸ� �̵��� ������ �������� ���� �����ϰ� ���Ͱ� ����մϴ�. ( ������ ���� ��� Ȯ���� �������� �� �� ���Ͱ� ���� )
- ������ ���ʹ� Ȧ/¦ ���߱� ����� �մϴ�. ������ �̱�� ����� HP��, ��밡 �̱�� ������ HP�� 1�� �پ��ϴ�.
- ������ �������� ���� �ְ� ������ ������ �� �ֽ��ϴ�.
- �����ϸ� ��ó���⸦ ����� ������ �⺻ ������ �ٲ� �� �ְ� �� ���ô�. ( ���� ���� ���� ũ��, ���̵� �� )
- �����ϸ� ���� �Լ� ���� ������ �Լ����� �ҽ� ������ ������ �ٸ� �ҽ� ���Ͽ� ���۵� �� �ְ� �� ���ô�.

- ������ �׸��� ���� ����ü�� ����մϴ�.
 1) Ÿ�� : Ÿ���� Ÿ��(��,��,����),������(����,����,�ſ�����)
 2) ���� : �̸�/HP/����ġ/����ϴ� ���
 3) ���� : �̸�/�ִ�HP/HP/�������ι��ళ��

- ������ �ݵ�� ������ �Լ��� �����մϴ�.
 1) �� �׸��� �Լ� ( �� ũ�⿡ �°� Ÿ��, ���� ���� ��ġ ) : Ÿ��, ���� ���� ������ �Լ��� ����� �����ص� �˴ϴ�.
 2) ȭ�� ��ܿ� ���� ǥ���� �ִ� �Լ� : ȭ�� ��ܿ��� ������ ����, ���� Ÿ���� ����, ���� ������ ������ ǥ�õ˴ϴ�. ( ���� ����, Ÿ�� ���� ���� ������ �Լ��� ����� �����ص� �˴ϴ�. )
 3) ���� �̵�
 4) ���� �̿�
 5) ����
 6) ���� �� ��� ó��
 7) ���� ����
 8) ���� ����

*/

/*
	�����Ѱ�

	�������Ѱ�

	�����̻��Ѱ�

	�������Ѱ�?

	
*/

//#include "9_header.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define MAPSIZE 10

bool gameOver = false;

struct MapTile
{
	char field = '*'; // ����
	char swamp = '~'; // �ſ�����
	char forest = '#'; // ����
	char escape = 'E'; // 4��ǥ��
	char store = 'S'; // 5�� ǥ��

}tile;

struct MapSafety
{
	int safe = 0;
	int danger = 1;
	int veryDanger = 2;
}safety;

struct Hero
{
	char shape = 'P'; // 3���� ǥ��
	int xPos = 0;
	int yPos = 0;

}hero;

struct Monster
{
	char shape = 'M';

}monster;

int main()
{
	srand(time(NULL));

	int storeX;
	int storeY;
	// ������ ���� ���� ����
	// ������ġ, Ż����ġ ���ܻ���
	// �ѹ��� ����
	do
	{
		storeX = rand() % (MAPSIZE);
		storeY = rand() % (MAPSIZE);

	} while ((storeX == 0 && storeY == 0) || (storeX == 0 && storeY == (MAPSIZE - 1)));		 // ������ġ �Ȱ�ġ�� ����

	COORD cur; // ��ǥ�� ���

	char mapArr[MAPSIZE][MAPSIZE] = { ' ' };		// ��ũ�νἭ �� ũ�� ����


	// 0 : �ʵ�
	// 1 : ��
	// 2 : ��
	// ����ġ�� ����ؼ� �� ��ȣ�� ǥ�õǴ� Ÿ���� �ٸ���
	int mapInfo[MAPSIZE][MAPSIZE] = { 0 };			// �ʰ� ������ ũ���� ������ ��� 2�����迭 
	// �� ������ �Ҵ�
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			int infoNum = rand() % 3;
			mapInfo[i][j] = infoNum;			// ���� ���ڷ� Ÿ���� ǥ���ϱ����� �̷��� �߽��ϴ�.
		}
	}
		
	//// �� ���� �Ҵ�
	//for (int i = 0; i < MAPSIZE; i++)
	//{
	//	for (int j = 0; j < MAPSIZE; j++)
	//	{
	//		mapArr[i][j] = '!';
	//		cout << mapArr[i][j] << " ";
	//	}
	//}

	// ��� ������
	while (!gameOver)		// ���� ���������� ��� ���ư����߽��ϴ�.
	{

		// ������ ����� ���
		mapArr[hero.yPos][hero.xPos] = hero.shape;

		// ������ ���� ���


		// ������ Ż���� ����
		mapArr[MAPSIZE - 1][0] = tile.escape;

		// ������ ���� ǥ��
		mapArr[storeY][storeX] = tile.store;


		// �� Ÿ�� ���
		for (int i = 0; i < MAPSIZE; i++)			// �� ��¿� �̻������� ó���� Ÿ�ϰ� ������ ���� ��µ����ʽ��ϴ�. �����̸� ������µ˴ϴ�.
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				// �ϴ� ���
				cout << mapArr[i][j] << " ";

				// ���ڿ� �´� Ÿ�� ǥ��
				switch (mapInfo[i][j])
				{
				case 0:
					mapArr[i][j] = tile.field;
					//cout << mapArr[i][j] << " ";
					break;
				case 1:
					mapArr[i][j] = tile.forest;
					//cout << mapArr[i][j] << " ";
					break;
				case 2:
					mapArr[i][j] = tile.swamp;
					//cout << mapArr[i][j] << " ";
					break;
				default:
					break;
				}
			}
			cout << endl;
		}

		// �Ʒ� ����ǥ�� �κ��� �ϵ� �ڵ��߽��ϴ�. 
#pragma region ����ǥ�� 

		// ȭ�� ��ܿ� ����ǥ��
		// ������ ����, ���� Ÿ���� ����, ���� ������ ����
		// ���� �����ʿ� ǥ���Ѵ�.
		cur.X = 22;
		cur.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "-������ ����-";

		cur.X = 22;
		cur.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "�̸�: ";

		cur.X = 22;
		cur.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "ü��: ";

		cur.X = 22;
		cur.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "���: ";

		// ���� ���� ����
		cur.X = 50;
		cur.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "-������ ����-";

		cur.X = 50;
		cur.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "�̸�: ";

		cur.X = 50;
		cur.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "ü��: ";

		cur.X = 50;
		cur.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		//cout << "���: ";

		// ����Ÿ��
		cur.X = 1;
		cur.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "<<<���� ��ġ>>>";

		string safetyText[3];
		cur.X = 0;
		cur.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		switch (mapInfo[hero.yPos][hero.xPos])
		{
		case 0:
			safetyText[0] = "   �����մϴ�.";
			cout << "     -����-" << endl;
			cout << safetyText[0];
			break;
		case 1:
			safetyText[1] = "���� ����� �����մϴ�.";
			cout << "      -��-" << endl;
			cout << safetyText[1];
			break;
		case 2:
			safetyText[2] = "�ſ� ������ ��� �Դϴ�.";
			cout << "    -������-" << endl;
			cout << safetyText[2];
			break;
		default:
			break;
		}

#pragma endregion



		// ����� ����Ű ����
		char input;
		input = _getch();
		switch (input)
		{
		case 'a':
		{
			hero.xPos--;
			if (hero.xPos < 0)			// ���� ������ ���̻� �������� �ʵ��� �����߽��ϴ�.
			{
				hero.xPos++;		
			}
			break;

		}
		case 'w':
		{
			hero.yPos--;
			if (hero.yPos < 0)
			{
				hero.yPos++;
			}
			break;

		}
		case 's':
		{
			hero.yPos++;
			if (hero.yPos == MAPSIZE)
			{
				hero.yPos--;
			}
			break;

		}
		case 'd':
		{
			hero.xPos++;
			if (hero.xPos == MAPSIZE)
			{
				hero.xPos--;
			}
			break;
		}
		}

		//Sleep(100);
		system("cls");		// ȭ���ʱ�ȭ
	}

}