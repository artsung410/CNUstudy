/*
N���� ������ ���
���� H���� �� �κи� ������
�� �κ��� ���� �Է°�M�� ���ƾ���
H�� �ִ��� ��?
*/

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll treeNum;
ll needLen;
ll treeHeight[1000000];
ll maxHeight;

ll s, e;

ll cutLen;

ll result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> treeNum >> needLen;

	for (int i = 0; i < treeNum; i++)
	{
		cin >> treeHeight[i];

		maxHeight = max(treeHeight[i], maxHeight);
	}

	// 1 ~ ������ �ִ� ����
	// start: 1  end: 20
	// H = start + end / 2  �߰������� �д�
	// ������ H�� �ڸ���
	// ������ �������� cutLen = 20 - H;
	// ��� cutLen�� ��������, needLen ���� ũ��?
	// needLen < cutLen �̸�, H�� ���ٴ� ��
	// H�� �ø����� start�� �߰������� �д�.
	s = 1;
	e = maxHeight + 1;

	result = 0;
	while (s < e)
	{
		ll H = (s + e) / 2;

		cutLen = 0;
		for (int i = 0; i < treeNum; i++)
		{
			if (treeHeight[i] >= H)
			{
				cutLen += (treeHeight[i] - H);
			}
		}

		if (cutLen < needLen)
		{
			// �����ѱ���
			// �� �߰� �߶���Ѵٸ�
			e = H;
		}
		else
		{
			result = H;
			s = H + 1;
		}
	}
	cout << result;
}