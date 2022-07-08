#include <iostream>

#include <vector>

using namespace std;

int digitCount[51];

// ���׻��� ������ ������� ����ü�� �����Ѵ�.
struct Student
{
	int x; // �л��� ������
	int y; // �л��� Ű
	int BodyRank; // �б޿��� �ڽ��� ��ġ ����

	Student(int _x, int _y, int _rank) : x(_x), y(_y), BodyRank(_rank) {} // �����ڸ� ����� �����͸� �޴´�.
};

vector<Student> v;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X, Y;
		cin >> X >> Y;

		int bodyRank = 1;

		v.push_back(Student(X, Y, bodyRank)); // �ϴ� ������ �л��� ������ �����̳ʸ� �̿��� ��´�.
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// ���� ���� �л��� ��ġ�� �񱳴�󺸴� ������ ������ ������.
			if (v[i].x < v[j].x && v[i].y < v[j].y)
			{
				++v[i].BodyRank;
			}

			// �׷��� ������ ���� ���� ����.
			else
			{
				continue;
			}

		}
	}


	for (int i = 0; i < N; i++)
	{
		cout << v[i].BodyRank << " ";
	}


	return 0;
}
