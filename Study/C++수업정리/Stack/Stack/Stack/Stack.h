#pragma once

class Stack
{
public:
    Stack(int size);
    ~Stack();

    // ���ÿ� value�� �����մϴ�.
    // �� �� ��� �ƹ��͵� ���� �ʽ��ϴ�.
    void Push(int value);

    // ���ÿ��� �����͸� ������, ��ȯ�մϴ�.
    // ���ÿ� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int Pop();

    // ���ÿ� ���� ���� �ִ� �����͸� ��ȯ�մϴ�.
    // ���ÿ� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int Top();

    // ������ ����ٸ� true, �ƴϸ� false�Դϴ�.
    bool IsEmpty();

    // ���� ������ ���� ��ȯ�Ѵ�.
    int Size();

private:
    int _top;
    int _arrSize;
    int* stack;
};