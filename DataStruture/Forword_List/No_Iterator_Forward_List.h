#pragma once

#include <stddef.h>

class ForwardList
{
public:
	// ���Ḯ��Ʈ���� �����͸� �����ϱ� ���� Ÿ��
	// ���Ḯ��Ʈ�� �����͸� �����ٷ����ʰ� ��� ��� ������ �ٷ��.
	struct Node
	{
		Node(int data = 0, Node* next = nullptr);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node();

		int		data = 0;
		Node*	Next = nullptr;

	}; // ���� �ܺο� �������� ����

public:

	// �⺻������
	ForwardList();

	// �������ȯ, count��ŭ ��Ҹ� �����ִ� �����̳ʸ� ����� ������
	// �����Լ����� �߸��������� �����ٶ߰Ը���
	explicit ForwardList(size_t count);

	// ���������
	ForwardList(const ForwardList& other);

	// �Ҵ翬����
	ForwardList& operator=(const ForwardList& rhs);

	// �Ҹ���
	~ForwardList();

	// ù��° ��� ��ȯ
	int& front();
	const int& front() const;

	// ������ ��Ҹ� ����Ű�� �����͸� ��ȯ
	Node* before_begin();
	const Node* before_begin() const;

	// ���� ��Ҹ� ����Ű�� ������ ��ȯ
	Node* begin();
	const Node* begin() const;

	// �� ���� ��Ҹ� ����Ű�� ������ ��ȯ
	Node* end();
	const Node* end() const;

	// pos������ value�� ����
	// ���Ե� ��Ҹ� ����Ű�� ������ ��ȯ
	Node* insert_after(const Node* pos, int value);

	// pos������� ����
	// ������ ����� ���� ��Ҹ� ����Ű�� �����͹�ȯ
	// �ƹ� ��ҵ� ������ end��ȯ
	Node* erase_after(const Node* pos);

	// ���ۿ�ҿ� value����
	void push_front(int value);

	// ���ۿ�� ����
	void pop_front();

	// �����̳� ������� �Ǵ�
	bool empty() const;

	// �����̳� ���
	void clear();

	// value�� �ִ��� �˻�
	bool contains(int value) const;

private:
	Node* _head = new Node();

	Node* _end = new Node();
};