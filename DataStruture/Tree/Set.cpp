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

std::pair<Set::Node*, bool> Set::insert(int value)
{
	if (empty())
	{
		_root = new Node(value);
		++_size;

		return std::make_pair(_root, true);
	}

	// �����̶� �����ΰ�

	// �����˻�Ʈ�� - ���� ����Ʈ���� ���κ��� ���� ��, ������ ����Ʈ���� ū ��.
	// ���ؼ� ���� ��ġ�� �����ؾ��Ѵ�.
	// �����˻�Ʈ���� �̿��ؼ� ������ ���Ե� ��ġ�� ã�ư���.
	Node* currentNode = _root;
	Node* prevNode = nullptr;

	while (currentNode)
	{
		prevNode = currentNode;

		// �����˻� �����ϱ�
		// ���� ���̶�� �ش� ���� ����Ű�� ���� false ��ȯ

		if (currentNode->Data == value)
		{
			return std::make_pair(currentNode, false);
		}
		else if (currentNode->Data < value)
		{
			currentNode = currentNode->Right;
		}
		else
		{
			currentNode = currentNode->Left;
		}
		
	}

	currentNode = new Node(value, prevNode);

	// currentNode�� prevNode�� �����ڽ����� �����Ұ��� �������ڽ����� �����Ұ���
	if (prevNode->Data < value)
	{
		prevNode->Right = currentNode;
	}
	else
	{
		prevNode->Left = currentNode;
	}

	++_size;
}

void Set::erase(Node* pos)
{
	// 1. pos�� ��Ʈ�����?
	// ��Ʈ���? �θ� ����. ��, �θ� ������Ʈ
	if (pos->Parent == nullptr)
	{
		// �ڽ��� ���ٸ�
		if (pos->IsLeaf())
		{
			_root = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// ���� �ڽĸ� �ִٸ�
		if (pos->Right == nullptr)
		{
			// ���� �ڽ��� ��Ʈ�� �����
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// ������ �ڽĸ� �ִٸ�
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// �Ѵ� �ִٸ�
		// ������� �߿��� ���� ����Ѱ��� ���ο� �θ��尡 �ȴ�.
		// ���� ����Ʈ���� �ִ밪, ������ ����Ʈ���� �ּҰ�
		
	}

	// 2. pos�� ���� �����?

	// 3. pos�� ���� �ڽĸ� �ִٸ�?

	// 4. pos�� ������ �ڽĸ� �ִٸ�?

	// 5. pos�� �ڽ��� �� �� ������ �ִٸ�?
}

size_t Set::erase(int value)
{

}