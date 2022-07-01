/*
	BFS����ϱ�
	
	����Ⱓ������ ����
	graph[s][e] = graph[e][s] = 1; ����ġ�� 1�� ���Ͻ�Ŵ

	bfs���� ����
	bool visited[] = false �� �湮Ȯ��
	queue<int> que; ��ǥ���� ť
	visited[node] = true; ��Ʈ��� ǥ��
	que.push(node); ��Ʈ��� ť�� ����
	
	while(!que.empty())
		int current = que.front(); �Ǿռ��� ������ ���
		que.pop(); ���ְ�
		cout << current; ���

		for(int next = 0; next < N; ++next) ���⼭ N�� ���α���
			if(!visited[next] && graph[current][next]) ù�湮����
				visited[next] = true
				que.push(next)

	bfsȰ���� �ִܰŸ�
	int row, col, dist
	int d[4][2] = �����¿� ��ǥ������
	int map[][] 2�����迭
	int N ������ ũ��
	
	for int i; i < N
		for int j; j < N
			cin map[i][j] ���߹ݺ����� �ʿ� �� ����
	
	int bfs()
		bool [][] �湮Ȯ��
		queue<int> que
		visit[row][col] = true ��Ʈ��� ��ŷ
		que.push({row, col}


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
//#include <utility>

using namespace std;

#define MAX_LEN 101
// ��������
int N, M;
int map[MAX_LEN][MAX_LEN];
bool isVisited[MAX_LEN][MAX_LEN];
int step[MAX_LEN][MAX_LEN]; // 

// ����ü�� Ÿ���� �����ϰ� ť�� ���밡��
//typedef struct Position
//{
//	int y;
//	int x;
//};

void bfs(int y, int x)
{
	step[y][x] = 1;
	isVisited[y][x] = true;
	queue<pair<int, int>> que; // ��ǥ�� �ޱ����� pair���
	que.push(pair<int, int>(y, x));

	static const int pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // �����¿�

	while (!que.empty())
	{
		y = que.front().first; // pair���� �յڱ����� �̷����Ѵ�.
		x = que.front().second;	

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = y + pos[i][0];
			int nX = x + pos[i][1];

			// �ƴ����ǵ�
			if (nX < 0 || nX >= M || nY < 0 || nY >= N || isVisited[nY][nX] || map[nY][nX] == 0)
			{
				continue;
			}
			else
			{
				isVisited[nY][nX] = true;
				que.push(pair<int, int>(nY, nX));
				step[nY][nX] = step[y][x] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) // ����
	{
		for (int j = 0; j < M; j++) // ����
		{
			scanf("%1d", &map[i][j]); // �ѱ��ھ� �迭�� �ֱ�
		}
	}

	bfs(0, 0);

	cout << step[N - 1][M - 1];
}