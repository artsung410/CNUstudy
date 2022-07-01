#include <iostream>
//#include <algorithm> 2�����迭�� �׷����� �׷����Ƿ� ������ �ʿ����?

using namespace std;

#define MAX_LENGTH 51

int T, M, N, cabbageCnt, X, Y;
int map[MAX_LENGTH][MAX_LENGTH] = { 0 };
bool isVisited[MAX_LENGTH][MAX_LENGTH] = { false };

void dfs(int y, int x)
{
	// �湮�� ��ġ ǥ��
	isVisited[y][x] = true;

	// ��ġ�� ������
	static const int dx[4] = { -1, 1, 0, 0 }; // �¿�
	static const int dy[4] = { 0, 0, -1, 1 }; // ����
	
	// �����¿� Ȯ���ϰ� ������ ������ ���
	for (int i = 0; i < 4; i++)
	{
		int newY = y + dy[i];
		int newX = x + dx[i];

		if ((map[newY][newX] == 0 || isVisited[newY][newX]) || newX < 0 || newY < 0 || newX >= M || newY >= N)
		{
			continue;
		}
		dfs(newY, newX);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �׽�Ʈ���̽�
	cin >> T;

	while (T--)
	{
		// ����, ����, �ɾ��� ���߰���
		cin >> M >> N >> cabbageCnt;
		
		int wormCnt = 0;

		// �� �ʱ�ȭ
		for (int i = 0; i < MAX_LENGTH; i++)
		{
			for (int j = 0; j < MAX_LENGTH; j++)
			{
				map[i][j] = 0;
				isVisited[i][j] = false;
			}
		}

		// ��ǥ�� �Է��ϰ� �ش� ��ǥ�� 1ǥ�� 
		while (cabbageCnt--)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		// ������ ���ߴ� �Ѹ���
		for (int i = 0; i < N; i++) // ����
		{
			for (int j = 0; j < M; j++) // ����
			{
				// dfsȣ������: ù�湮�̰� 0�� �ƴѰ��
				if (isVisited[i][j] == false && map[i][j] == 1)
				{
					dfs(i, j);
					++wormCnt;
				}
			}
		}
		// ���� ���
		cout << wormCnt << "\n";
	}

}