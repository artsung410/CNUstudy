#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_COM 100

// ���ͷ� �׷���
vector<int> graph[MAX_COM];
//int num[MAX_COM] = { 0 };
bool isVisit[MAX_COM] = { false };
int cnt = 0;

// ��ͷ� dfs����
void dfs(int vertex)
{
	isVisit[vertex] = true;

	++cnt;

	for (int next : graph[vertex])
	{
		if (isVisit[next])
		{
			continue;
		}
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// ������ �Է�
	int com;
	cin >> com;

	// ������ �Է�
	int link;
	cin >> link;

	// ������ ��ŭ �����ϱ�
	for (int i = 0; i < link; i++)
	{
		int s, e;
		cin >> s >> e;

		// �瓇�� ����
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// ���� �����ϱ�
	for (int i = 0; i < com; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(1);

	cout << cnt - 1;
}