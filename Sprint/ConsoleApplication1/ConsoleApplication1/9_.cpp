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
	char escape = 'E';
	char store = 'S';

}tile;

struct Hero
{
	char shape = 'P';
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

	// ������ ���� ���� ����
	// ������ġ, Ż����ġ ���ܻ���
	// �ѹ��� ����
	int storeX;
	int storeY;

	do
	{
		storeX = rand() % (MAPSIZE);
		storeY = rand() % (MAPSIZE);

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

		// ������ ����� ���
		mapArr[hero.yPos][hero.xPos] = hero.shape;

		// ������ ���� ���


		// ������ Ż���� ����
		mapArr[MAPSIZE - 1][0] = tile.escape;

		// ������ ���� ǥ��
		mapArr[storeY][storeX] = tile.store;



		// �� Ÿ�� ���
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				cout << mapArr[i][j] << " ";
			}
			cout << endl;
		}

		// ����� ����Ű ����
		char input;
		input = _getch();
		switch (input)
		{
		case 'a':
		{
			hero.xPos--;
			break;

		}
		case 'w':
		{
			hero.yPos--;
			break;

		}
		case 's':
		{
			hero.yPos++;
			break;

		}
		case 'd':
		{
			hero.xPos++;
			break;
		}
		}

		//Sleep(100);
		system("cls");
	}

}