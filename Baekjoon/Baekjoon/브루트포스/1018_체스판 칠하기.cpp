#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#define BLACK 'B'
#define WHITE 'W'
#define MAX_NUM 50

using namespace std;

int N, M;
char board[MAX_NUM][MAX_NUM];
string line;

const char WB[8][8] = {
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
};

const char BW[8][8] = {
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
};

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = line[j]; 
		}

	}

	// ī��Ʈ�� ������ �迭
	int cnt = 0;
	int checkWb[MAX_NUM * MAX_NUM] = {0};
	int checkBw[MAX_NUM * MAX_NUM] = {0};

	// ������
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			// i, j�� WB, BW �� ������ġ��.
			// ������ġ�� ��´�
			int xStart = j;
			int yStart = i;

			// WB, BW�� 8 * 8 �������

			int cntWB = 0;
			int cntBW = 0;

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					// ������ġ�� ��� �̵��ϴ� ���� 8*8��ŭ��
					// board[y - i][x - j];
					if (WB[y][x] == board[yStart + y][xStart + x])
					{
						cntWB++;
					}
					else if (BW[y][x] == board[yStart + y][xStart + x])
					{
						cntBW++;
					}

				}

			}

			checkBw[cnt] = cntBW;
			checkWb[cnt] = cntWB;
			cnt++;
		}
	}

	// �� �迭�� ���� ��������?
	int minBw = 999999;
	for (int i = 0; i < cnt; i++)
	{
		if (minBw > checkBw[i])
		{
			minBw = checkBw[i];
		}
	}

	int minWb = 999999;
	for (int i = 0; i < cnt; i++)
	{
		if (minWb > checkWb[i])
		{
			minWb = checkWb[i];
		}
	}

	cout << min(minWb, minBw);
}