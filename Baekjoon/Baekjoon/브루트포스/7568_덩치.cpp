#include <iostream>
#include <algorithm>

#define MAX_MEN 50

using namespace std;

int bulk[MAX_MEN][2];
int N, weight, height;
int rankArr[MAX_MEN];

int main()
{
	cin >> N;
	// ������ Ű �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> height;

		bulk[i][0] = weight;
		bulk[i][1] = height;
	}
	
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 0; j < N; j++)
		{
			if (bulk[i][0] < bulk[j][0] && bulk[i][1] < bulk[j][1]) // �񱳰��� �ּҰ��ϼ��� ���� ����ȴ�. ��, ����ī��Ʈ�� �ö�
			{
				cnt++;
			}
		}
		rankArr[i] = cnt; // ������ ������ �迭, ������ ��ġ�迭�� �����ϴ�.
	}

	for (int i = 0; i < N; i++)
	{
		cout << rankArr[i] << " ";
	}
}
