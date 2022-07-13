#include <iostream>
#include <algorithm>

using namespace std;

#define CARDMAX 500000
int N;
int M;
int cardArr[CARDMAX];
int sangCard[CARDMAX];
int ans[CARDMAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// ����ī��
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cardArr[i];
	}
	// �̺�Ž�� �����ʿ�
	sort(cardArr, cardArr + N); // -10 2 3 6 10 
											//  0 1 2 3 4
											// 
	// ������� ī��
	cin >> M;


	for (int i = 0; i < M; i++)
	{
		cin >> sangCard[i];

		//int isEnd = 0;

		int sIdx = 0;
		int eIdx = N - 1;
		int midIdx = 0;
		while (sIdx <= eIdx)
		{
			midIdx = (sIdx + eIdx) / 2;

			if (sangCard[i] == cardArr[midIdx])
			{
				ans[i] = 1;
				break;
			}
			else if (sangCard[i] > cardArr[midIdx])
			{
				sIdx = midIdx + 1;
				//++isEnd;
			}
			else
			{
				eIdx = midIdx;
				//++isEnd;
			}

			// �������� ��������������
			if (sangCard[i] != cardArr[midIdx] && midIdx == eIdx && midIdx == sIdx)
			{
				//ans[i] = 0;
				break;
			}
		}

		cout << ans[i] << " ";

	}

}