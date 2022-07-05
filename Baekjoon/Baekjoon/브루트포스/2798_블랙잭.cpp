#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cardNum[101];
int sum;

// 3���� ī������ �������ں��� �����鼭(&&) �ִ��� �������� ���ö� ���� �ݺ��ؼ� ����

int main()
{
	// ī���� ���� N, �������� M
	cin >> N >> M;

	// ī���� ������ŭ ī����� �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> cardNum[i];
	}

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = i + 1; k < N; k++)
		{
			for (int j = k + 1; j < N; j++)
			{
				sum = cardNum[i] + cardNum[k] + cardNum[j];
				
				// M�� ���� �����鼭 �ִ��� ������ -> M���� �۰ų� ���� �� �߿� ���� ū��
				if (sum <= M && sum > ans)
				{
					ans = sum;
				}
				cnt++;
			}
		}
	}

	cout << ans;
}