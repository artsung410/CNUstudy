#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// ����� �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// ���ڸ� ���� ���û����ϱ�
	stack<int> st;

	int action;
	cin >> action;
	while (action--)
	{
		// ���ÿ� ���� ���� �Է��ϱ�
		int num;
		cin >> num;

		if (num != 0)
		{
			// ���ÿ� ���� �ϳ��� �ֱ�
			st.push(num);
		}
		else
		{
			// 0�� ��� ���ÿ��� ���� �ϳ� ����
			st.pop();
		}
	}

	// ���ÿ� �ִ� ���� ���Ͽ� ����ϱ�
	int size = st.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
}