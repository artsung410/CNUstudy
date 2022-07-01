#include <iostream>
#include <queue>

using namespace std;

#define MAX_POS 100001

// ��������
int start, finish;

queue<int> que;

bool isVisited[MAX_POS];

int quick[MAX_POS];

void bfs(int s, int e)
{
	que.push(s);

	quick[s] = 0;
	isVisited[s] = true;
	
	while (!que.empty())
	{

		int temp = que.front();
		//temp������ �����ϰ��� ������ ����� �ȵ�
	
		if (temp == e)
		{
			break;
		}

		que.pop();

		// ���ο� ��ǥ�� �����ΰ� push�ϱ�
		// �������� �ߺ����� ���� �ȵȴ�.
		// x + 1
		if (temp + 1 < MAX_POS)
		{
			if (!isVisited[temp + 1]) // ���� ���� �ִ������ �Ѿ��ȵȴ�.
			{
				que.push(temp + 1);
				isVisited[temp + 1] = true;
				quick[temp + 1] = quick[temp] + 1;

			}
		}

		// x - 1
		// �����Ʈ: temp - 1���� 0�� ���ü������Ƿ� 0�� ���Խ��Ѿ��ߴ�
		if (temp - 1 >= 0)
		{
			if (!isVisited[temp - 1]) // ������ ������ �ȵȴ�.
			{
				que.push(temp - 1);
				isVisited[temp - 1] = true;
				quick[temp - 1] = quick[temp] + 1;

			}
		}

		// 2 * x
		// �����Ʈ: temp * 2���� �ִ�������� �۰� �����ؾ��ߴ�. �����迭�� ������ ��� ���� ���� �ʵ���
		if (temp * 2 < MAX_POS)
		{
			if (!isVisited[temp * 2]) // ���Ѱ��� ������ �Ѿ�� �ȵȴ�.
			{
				que.push(temp * 2);
				isVisited[temp * 2] = true;
				quick[temp * 2] = quick[temp] + 1;
			}

		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// ������ġ, ������ġ
	cin >> start >> finish;

	// ť�� 3���� ������ ������ ���
	// ���� ������ �������� �������Ѵ�.
	// 5 -> ( 6       4       10 ) 
	//    (7 5 12) (5 3 8) (11 9 20)   �̷������� ť�� ���δ� 
	// �̹� ���� ���ڶ�� ���� �ʴ´�
	// ť�� ����ִ� ���� ������ġ�� ���ö����� ī��Ʈ

	bfs(start, finish);

	cout << quick[finish];
}