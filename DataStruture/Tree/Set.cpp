#include "Set.h"

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

bool Set::Node::IsLeaf() const
{
	// �ڽĳ�尡 ���ٸ� true
	if (Left == nullptr && Right == nullptr) // ��, �� �Ѵ� ������ �ڽĳ�尡 ����
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Set::empty() const
{
	// ����ٸ� true
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Set::size() const
{
	return _size;
}

