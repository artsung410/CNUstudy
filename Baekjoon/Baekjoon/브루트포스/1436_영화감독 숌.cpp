#include <iostream>

using namespace std;

#define MAX_SIZE 10000

int N;
// N��° ��ȭ������ �迭�� ����
int titleNum[MAX_SIZE];
int findNum;
int cnt;

int main()
{
	int startNum = 666;
	// 6�� ����3���̻� ������ ������ ����������� �迭�� �����ϱ�
	while (cnt < MAX_SIZE)
	{
		// �ӽ�����
		int temp = startNum;
		// �ڸ����� 6 ���ö����� ī��Ʈ
		int sixCount = 0;

		int i = 0;
		// 66606�� �迭�� �ȴ��
		while ( temp)
		{
			int sixDigit = temp % 10;
			
			// �� ������ ���� ��ü�� Ȯ���ؾ���
			// 666006 ������츦 �����ϸ�
			if (sixDigit == 6) // 6�� ������ +1
			{
				sixCount++;
			}
			else // �׿� ���̳����� 0����
			{
				sixCount = 0;
			}
			// �������� 6�� ������ sixCount�� �ٷ� 3�̵ȴ�.
			// 6�� ����3����������
			if (sixCount == 3)
			{
				titleNum[cnt] = startNum;
				cnt++;
			}
			temp /= 10;
		}
		++startNum;
	}

	cin >> N;
	cout << titleNum[N - 1];
}

