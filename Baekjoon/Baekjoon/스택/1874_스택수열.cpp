#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define MAXNUM 300000

int N;
stack<int> st; // ���Ϳ��� �� �� ���� ����
vector<int> vec; // ó���� �Է°� ���� ����
vector<int> pure; // ���ľ��� ����


int arr[MAXNUM];
char ch[MAXNUM];


int flag; // ������ ���Ǹ����Ҷ��� �ø���
int cnt; // ��ȸ
int chCnt;
int loofChk;

//stack<int> vSt; // ���ľ��ϰ� 

int main()
{
	// �Է�
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
		pure.push_back(input);
	}
	
	sort(vec.begin(), vec.end()); // ���� ������
	/*st.push(vec[cnt]);
	cnt++;*/

	while (flag != N)
	{
		if (loofChk > cnt)
		{
			cout << "NO";
			return 0;
		}
		while (true)
		{
			if (st.empty())
			{
				break;
			}
			if (st.top() == pure[flag])
			{
				arr[flag] = st.top();
				st.pop();
				//cout << "-\n";
				ch[chCnt] = '-';
				chCnt++;
				flag++;
			}
			else
			{
				loofChk++;
				break;
			}
		}

		if (cnt < N)
		{
			st.push(vec[cnt]);
			cnt++;
			ch[chCnt] = '+';
			++chCnt;
			//cout << "+\n";
		}
	}

	int correct = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == pure[i])
		{
			++correct;
		}
	}

	if (correct == N)
	{
		for (int i = 0; ch[i] != '\0'; i++)
		{
			cout << ch[i] << "\n";
		}
	}

}
		// ���� ��ȸ, �Ǿ� ����
		// ���ĵ� ���͸� ���ÿ� push
		// push�� �����ʿ�?
		// ���ĵ������� ó�� ���� ������ ù��° �ε����� ������
		// ���� top�� pop�Ѵ�
		// ���� top�� ���� �����ε����� ������ �˻�
		// ������ pop �ٸ��� push�Ѵ�
		// �� ������ ���Ͱ� �������� �ݺ��Ѵ�
		// ���Ͱ� �� �� ���¿��� ���ÿ� ���ΰ��� �������Ͱ��� �ٸ���
		// NO�� ����Ѵ�

	// ���ÿ��� ���� ������ ���� �Է¹迭 ������ �ٸ��� NO �ƴϸ� �״�� ���
	

	// ���: ������ ����� ���� �ʿ��� ���� ���ٿ� �Ѱ��� push == +, pop == -, else == NO

/*
     0 1 2 3 4 5 6 7
ó��: 4 3 6 8 7 5 2 1 ����
     0 1 2 3 4 5 6 7
����: 1 2 3 4 5 6 7 8 ����
cnt		= 3
flag	= 2
push: 1 2  
pop	: 4 3
����: 1 2 5 7 8 6 3 4

		+ 1
		+ 1 2
		+ 1 2 3
		+ 1 2 3 4
		- 1 2 3 [4]
		- 1 2 [4 3]
		+ 1 2 5
		+ 1 2 5 6
		- 1 2 5 [4 3 6]
		+ 1 2 5 7
		+ 1 2 5 7 8
		- 1 2 5 7 [4 3 6 8]
		- 1 2 5 [4 3 6 8 7]
		- 1 2 [4 3 6 8 7 5]
		- 1 [4 3 6 8 7 5 2]
		- [4 3 6 8 7 5 2 1] <- ó�� �Է°��� ���´�

ó��: 1 2 5 3 4
����: 4 3 5 2 1
����: 1 2 3 4 5
		+ 1
		- [1]
		+ 2 [1]
		- [1 2]
		+ 3 [1 2]
		+ 3 4 [1 2]
		+ 3 4 5 [1 2]
		- 3 4 [1 2 5]
		- 3 [1 2 5 4] <- ó���Է°��� �ȳ���
		
*/