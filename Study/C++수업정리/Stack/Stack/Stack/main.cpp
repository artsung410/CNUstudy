#include <iostream>
#include "Stack.h"

using namespace std;
int main() 
{
    Stack stack(5);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);

    while (!stack.IsEmpty())
    {
        cout << stack.Top() << endl;
        stack.Pop();
    }
    stack.Pop();

    cout << "\n";

    cout << "������ ����ֳ���? : " << boolalpha << stack.IsEmpty() << endl;

    return 0;
}