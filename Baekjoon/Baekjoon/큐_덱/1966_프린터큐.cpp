/*
중요도 확인
중요도 높은문서가 있으면 앞에서부터 뒤로 배치함

첫줄에 테스트케이스 수 입력
케이스의 첫번째 줄에는 문서의 개수N, 몇번째로 인쇄되었는지 궁금한 문서가 현재 que에 몇번째에 놓여있는지 나타내는 정수M이 주어짐
맨 왼쪽은 0번째
두번째 줄에는 N개의 문서의 중요도가 차례대로 1 ~ 9 중요도
같은 중요도문서 있음

출력
각 테스트 케이스에 대해 문서가 몇번째로 인쇄 되는지 출력
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
		// 입력
		int document;
		cin >> document;
		int idx;
		cin >> idx;

		// 몇번째인지 세기
		int count = 0;

		// 배열을 큐에 저장
		queue<int> printer;
		int* arr = new int[document];
		for (int i = 0; i < document; i++)
		{
			// 중요도 입력
			int imp;
			cin >> imp;

			arr[i] = imp;
			printer.push(arr[i]);
		}

		// idx입력 -> arr[idx]
		
		// 높은순으로 재정렬?


		delete[] arr;
	}
}