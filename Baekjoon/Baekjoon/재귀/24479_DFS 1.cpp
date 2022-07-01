/*
N���� ����, M���� ���� ������׷���
������ȣ 1 ���� N��
����ġ 1
R���� ����
���������湮
i ��° �ٿ��� ���� i��
�湮 ������ ���
������������ �湮�Ҽ����°�� 0 ���

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXSCOPE 100001

vector<int> graph[MAXSCOPE];
int isVisit[MAXSCOPE];
int cnt = 0;

void dfs(int vertex)
{
	// �湮Ȯ�ο�


	isVisit[vertex] = ++cnt;

	// ��湮�� ����
	if (isVisit[vertex])
	{
		return;
	}

	for (int next : graph[vertex])
	{
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;
	
	// �׷�������
	for (int i = 0; i < M; i++) // ������ ������ ����
	{
		int s, e;
		cin >> s >> e;

		// ��������� ����
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// �����ϱ�. ������ ������ŭ
	for (int i = 0; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for (int i = 0; i < N; i++)
	{
		cout << isVisit[i] << "\n";
	}
}