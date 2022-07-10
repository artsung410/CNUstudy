#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    std::stack<int> s1; // ���ǿ� ���� ��� ����
    std::stack<int> s2; // �ε��� ��� ����

    int length;

    // 1. �Է�
    cin >> length;
    int* SeqArray = new int[length]; // �迭 �ʱ�ȭ

    int stackNum = 0; // ���� ���� �ʱ�ȭ
    for (int i = 0; i < length; i++)
    {
        SeqArray[i] = -1;

        cin >> stackNum; // �ѹ��� �Է¹޴´�.

        if (i == 0)
        {
            s1.push(stackNum);
            s2.push(i);
        }

        // ���� �ֻ�ܿ� �ִ� ������ ������ ������ ������

        if (s1.top() > stackNum)
        {
            s1.push(stackNum);
            s2.push(i);
        }

        else if (s1.top() <= stackNum)
        {
            while (!s1.empty() && s1.top() < stackNum)
            {
                SeqArray[s2.top()] = stackNum;
                s1.pop();
                s2.pop();
            }

            s1.push(stackNum);
            s2.push(i);
        }

    }

    // 3. ���
    for (int i = 0; i < length; i++)
    {
        cout << SeqArray[i] << ' ';
    }


    // 4. �޸� ����
    while (!s1.empty())
    {
        s1.pop();
        s2.pop();
    }

    delete[] SeqArray;

    return 0;
}