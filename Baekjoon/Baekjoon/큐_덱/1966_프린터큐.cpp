/*
�߿䵵 Ȯ��
�߿䵵 ���������� ������ �տ������� �ڷ� ��ġ��

ù�ٿ� �׽�Ʈ���̽� �� �Է�
���̽��� ù��° �ٿ��� ������ ����N, ���°�� �μ�Ǿ����� �ñ��� ������ ���� que�� ���°�� �����ִ��� ��Ÿ���� ����M�� �־���
�� ������ 0��°
�ι�° �ٿ��� N���� ������ �߿䵵�� ���ʴ�� 1 ~ 9 �߿䵵
���� �߿䵵���� ����

���
�� �׽�Ʈ ���̽��� ���� ������ ���°�� �μ� �Ǵ��� ���
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		// �Է�
		int document;
		cin >> document;
		int idx;
		cin >> idx;

		// ���°���� ����
		int count = 0;

		// �迭�� ť�� ����
		queue<int> printer;
		int* arr = new int[document];
		for (int i = 0; i < document; i++)
		{
			// �߿䵵 �Է�
			int imp;
			cin >> imp;

			arr[i] = imp;
			printer.push(arr[i]);
		}

		// idx�Է� -> arr[idx]
		
		// ���������� ������?


		delete[] arr;
	}
}