/*
������
push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù�� ��ɼ�

*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int action;
	cin >> action;

	vector<int> dq;
	while (action--)
	{
		string command;
		cin >> command;

		if (command == "push_front")
		{
			int X;
			cin >> X;
			dq.insert(dq.begin(), X);
		}
		else if (command == "push_back")
		{
			int X;
			cin >> X;
			dq.push_back(X);
		}
		else if (command == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.erase(dq.begin());
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "empty")
		{
			if (!dq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}
		else if(command == "front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
}