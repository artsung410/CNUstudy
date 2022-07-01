/*
1 ~ 500000 ī��
���������� 1
���� pop�ϰ� top�� �� ������
�ٽ� ���� pop�ϰ� top�� �� ������
�� ������ ���峲���� ���� �ݺ�

*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// ī�� ���� �Է�
	int action;
	cin >> action;

	// ť�� ī�� 1���� ������� �ֱ�
	queue<int> card;
	for (int i = 0; i < action; i++)
	{
		card.push(i + 1);
	}

	while (1)
	{
		if (card.size() == 1)
		{
			break;
		}
		// �̰�
		card.pop();

		// swap
		int front = card.front();
		int back = card.back();

		card.push(front);
		card.pop();
	}

	cout << card.front();
}