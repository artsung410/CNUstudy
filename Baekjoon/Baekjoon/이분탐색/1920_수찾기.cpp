#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

// ��ͷ� �غ���
bool BinarySearch(int s, int e, int value)
{
	if (s >= e)
	{
		return false;
	}

	int mid = (s + e) / 2;

	if (arr[mid] == value)
	{
		return true;
	}
	else if (arr[mid] < value)
	{
		return BinarySearch(mid + 1, e, value);
	}
	else
	{
		return BinarySearch(s, mid, value);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	// ���ĵ� ��������Ʈ������ ��밡���ϴ�.
	sort(arr, arr + N);

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;

		bool isExist = false;
		// �̺�Ž��
		int s = 0, e = N;
		while (s < e)
		{
			// �߰�����
			int mid = (s + e) / 2;

			// ���ϱ�
			if (arr[mid] == num)
			{
				isExist = true;
				break;
			}
			else if (arr[mid] < num)
			{
				s = mid + 1;
			}
			else
			{
				e = mid;
			}

		}
		cout << (isExist ? 1 : 0);
		/*if (isExist == true)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}*/
	}
}

