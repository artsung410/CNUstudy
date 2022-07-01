/*
��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.

�ϳ� �Ǵ� �����ٿ� ���ļ� ���ڿ��� �־�����
���ĺ�, ����, �Ұ�ȣ("( )") ���ȣ("[ ]")
���� ��ħǥ . �� ������

�Է��� ������������ �� �������� . �� ���´�

�� �ٸ��� ������ yes, �ƴϸ� no

��ȣ ���� " ."�� ��쵵 yes


So when I die (the [first] I will see in (heaven) is a score list).		yes
[ first in ] ( first out ).												yes
Half Moon tonight (At least it is better than no Moon at all].			no
A rope may form )( a trail in a maze.									no
Help( I[m being held prisoner in a fortune cookie factory)].			no
([ (([( [ ] ) ( ) (( ))] )) ]).											yes
 .																		yes
. 
����

*/

#include <iostream>
#include <string>
#include <stack>

#define BIGBRACKETLEFT '['
#define BIGBRACKETRIGHT ']'

#define SMALLBRACKETLEFT '('
#define SMALLBRACKETRIGHT ')'

#define PERIOD '.'

using namespace std;

int main()
{
	string str;
	while (true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		getline(cin, str);
		if (str[0] == PERIOD)
		{
			break;
		}

		stack<char> stk;
		bool isCorrect = true;
		for (int i = 0; i < str.size(); i++)
		{
			char ch = str[i];
			if (ch == BIGBRACKETLEFT || ch == SMALLBRACKETLEFT)
			{
				stk.push(ch);
			}
			else if (ch == BIGBRACKETRIGHT)
			{
				if (!stk.empty() && stk.top() == BIGBRACKETLEFT)
				{
					stk.pop();
				}
				else
				{
					isCorrect = false;
					break;
				}
			}
			else if (ch == SMALLBRACKETRIGHT)
			{
				if (!stk.empty() && stk.top() == SMALLBRACKETLEFT)
				{
					stk.pop();
				}
				else
				{
					isCorrect = false;
					break;
				}
			}
		}

		if (stk.empty() && isCorrect)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}