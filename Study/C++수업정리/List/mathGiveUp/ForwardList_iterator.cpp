#include "ForwardList_iterator.h"
#include <algorithm>

ForwardList::Node::Node(int data, Node* next)
	: Data(data), Next(next)
{

}

ForwardList::Node::~Node()
{
	// ��۸������Ͱ� �ȵǵ��� ����
	Next = nullptr;
}

ForwardList::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& ForwardList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* ForwardList::const_iterator::operator->() const
{
	return &(_p->Data); // �ּҰ��� ��ȯ�Ѵ�.

}

ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}

ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	// 1. p�� 1������Ű��
	// 2. ���� p�� ��ȯ�Ѵ�.

	const_iterator temp = *this;
	_p = _p->Next;

	return temp;

	// iterator�� ���������ڷ� ����� ��������� �����ϹǷ� �����ϸ� ������ ����
}

bool ForwardList::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

// �������Ϳ� ���ϴ� ������
bool ForwardList::const_iterator::operator==(nullptr_t p)const
{
	// �������͵����� : null�� ��ȣ�Զ���
	// null�� �����μ��� 0���ǰ�
	// �����ͷμ��� null�� �Ǳ⶧���� -> �����߻�����

	if (_p == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(nullptr_t p)const
{
	return !(*this == nullptr);
}

ForwardList::iterator::iterator(Node* p)
	: const_iterator(p)
{

}

int& ForwardList::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* ForwardList::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

ForwardList::iterator& ForwardList::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
}

ForwardList::ForwardList()
{
	// _head -> [something]
	// _end -> [something]

	// [something] -> [something]
	// _head->Next = nullptr;
}

// ������
ForwardList::ForwardList(size_t count)
	: ForwardList() // �⺻������
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0); // �� ��忡 0 �� �߰��Ѵ�?
	}
}

// ���������
ForwardList::ForwardList(const ForwardList& other) // �Ű������� �ڱ��ڽ��� �޴´�
	: ForwardList()
{
	iterator inserted = before_begin();
	for (const_iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert_after(inserted, *iter);
	}
}

// �����Ҵ翬����
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);

	}

	return *this;
}

// �Ҹ���
ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;
}

int& ForwardList::front()
{
	return *begin();
}

const int& ForwardList::front() const
{
	return *begin();
}

ForwardList::iterator ForwardList::before_begin()
{
	return _head; // �Ͻ�����ȯ�� �Ͼ ��ȯ������ head��밡��
}

ForwardList::const_iterator ForwardList::before_begin() const
{
	return _head;
}

ForwardList::iterator ForwardList::begin()
{
	return _head->Next;
}

ForwardList::const_iterator ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::iterator ForwardList::end()
{
	return nullptr;
}

ForwardList::const_iterator ForwardList::end() const
{
	return nullptr;
}



ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	// [] -> [] -> [] -> []
	//       pos
	//          value
	// [] -> []  [] -> []
	//        ��   �� 
	//        value

	Node* newNode = new Node(value);
	Node* where = pos._p; // �Ű������� ���� pos�� Ư�����Ҹ� ����Ŵ

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	// [] -> [] -> [] -> [*]
	//      where  removed 

	Node* where = pos._p;
	Node* removed = where->Next; // ���⼭ removed�� ������ ����.

	where->Next = removed->Next;
	// [] -> [] -> [*]
	//      where
	//          []
	//         removed
	delete removed;

	return where->Next;
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
	// if(begin() == end())
	if (_head->Next == nullptr)
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
	// �����̳� ����
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	// ó������ ������ ��ȸ�ϸ鼭 ã�´�
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}