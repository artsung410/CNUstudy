/*
N���� ��
C���� ������
������� ������ �ִ뼳ġ���� 1��
���������� �� ������ ������ �ִ�Ÿ�
1 2 4 => 1
1 4 8 => 3
4 8 9 => 1
1 4 9 => 3
2 4 9 => 2
����...������ 3
*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int homeCnt, wifiCnt;
int homePos[200000];

int main()
{
	// ���ǰ����� �����ⰳ���Է�
	cin >> homeCnt >> wifiCnt;

	// ���� ��ǥ�Է�
	for (int i = 0; i < homeCnt; i++)
	{
		cin >> homePos[i];
	}

	// ���� ��ǥ�����ʿ�
	sort(homePos, homePos + homeCnt);

	// �����˻������� ���� ������ ����������� �Ÿ� => [����ª���Ÿ� = 1, ����հŸ� = ���帶��������ǥ] => [1, x[N - 1]]
	int s = 1, e = homePos[homeCnt - 1] + 1;
	int result = 0;
	while (s < e)
	{
		// �߾Ӱ��� ���� �ĺ�������
		int mid = (s + e) / 2;

		int cnt = 1; // ó���� �����Ǽ�ġ?

		// ������ mid�Ÿ���ŭ ���� �����⸦ ��ġ�Ҽ��ִ��� Ȯ��
		// cnt�� �����쿡 �����ұ�?!
		// homePos���� mid��ŭ ������ �Ÿ��� ������ ��ġ�� ��쿡 cnt�� �����Ѵ�.
		int pos = 0;
		for (int i = 0; i < homeCnt; i++)
		{
			//ó���� ��ġ�ϰ�
			// home[pos]
			// �� ��ġ�� �������� mid��ŭ������ �ڸ��� ��ġ
			// home[pos] + mid => home[newPos]
			// ���� ���ŵ� ��ġ ���� mid��ŭ ������ �ڸ��� ��ġ
			// home[newPos] => home[pos]
			int len = homePos[i] - homePos[pos];
			
			if (len >= mid)
			{
				pos = i;
				++cnt;
			}
		}

		if (cnt < wifiCnt)
		{
			// ��! �����Ⱑ �� ��ġ��
			// �� �����ϰ� �Ÿ��������ϱ�
			e = mid;
		}
		else
		{
			if (result < mid)
			{
				result = mid;
			}
			// �����Ⱑ ���� ��ġ�Ȱ��
			// ��ġ�Ÿ��� ���ݴ� �ø���
			s = mid + 1;
		}
		
	}
	// �ִ�Ÿ� ���
	cout << result;

}