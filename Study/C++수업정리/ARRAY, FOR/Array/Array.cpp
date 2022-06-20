#include <iostream>
#include <conio.h>
using namespace std;

#define MAP_SIZE 10

// 1. �÷��̾�� p�� ǥ���Ѵ�.
// 2. �÷��̾��� �ʱ� ��ġ�� (0, 0)�̴�.
// 3. ���� 10X10���� ǥ���Ѵ�.
// 4. Ż�������� E�� ǥ���Ѵ�.
// 5. Ż�������� ��ġ�� (8, 8)
// 6. �÷��̾�� �Է��� �޴´�.

// ##############
// �̵��� ���� Ű�� �Է��� �ּ���.
int main()
{
	int PosX = 0;
	int PosY = 0;
	char Escape_Point = 'E';
	char tile = '#';
	char player = 'p';

	char Map[MAP_SIZE][MAP_SIZE];

	// �� ���.

	// �� ���. �ݺ��������ؼ� �ٲ�����Ѵ�.
	while (1)
	{
		system("cls");
		for (int y = 0; y < MAP_SIZE; y++)
		{
			for (int x = 0; x < MAP_SIZE; x++)
			{
				if (y == 8 && x == 8)
				{
					Map[y][x] = Escape_Point;
				}

				else if ( y == PosY && x == PosX )
				{
					Map[y][x] = player;
				}

				else
				{
					Map[y][x] = tile;
				}
			}
		}

		for (int y = 0; y < MAP_SIZE; y++)
		{
			for (int x = 0; x < MAP_SIZE; x++)
			{
				cout << Map[y][x];
			}
			cout << "\n";
		}

		if (PosX == 8 && PosY == 8)
		{
			cout << "������(��)�� �ַ�Ż�⿡ �����Ͽ����ϴ�!" << endl;
			break;
		}
		// ȭ�鿡 ��� �ؽ�Ʈ�� �����.


		cout << "�̵��� ���� Ű�� �Է��� �ּ��� : ";
		char inputChar = _getch();

		// ���Է����� Ȯ���Ѵ�.

		switch(inputChar)
		{
		case 'w':
			if (PosY > 0) { PosY--; }
			break;
		case 's':
			if (PosY < 9) { PosY++; }
			break;
		case 'a':
			if (PosX > 0) { PosX--; }
			break;
		case 'd':
			if (PosX < 9) { PosX++; }
			break;
		}


	}

	return 0;
}
