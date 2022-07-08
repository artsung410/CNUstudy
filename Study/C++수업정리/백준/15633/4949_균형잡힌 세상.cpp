#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        // 1. �Է�
        std::string inputStr;
        getline(cin, inputStr);


        // ���ڰ� �ϳ��� ���϶� Ż��..
        std::stack<char> s;
        bool result = true;

        if (inputStr == ".")
        {
            break;
        }

        // // 2. ó�� : ���ÿ� ��Ҹ� ��´�.
        for (int i = 0; i < inputStr.length(); i++)
        {
            if (inputStr[i] == '(' || inputStr[i] == '[')
            {
                s.push(inputStr[i]);
            }

            if (inputStr[i] == ')')
            {
                if (s.empty() || s.top() == '[')
                {
                    result = false;
                }
                else
                {
                    s.pop();
                }

            }

            if (inputStr[i] == ']')
            {
                if (s.empty() || s.top() == '(')
                {
                    result = false;
                }
                else
                {
                    s.pop();
                }
            }
        }

        if (s.empty() && result)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }

    }
    return 0;
}