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

<<<<<<< HEAD
=======
/*
	�����Ѱ�

	�������Ѱ�

	�����̻��Ѱ�

	�������Ѱ�?

	
*/

>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
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
<<<<<<< HEAD
	char escape = 'E';
	char store = 'S';

}tile;

struct Hero
{
	char shape = 'P';
=======
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
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
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

<<<<<<< HEAD
	// ������ ���� ���� ����
	// ������ġ, Ż����ġ ���ܻ���
	// �ѹ��� ����
	int storeX;
	int storeY;

=======
	int storeX;
	int storeY;
	// ������ ���� ���� ����
	// ������ġ, Ż����ġ ���ܻ���
	// �ѹ��� ����
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
	do
	{
		storeX = rand() % (MAPSIZE);
		storeY = rand() % (MAPSIZE);

<<<<<<< HEAD
	} while ((storeX == 0 && storeY == 0) || (storeX == 0 && storeY == (MAPSIZE - 1)));

	while (!gameOver)
	{

		char mapArr[MAPSIZE][MAPSIZE] = { ' ' };

		// �� ���� �Ҵ�
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				mapArr[i][j] = tile.field;
			}
		}
=======
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
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379

		// ������ ����� ���
		mapArr[hero.yPos][hero.xPos] = hero.shape;

		// ������ ���� ���


		// ������ Ż���� ����
		mapArr[MAPSIZE - 1][0] = tile.escape;

		// ������ ���� ǥ��
		mapArr[storeY][storeX] = tile.store;


<<<<<<< HEAD

		// �� Ÿ�� ���
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				cout << mapArr[i][j] << " ";
=======
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
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			}
			cout << endl;
		}

<<<<<<< HEAD
=======
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



>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
		// ����� ����Ű ����
		char input;
		input = _getch();
		switch (input)
		{
		case 'a':
		{
			hero.xPos--;
<<<<<<< HEAD
=======
			if (hero.xPos < 0)			// ���� ������ ���̻� �������� �ʵ��� �����߽��ϴ�.
			{
				hero.xPos++;		
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 'w':
		{
			hero.yPos--;
<<<<<<< HEAD
=======
			if (hero.yPos < 0)
			{
				hero.yPos++;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 's':
		{
			hero.yPos++;
<<<<<<< HEAD
=======
			if (hero.yPos == MAPSIZE)
			{
				hero.yPos--;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 'd':
		{
			hero.xPos++;
<<<<<<< HEAD
=======
			if (hero.xPos == MAPSIZE)
			{
				hero.xPos--;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;
		}
		}

		//Sleep(100);
<<<<<<< HEAD
		system("cls");
=======
		system("cls");		// ȭ���ʱ�ȭ
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
	}

}