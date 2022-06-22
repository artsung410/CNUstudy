#include "List.h"
#include <algorithm>

List::Node::Node(int data, Node* prev, Node* next)
	:Data(data), Prev(prev), Next(next)
{

}

List::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}

// �ݺ����� ������ ����
const int& List::const_iterator::operator*() const
{
	return _p->Data;
}
const int* List::const_iterator::operator->() const
{
	return &(_p->Data);
}

List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}
List::const_iterator List::const_iterator::operator++(int)
{
	// ���̿���
	// �ּ� �����̰�
	// �� ������ ��ȯ?

	const_iterator temp = *this;
	_p = _p->Next;

	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;

	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	const_iterator temp = *this;
	_p = _p->Prev;

	return temp;
}

bool List::const_iterator::operator==(const const_iterator& rhs) const
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

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool List::const_iterator::operator==(nullptr_t p) const
{
	if (nullptr == _p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool List::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == _p);
}

int& List::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* List::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();

	return *this;
}

List::iterator List::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();

	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();

	return *this;
}

List::iterator List::iterator::operator--(int)
{
	iterator temp = *this;
	const_iterator::operator--();

	return temp;
}

// �⺻������
List::List()
{
	_end->Next = _end;
	_end->Prev = _end;
}

// count
List::List(size_t count)
	: List()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// ���������
List::List(const List& other)
	: List()
{
	for (iterator iter = begin(); iter != end(); ++iter)
	{
		push_back(*iter);
	}
}

// ���� �Ҵ翬����
List& List::operator=(const List& rhs)
{
	if (&rhs != this)
	{
		List temp(rhs);
		std::swap(_end, temp._end);
		std::swap(_size, temp._size);
	}

	return *this;
}

// �Ҹ���
List::~List()
{
	clear();

	delete _end;
	_end = nullptr;
}

// ù��° ��� ��ȯ
int& List::front()
{
	return *begin();
}
const int& List::front() const
{
	return *begin();
}

// ������ ��� ��ȯ
int& List::back()
{
	return *(--end());
}
const int& List::back() const
{
	return *(--end());
}

// ���ۿ�ҹݺ��ڹ�ȯ
// ����Ʈ����ٸ� end�Ͱ���
List::iterator List::begin()
{
	return iterator(_end->Next);
}
List::const_iterator List::begin() const
{
	return const_iterator(_end->Next);
}

// �� ������Ҹ� ����Ű�� �ݺ��� ��ȯ
List::iterator List::end()
{
	return _end;
}
List::const_iterator List::end() const
{
	return _end;
}

// pos ������ value�� �����Ѵ�
// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
List::iterator List::insert(iterator pos, int value)
{
	Node* insertBefore = pos._p;
	Node* insertAfter = pos._p->Prev;
	Node* newNode = new Node(value, insertBefore, insertBefore);

	insertAfter->Next = newNode;
	insertBefore->Prev = newNode;

	++_size;

	return newNode;

	/*Node* newNode = new Node;
	Node* where = new Node;
	where = pos._p;

	++_size;
	
	where->Prev = newNode->Next;
	newNode->Prev = where->Prev;

	newNode->Next = pos._p;*/
}

// pos��ġ�� ��Ҹ� �����Ѵ�
// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
// �ƹ���ҵ� ������ end() ��ȯ
List::iterator List::erase(iterator pos)
{
	Node* erasePos = pos._p;
	Node* posFront = erasePos->Next;
	Node* posBefore = erasePos->Prev;

	posFront->Prev = posBefore;
	posBefore->Next = posFront;
	
	delete erasePos;

	--_size;

	return posBefore;	
}

// ���ۿ� value�� �����Ѵ�
void List::push_front(int value)
{
	insert(begin(), value);
}

// ���� value�� �����Ѵ�
void List::push_back(int value)
{
	insert(end(), value);
}

// ���ۿ�� ����
void List::pop_front()
{
	erase(begin());
}

// ����� ����
void List::pop_back()
{
	erase(_end->Prev);
}

// �����̳� ������� Ȯ��
bool List::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ����Ʈ�ȿ��ִ� ��Ұ��� ��ȯ
size_t List::size() const
{
	return _size;
}

// �����̳� ����
void List::clear()
{
	while (false != empty())
	{
		pop_front();
	}
}

// �ش� value�ִ��� üũ
bool List::contains(int value) const
{
	// ó������ ������ �ݺ��ڸ� ��ȸ�Ѵ�
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		// �ش� value�� ��Ÿ���� true��ȯ
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}