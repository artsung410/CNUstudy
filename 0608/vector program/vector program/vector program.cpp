#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// 1�� ������ : 1, 2, 3, 4, 5 //
// 2�� ������ : 2, 1, 2, 3, 2, 4, 2, 5 // 
// 3�� ������ : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 //

// �ִ�  10,000 ������ �����Ǿ��ֽ��ϴ�. == _size <= 10000
// ������ ������ 1, 2, 3, 4, 5 �� �ϳ��Դϴ�.
// ���� ���� ������ ��������� �����ϰ��, return ���� �������� �������ּ���.

// �������� ī��Ʈ�Ѱ� �迭�� ���

// �� �迭 ������� ����

// �� �迭 �ε����� �ٸ��迭�� ����. ������������
using namespace std;





// �������� ������ ���� ���������� ������ �����۾��� �Ͼ��.
void CopyData(vector<int> answers, vector<int> mathGiveUpMan)
{
    if (answers.size() > mathGiveUpMan.size())
    {
        mathGiveUpMan.reserve(mathGiveUpMan.size() + 10);
        int prevSize = mathGiveUpMan.size();
        int count = answers.size() / mathGiveUpMan.size();
        int n = 0;
        while (1)
        {
            if (n == count)
            {
                break;
            }

            for (int i = 0; i < prevSize; ++i)
            {
                mathGiveUpMan.push_back(mathGiveUpMan[i]);
            }

            ++n;
        }
    }
}

// ���䰳�� ����
void AnswerCount(vector<int> answers, vector<int> aCnt, vector<vector<int>> mgms)
{
    vector<int>::iterator iter_answer;
    vector<int>::iterator iter_mgm1;
    vector<int>::iterator iter_mgm2;
    vector<int>::iterator iter_mgm3;
    vector<int>::iterator iter_acnt;

    
    iter_mgm1 = mgms[0].begin();
    iter_mgm2 = mgms[1].begin();
    iter_mgm3 = mgms[2].begin();

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (iter_answer = answers.begin(); iter_answer != answers.end(); ++iter_answer)
    {
        if (*iter_answer == *iter_mgm1)
        {
            ++cnt1;
        }

        if (*iter_answer == *iter_mgm2)
        {
            ++cnt2;
        }

        if (*iter_answer == *iter_mgm3)
        {
            ++cnt3;
        }

        ++iter_mgm1;
        ++iter_mgm2;
        ++iter_mgm3;
    }

    aCnt.reserve(5);
    aCnt.push_back(5);
    aCnt.push_back(2);
    aCnt.push_back(3);
}

// ���䰳���� ���� �л��� ������������ ����
void sortData(vector<int> aCnt)
{
    int temp;
    for (int i = 0; i < aCnt.size(); ++i)
    {
        for (int j = 0; j < aCnt.size() - 1; j++)
        {
            if (aCnt[j] > aCnt[j + 1])
            {
                temp = aCnt[j];
                aCnt[j] = aCnt[j + 1];
                aCnt[j + 1] = temp;
            }
        }
    }
}


//vector<int> solution(vector<int> answers)
//{   
//    for (int i = 0; i < mathGiveUpMans.size(); ++i)
//    {
//        CopyData(answers, mathGiveUpMans[i]);
//    }
//
//    AnswerCount(answers, answerCount);
//
//
//    return answer;
//}

void solution(vector<int> answers, vector<vector<int>> mgms, vector<int> aCnt)
{
    for (int i = 0; i < mgms.size(); ++i)
    {
        CopyData(answers, mgms[i]);
    }

    AnswerCount(answers, aCnt, mgms);

    for (int i = 0; i < aCnt.size(); ++i)
    {
        cout << aCnt[i] << endl;
    }
}

int main()
{
    vector<int> mathGiveUpMan1 = { 1, 2, 3, 4, 5 };
    vector<int> mathGiveUpMan2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> mathGiveUpMan3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> answer = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

    vector<int> answerCount = { 0 };
    vector<int> mathGiveUpSequence = { 0 };
    vector<vector<int>> mathGiveUpMans = { mathGiveUpMan1 , mathGiveUpMan2 , mathGiveUpMan3 };

    solution(answer, mathGiveUpMans, answerCount);
}

