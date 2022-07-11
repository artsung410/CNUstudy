#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
stack<int> s;

int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Num;
		cin >> Num; 

		// ���Ϳ� ù��°���� �Է¹��� ����, �ι�°���� �ش� �迭�� �ε����� ��´�.
		v.push_back(make_pair(Num, i));
	}

	sort(v.begin(), v.end()); // ���� ���Ľ�Ű��,
	// -10 / 2
	// -9 / 4
	// 2 / 0
	// 4 / 1
	// 4 / 3

	// 999  / 1 
	// 999  / 3
	// 999  / 5
	// 1000  / 0
	// 1000  / 2
	// 1000  / 4

	int Rank = -1;
	for (int i = 0; i < N; i++)
	{
		// ������ ����ְų�, ��������ʰ� �ֻ�ܰ��̶� ���� ���̶� �ٸ��� ���ÿ� �־��ش�.
		if (s.empty() || !s.empty() && s.top() != v[i].first) 
		{
			s.push(v[i].first);
			Rank += 1; // ����������� +1�� ����ǹǷ�, Rank�ʱⰩ�� -1�εΰ�, �ʱⰪ�� ������ +1ī��Ʈ�ؼ� 0���� �����.
			arr[v[i].second] = Rank; // �迭�� �ش� �ε����� �����ؼ� ��ũ�� ��´�.
		}
		else
		{
			arr[v[i].second] = Rank; // �ֻ�� ���̶� ���� ���� �ٸ��� push�� �����ʰ�, ������ ����� ��ũ�� ��´�.
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}