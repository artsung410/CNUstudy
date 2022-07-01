/*
��ȣ ����� �ٸ��� ������ ���ڿ� -> VPS

VPS
	(())()
	((()))

���ڿ�
	(()(
	(())()))

*/

#include <iostream>
#include <stack>

#define RIGHT ')'
#define LEFT '('

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �Է�
	int action;
	cin >> action;
	while (action--)
	{
		string vps;
		cin >> vps;

		int rightCnt = 0;
		int leftCnt = 0;

		// ���ÿ� ���ڿ� �ֱ�
		stack<char> st;
		for (int i = 0; i < vps.size(); i++)
		{
			if (vps[i] == RIGHT)
			{
				++rightCnt;
			}
			else
			{
				++leftCnt;
			}
			st.push(vps[i]);
		}

		// ī��Ʈ �ٸ��� NO
		if (rightCnt != leftCnt)
		{
			cout << "NO" << "\n";
		}
		else
		{
			if (st.top() == LEFT) // ó�� ������ ���ڰ� ( �Ͻ� NO
			{
				cout << "NO" << "\n";
				while (st.size())
				{
					st.pop();
				}
			}
			else
			{
				// )�� ������ 
				// ++ī��Ʈ�Ѵ�
				// ( ������
				// -- ī��Ʈ�Ѵ�
				// ī��Ʈ�� �������� 0�̸� �ѽ��̴�
				// -�� �����ϸ�
				// ���� �ƴϴ�
				int bracketCount = 0;
				// �ϳ��� �����鼭 Ȯ���ϱ�

				while (!st.empty())
				{
					/*
					())(()
					) 1
					( -1
					0 ����

					( -1 
					������ �����ϸ� NO

					*/
					if (st.top() == RIGHT)
					{
						++bracketCount;
					}
					else
					{
						--bracketCount;
					}

					if (bracketCount < 0)
					{
						cout << "NO" << "\n";
						break;
					}
					
					st.pop();
				}
				
				if (bracketCount == 0)
				{
					cout << "YES" << "\n";
				}
			}
		}
	}
}