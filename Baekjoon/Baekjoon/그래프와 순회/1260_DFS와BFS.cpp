#include <iostream>
// ��ұ׷���?
#include <stack> // dfs
#include <queue> // bfs
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int N, M, V;

void dfsWithStack()
{
	// �湮��������
	bool isVisit[1001] = { false };

	// dfs ����� ���ø����
	stack<int> st; // ���ÿ��� ������ �湮�� ��������
	st.push(V); // ��ó�� �湮�� ����
	isVisit[V] = true;
	
	// ��������湮 Ȯ���ϱ�? => ������ ������� Ȯ�� ������� ��ι湮
	// ���̻� �湮�� ������ ���� ������ �湮
	while (st.empty() == false) // ����ٸ� ������� �湮
	{
		// �����湮
		int node = st.top();
		//cout << node << " ";
		st.pop();
		isVisit[node] = true;
	
		// �������� �湮�� ���� ã��
		/*size_t degreeCnt = graph[node].size();
		for (size_t i = 0; i < degreeCnt; i++)
		{
			int nextNode = graph[node][i];
			if (false == isVisit[nextNode])
			{
				st.push(nextNode);
			}
		}*/
		int cnt = 1;
		for (int nextNode : graph[node])
		{
			if (false == isVisit[nextNode])
			{
				
				st.push(nextNode);
				
				isVisit[nextNode] = true;
				std::cout << nextNode << " ";
			}
			// for���� �� ���´µ��� ������ ��ã������??
		}

	}

}

// ����Լ�
void dfs(int vertex)
{
	static bool isVisited[1001] = { false }; // ���ȣ��־��ϹǷ� ���������ͷ� ����

	// ��湮�� return
	if (isVisited[vertex])
	{
		return;
	}
	
	isVisited[vertex] = true;

	cout << vertex << ' ';

	for (int next : graph[vertex])
	{
		// ù�湮�� ��쿡��
		/*if (isVisited[next] == false)
		{
			dfs(next);
		}*/

		dfs(next);
	}
}

void bfs()
{
	// �湮��������
	bool isVisit[1001] = { false };

	// dfs ����� ���ø����
	queue<int> que; // ���ÿ��� ������ �湮�� ��������
	que.push(V); // ��ó�� �湮�� ����
	isVisit[V] = true;

	// ��������湮 Ȯ���ϱ�? => ������� Ȯ�� ������� ��ι湮
	// ���̻� �湮�� ������ ���� ������ �湮
	while (que.empty() == false) // ����ٸ� ������� �湮
	{
		// �����湮
		int node = que.front();
		cout << node << " ";
		que.pop();
		isVisit[node] = true;

		for (int nextNode : graph[node])
		{
			if (false == isVisit[nextNode])
			{
				que.push(nextNode);
				isVisit[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �׷��� ����
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// ���� �������� �湮 ��Ű������ ����
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);

	cout << "\n";
	
	dfsWithStack();

	cout << "\n";

	bfs();
}