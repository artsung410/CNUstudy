#include <iostream>
#include <queue>

#define MAX_LEN 1001
using namespace std;

int M, N;
int box[MAX_LEN][MAX_LEN];
bool isVisited[MAX_LEN][MAX_LEN];
int date[MAX_LEN][MAX_LEN];
int y, x;
int dy, dx;
queue<pair<int, int>> que;

void bfs()
{
	// ������ġ ��������
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
			{
				que.push(pair<int, int>(i, j));
				date[i][j] = 0; // ��������
				isVisited[i][j] = true; // �湮��ũ
				x = j;
				y = i;
			}
		}
	}

	// �������� �Ͼ�� ó����
	// ť������޾ƿͼ�
	// ������ ũ�⸸ŭ �ݺ����� ������.

	static const int pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			dy = y + pos[i][0];
			dx = x + pos[i][1];

			if (dy < 0 || dy >= N || dx < 0 || dx >= M)
			{
				continue;
			}
			if (isVisited[dy][dx] || box[dy][dx] == -1 || box[dy][dx] == 1)
			{
				continue;
			}

			isVisited[dy][dx] = true;
			box[dy][dx] = 1;
			que.push(pair<int, int>(dy, dx));
			date[dy][dx] = date[y][x] + 1; // ���Ǹ����� 1�� ����
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	cin >> M >> N;

	int cnt = 0;
	// �丶�� ������ �����Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
			
			if (box[i][j] == 0)
			{
				++cnt;
			}
			// �Է¹����� ť�� Ǫ��
		}
	}

	// ó������ �� �������
	// ��ȸ�ߴµ� 0�̾����� ������
	if (/*�迭�ȿ� 0�̾���.*/cnt == 0)
	{
		// �迭�ȿ� 0�� ������ ���⸦ �����ϰ�ʹ�
		cout << 0 << "\n";
		return 0;
	}

	// �丶�� ��������
	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0) // �ڽ��� 0 ������, ������������ �丶�� ����
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	
	cout << date[dy][dx - 1] << "\n";
}