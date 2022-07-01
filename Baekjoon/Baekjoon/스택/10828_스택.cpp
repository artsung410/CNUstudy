/*
push X	: ���� X�� ���ÿ� �ִ� �����̴�.
pop		: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size	: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty	: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top		: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù° �ٿ� �־����� ����� ��
��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �Էµȴ�

14
push 1
	stack : 1
push 2
	stack : 1 2
top
	���� 2
	stack : 1 2
size
	2��
	stack : 1 2
empty
	��������ϱ� 0
	stack : 1 2
pop
	2
	stack : 1
pop
	1
	stack : 
pop
	-1
	stack :
size
	0
	stack :
empty
	1
	stack :
pop
	-1
	stack : 
push 3
	stack : 3
empty
	0
	stack : 3
top
	3
	stack : 3

2
2
0
2
1
-1
0
1
-1
0
3
*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	//// top�� �ǳ�
	//vector<int> st;
	//st.push_back(1);
	//st.pop_back();

	// ����� �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int action;
	cin >> action;

	vector<int> stack;

	while (action--)
	{
		string command;
		cin >> command;
		
		if (command == "push")
		{
			int num;
			cin >> num;
			stack.push_back(num);
		}
		else if (command == "pop")
		{
			if (stack.empty() != true)
			{
				cout << stack.back() << "\n";
				stack.pop_back();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (command == "empty")
		{
			if (stack.empty() == true)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (command == "top")
		{
			if (stack.empty() != true)
			{
				cout << stack.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
}