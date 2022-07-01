/*
k��° ����� ����
ex) 7 3
1 2 3 4 5 6 7
3����

4 5 6 7 1 2
6����

7 1 2 4 5
2����

4 5 7 1
7����

1 4 5
5����

1 4
1����

4
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int menNum;
	int eraseNum;
	cin >> menNum;
	cin >> eraseNum;

	queue<int> josephus;
	for (int i = 0; i < menNum; i++)
	{
		josephus.push(i + 1);
	}

	cout << "<";
	while (!josephus.empty())
	{
		for (int i = 0; i < eraseNum - 1; i++)
		{
			int front = josephus.front();
			josephus.push(front);
			josephus.pop();
		}
		cout << josephus.front();
		josephus.pop();
		if (josephus.size() >= 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
}