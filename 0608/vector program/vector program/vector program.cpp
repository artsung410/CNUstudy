#include <iostream>
#include <vector>
#include <algorithm>


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

vector<int> mathGiveUpMan1 = { 1, 2, 3, 4, 5 };
vector<int> mathGiveUpMan2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> mathGiveUpMan3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> answer =         { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

vector<int> answerCount = { 0, 0, 0 };
vector<int> mathGiveUpSequence = { 0 };

vector<int>::iterator iter;

vector<int>::iterator iter1;
vector<int>::iterator iter2;
vector<int>::iterator iter3;

vector<vector<int>::iterator> iterator3 = { iter1, iter2, iter3 };

void CopyData(vector<int> answers, vector<int> mathGiveUpMan)
{
    if (answers.size() > mathGiveUpMan.size())
    {
        int count = answers.size() / mathGiveUpMan.size();
        int n = 0;
        while (1)
        {
            if (n == count)
            {
                break;
            }
            for (int i = 0; i < mathGiveUpMan.size(); ++i)
            {
                mathGiveUpMan.push_back(mathGiveUpMan[i]);
            }
            ++n;
        }
    }
}

void AnswerCount(vector<int> answers, vector<int> mathGiveUpMan, vector<vector<int>::iterator> iterator, vector<int> answerCount)
{
    iter1 = mathGiveUpMan1.begin();
    iter2 = mathGiveUpMan2.begin();
    iter3 = mathGiveUpMan3.begin();

    for (iter = answers.begin(); iter != answers.end(); ++iter)
    {
        if (*iter = *iterator[i])
        {
            ++answerCount[0];
        }

        if (*iter = *iter2)
        {
            ++answerCount[1];
        }

        if (*iter = *iter3)
        {
            ++answerCount[2];
        }
    }

}

vector<int> solution(vector<int> answers)
{   
    CopyData(answers, mathGiveUpMan1);
    CopyData(answers, mathGiveUpMan2);
    CopyData(answers, mathGiveUpMan3);

    int* mgm[] = {mathGiveUpMan1AnswerCount, ;
    int* mgm2 = &mathGiveUpMan2AnswerCount;
    int* mgm3 = &mathGiveUpMan3AnswerCount;




    answerCount.push_back(mathGiveUpMan1AnswerCount);
    answerCount.push_back(mathGiveUpMan2AnswerCount);
    answerCount.push_back(mathGiveUpMan3AnswerCount);
    
    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}

