#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#pragma region ���ͻ��
//���͸� �̿��� DFS
int nodeNum = 7; // ��尳��
bool c[7] = {false}; // �湮ó���� ���� �迭
vector<int> a[8]; // ��尡 ���� ������ ��带 �������ְ� ������ �����Է�

void dfs(int vertex)
{
	if (c[vertex]) // �湮�� ����
	{
		return;
	}
	c[vertex] = true; // �湮ó��
	cout << vertex << ' '; // �湮��� ���

	// �ش���� �����ѳ�带 �ϳ����湮
	for (int  i = 0; i < a[vertex].size(); i++)
	{
		// ������� ������� ����Լ� ���
		int y = a[vertex][i];
		dfs(y);
	}
}
#pragma endregion
