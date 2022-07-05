/*
������ Ű -> ��ġ

A	(55, 185)	2
B	(58, 183)	2
C	(88, 186)	1
D	(60, 175)	2
E	(46, 155)	5

����2�� ����

*/
#include <iostream>
#include <algorithm>

#define MAX_MEN 50

using namespace std;

int bulk[MAX_MEN][2];
int weight, height;
int N;

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
	
	// �ϳ��ϳ��� ���ϱ����ؼ� ���߹ݺ��� ���
	// ����for���� ����ϸ� �ϳ��� �����ϰ� ���������� ���������� ���Ҽ��ִ�.
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 0; j < N; j++)
		{
			// ���� ������, Ű�� �ٸ� ��󺸴� �������
			// ����ī��Ʈ�� ������Ų��.
			// �����԰� ũ���� Ű�� ������� ����� ��������鼭, 4���̾ƴ� 2������ �����
			// ���� ������ ���
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
