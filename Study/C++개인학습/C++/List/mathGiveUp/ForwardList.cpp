#include "ForwardList.h"
#include <math.h>
#include <utility>

// �⺻ ������
ForwardList::ForwardList()
{
	// _head-> []
	// _end-> []

	// [] -> []
	_head->Next = _end; 
}

// count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
ForwardList::ForwardList(size_t count) : ForwardList()
{
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

// ���� ������.
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	Node* inserted = before_begin();
	for (Node* iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert_after(inserted, iter->Data);
	}
}

// �Ҵ� ������
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

// ù ��° ��Ҹ� ��ȯ�Ѵ�.
int& ForwardList::front()
{
	return begin()->Data;
}

ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}


ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}

ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::Node* ForwardList::end()
{
	return _end;
}

ForwardList::Node* ForwardList::end() const
{
	return _end;
}
ForwardList::Node* ForwardList::insert_after(Node* pos, int value)
{	
	Node* newNode = new Node(value);
	Node* where = pos;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::Node* ForwardList::erase_after(Node* pos)
{
	// []->[]->[]->[]
	//   where removed
 	if (empty())
	{
		return end();
	}

	Node* where = pos;
	Node* removed = where->Next;

	where->Next = removed->Next;
	removed->Next = nullptr; // ��带 �����ش�.

	return removed;
}

void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	if (_head->Next = _end) // if(begin() == end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ForwardList::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (Node* iter = begin(); iter != end(); ++iter)
	{
		if (iter->Data == value)
		{
			return true;
		}
	}
	return false;
}