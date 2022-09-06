#pragma once

struct Node
{
	int data;
	Node* next;
};

class MyQueue
{
public:

	// �⺻ ������
	MyQueue() = default;

	// �Ҹ���
	~MyQueue() {};

	// ���� ���� ��带 �������ϰ�, Queue ����ü�� �����Ѵ�. ť�� �ʱ�ȭ �ϴ� initQueue()�Լ��� �̿��� front�� rear�� null�� �ʱ�ȭ

	int _front();

	int _back();

	int size();

	bool isEmpty();

	void enqueue(int data);

	int dequeue();

private:
	Node* front = nullptr;
	Node* rear = nullptr;
	int count = 0;

	size_t	_size = 0;
};