#include <iostream>

using namespace std;

int main()
{
    // 1���� 100���� ���
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " ";
    }
    cout << "\n";


    int currentNumber = 1;
    for (int currentNumber = 0; currentNumber < 100; currentNumber++)
    {
        // 15�� ����� FizzBuzz�� ����ϳ�.
        if (currentNumber % 3 == 0 && currentNumber % 5 == 0)
        {
            cout << "FizzBuzz\n";
        }

        // 3�� ����� ���ڴ�� Fizz�� ����Ѵ�.
        else if (currentNumber % 3 == 0)
        {
            cout << "Fizz" << endl;
        }

        // 5�� ����� ���ڴ�� buzz�� ����Ѵ�.
        else if (currentNumber % 5 == 0)
        {
            cout << "Buzz\n";
        }

        // �� ���� ���ڴ� �״�� ����Ѵ�. 
        else
        {
            std::cout << currentNumber << "\n";
        }
    }
}
