/*
���ִ°� 1 ���°� 0

	0 1 1 0 1 0 0
	0 1 1 0 1 0 1
	1 1 1 0 1 0 1
	0 0 0 0 1 1 1
	0 1 0 0 0 0 0
	0 1 1 1 1 1 0
	0 1 1 1 0 0 0

	�������: ����
	������ ���Ǽ��� ������������ ���
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAXSIZE 25

bool isVisit[MAXSIZE][MAXSIZE] = { false };

void dfs(int x, int y)
{
	isVisit[y][x] = true;

	int nx;
	int ny;

	nx = x + 1 || x - 1;
	int pos[4] = {
		{},
		{},
		{},
		{}
	}

	if (!isVisit[ny][nx])
	{
		dfs(nx, ny);
	}
}

int main()
{
	// ������ ũ��
	int N;
	cin >> N;

	// ���ڿ��� �Է¹ޱ�
	string str;
	int home[MAXSIZE][MAXSIZE];
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		// ���ڿ��� �ܾ��ϳ��� �迭�� �����ϱ�
		for (int j = 0; j < N; j++)
		{
			home[i][j] = str[j] - '0';
		}
	}

	// 1�̸鼭 ù�湮�̸� ��ȸ�ϱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (home[i][j] == 1 && isVisit[i][j] == false)
			{
				dfs(j, i);
			}
		}
	}

}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <utility> // pair
#include <vector>

using namespace std;

//����������
int N;
int map[30][30];
bool isVisited[30][30] = {false};

// ��ȯ���� �ǹ�, ������ ���� ����
int dfs(int y, int x)
{
	isVisited[y][x] = true;

	// ����, �¿� ������ ������
	static const int yPos[] = { -1, 1, 0, 0 }; // ����
	static const int xPos[] = { 0, 0, -1, 1 }; // �¿�

	int houseCnt = 1;

	// ������ǥ�� ����, �¿� �̵��� ���ο� ��ǥ
	for (int i = 0; i < 4; i++)
	{
		// ���ο� ��ǥ������
		int nx = x + xPos[i];
		int ny = y + yPos[i];
		
		// ����ó��
		// �����Ѿ�κ�
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			continue;
		}
		// ��湮�������ų� ���̾ƴѰ�
		if (isVisited[ny][nx] || map[ny][nx] == 0)
		{
			continue;
		}
		houseCnt += dfs(ny, nx);
	}
	return houseCnt;
}

int main()
{
	// N�� �Է�
	scanf("%d", &N);

	// �����Է� scanf
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			scanf("%1d", &map[y][x]); // ���ڸ� �ϳ��� �Է��ض�
		}
	}

	int complexCount = 0;
	vector<int> houseCnt;
	// �������� ������ ���ǰ��� ���ϱ�
	// ������ �˾Ƴ��µ� DFS����Ѵ�.
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			//// 1. �湮���θ� �����Ѵ�. => isVisited
			//// 2. ������ �湮�Ұ��� ���ÿ� �����Ѵ�.
			//// 2-1 ���ÿ��� ��ǥ�� �����Ѵ�. ��ǥ�� pair�� �����Ѵ�. => stack<pair<int, int>> st;
			//stack<pair<int, int>> st;
			//st.push(pair<int, int>(0, 0));
			//// 3. ���� �湮�Ҷ����� ��ȸ�Ѵ�.
			//while (st.empty() == false)
			//{
			//	// ���� �� ��ġ��������
			//	// �湮
			//	// �ֺ�Ž��
			//}
			
			// ��ã�Ұ�, �湮 ��?
			if (isVisited[y][x] == false && map[y][x] == 1)
			{
				// �ѹ������Ҷ����� ������ �ϳ� ã�´�
				int housecount = dfs(y, x);
				houseCnt.push_back(housecount);
				++complexCount;
			}
		}
	}
	sort(houseCnt.begin(), houseCnt.end());

	printf("%d\n", complexCount);
	for (int i = 0; i < houseCnt.size(); i++)
	{
		printf("%d\n", houseCnt[i]);
	}
}