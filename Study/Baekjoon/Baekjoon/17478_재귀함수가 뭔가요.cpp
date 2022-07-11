#include <iostream>
#include <string>

using namespace std;
int cnt = 0;

void recursion(int n)
{
	static int temp = n;
	string dot;
	for (int i = n; i < temp; i++)
	{
		dot += "____";
	}

	cout << dot + "\"����Լ��� ������?\"" << "\n";
	cout << dot + "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
	cout << dot + "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
	cout << dot + "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

	if (n == 1)
	{
		dot += "____";
		cout << dot + "\"����Լ��� ������?\"" << "\n";
		cout << dot + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		cout << dot + "��� �亯�Ͽ���." << "\n";
		return;
	}

	recursion(n - 1);
	dot += "____";
	cout << dot + "��� �亯�Ͽ���." << "\n";
}
int main()
{
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	int N;
	cin >> N;

	recursion(N);

	cout << "��� �亯�Ͽ���.";
	return 0;
}