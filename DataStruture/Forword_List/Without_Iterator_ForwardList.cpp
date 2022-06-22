#include "No_Iterator_Forward_List.h"
#include <algorithm>
// �ݺ��ڸ� ����ϸ� ���α����� ������� ������ ������ ���ҿ� �����Ϸ��Ҷ� �ϰ��� �������̽��� �����Ѵ�.

// �⺻������
ForwardList::ForwardList()
{
	_head->Next = _end;
}

// �������ȯ
ForwardList::ForwardList(size_t count)
	: ForwardList()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// ���������
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	Node* inserted = before_begin();
	for (const Node* i = other.begin(); i != other.end(); i = i->Next)
		// �ݺ��� ����ϸ� ���α��� �������� ������ ó�� �����ڸ� ���� ������ �׷��� ���� ��� �Ű����Ұ� ����.
	{
		inserted = insert_after(inserted, i->data);
	}
}

// �Ҵ翬����
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head); 
		std::swap(_end, temp._end);
	}

	return *this;
}

// �Ҹ���
ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;

	delete _end;
	_end = nullptr;
}

// ù��° ��� ��ȯ
int& ForwardList::front()
{
	return begin()->data;
}
const int& ForwardList::front() const
{
	return begin()->data;
}

// ������ ��Ҹ� ����Ű�� ��������� ��ȯ
ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}
const ForwardList::Node* ForwardList::before_begin() const
{
	return _head;
}

// ���ۿ�Ҹ� ����Ű�� ������ ��ȯ
ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}
const ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}

// �� ������Ҹ� ����Ű�� ������ ��ȯ
ForwardList::Node* ForwardList::end()
{
	return _end;
}
const ForwardList::Node* ForwardList::end() const
{
	return _end;
}

// pos������ value�� �����Ѵ�.
// ���Ե� ��Ҹ� ����Ű�� ������ ��ȯ
ForwardList::Node* ForwardList::insert_after(const Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* where = (Node*)pos;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

// pos������� ����
// ������ ����� ������Ҹ� ����Ű�� �����͹�ȯ
// �ƹ���ҵ������� end��ȯ
ForwardList::Node* ForwardList::erase_after(const Node* pos)
{
	if (empty())
	{
		return end();
	}
	
	Node* where = (Node*)pos;
	Node* removed = where->Next;

	where->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
}

// ���ۿ�ҿ� value����
void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

// ���ۿ�� ����
void ForwardList::pop_front()
{
	erase_after(before_begin());
}

// �����̳� ������� �Ǵ�
bool ForwardList::empty() const
{
	if (_head->Next == _end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �����̳� ���
void ForwardList::clear()
{
	// ������� �Ǵ��ϰ�
	// ������� ������
	while (empty() == false)
	{
		// ���ۿ�� ����
		// �������� �ݺ�
		pop_front();
	}
}

// value�� �ִ��� �˻�
bool ForwardList::contains(int value) const
{
	// ó������ ������ ��ȸ�ϸ� ã��
	// ������ true ��ȯ , ������ false��ȯ
	for (const Node* i = begin(); i != end(); i = i->Next)
	{
		if (i->data == value)
		{
			return true;
		}
	}

	return false;
}