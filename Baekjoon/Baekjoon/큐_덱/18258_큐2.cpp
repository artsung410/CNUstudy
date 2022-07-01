/*
�������� ť �����ϱ�

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù°�� ��ɾ� ��	

*/
#include <iostream>
#include <list>	

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int action;
	cin >> action;

	// �����̳ʻ���
	list<int> que;

	while (action--)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			int num;
			cin >> num;
			que.push_back(num);
		}
		else if (command == "pop")
		{
			if (!que.empty())
			{
				int n = que.front();
				cout << n << endl;
				que.pop_front();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command == "size")
		{
			cout << que.size() << endl;
		}
		else if (command == "empty")
		{
			if (!que.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
		else if (command == "front")
		{
			if (!que.empty())
			{
				cout << que.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}