// �̰Կ� ����?
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long; // �����÷ι����� long long Ÿ�� ���

ll K, N;
ll lan[10000];
ll maxLan;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �Է¹ޱ�
	cin >> K >> N;

	// �����ִ� ������ ���� �Է¹���
	// �����˻����� ó��
	// �������?! => �ڸ� �� �ִ� ������ ����
	// �ڸ����ִ� �ּұ��� : 1cm
	//    ""      �ִ���� : ������ �ִ� ������ ���� �� ����
	// [1, maxLan] ������
	for (size_t i = 0; i < K; i++)
	{
		cin >> lan[i];

		maxLan = max(lan[i], maxLan); // �������ִ� ������ ���� �� ����ã��
	}
	
	// �����˻�
	// [1, maxLan + 1)
	ll s = 1, e = maxLan + 1;
	ll result = 0;
	while (s < e)
	{
		// �ذ� �ɼ��ִ� �ĺ�?!
			ll m = (s + e) / 2;
		// s : 1, e : 803, m : 401

		// m�� ���̷� �߶����� ������ �ִ� ������ ����
		ll cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cnt += lan[i] / m;
		}

		// ��
		if (cnt >= N)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}
		else
		{
			// ���δ�
			e = m;
		}
	}

	cout << result;
}