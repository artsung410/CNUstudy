#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, string>> v;

// ���̰� ���� ������, �ϴ� ���̼����� ��������

// ���̰� ������, ���� ���� �������.

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X; string word;
		cin >> X >> word;
		v.push_back(make_pair(X, word));
	}

	stable_sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << ' ' << v[i].second <<'\n';
	}

	return 0;
}

