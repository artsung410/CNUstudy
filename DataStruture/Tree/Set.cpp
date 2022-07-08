#include "Set.h"
#include <iostream>
#include <queue>

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

Set::~Set()
{
	clear();

	delete _head;
	_head = nullptr;
}


// Ʈ���� ����
int Set::height() const // ť ���(BFS)
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	int height = 0;
	while (false == q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node* node = q.front();
			q.pop();

			if (node->Left)
			{
				q.push(node->Left);
			}
			if (node->Right)
			{
				q.push(node->Right);
			}
		}

		++height;
	}
	return height;
}
int Set::height2() const // ��� ���
{
	if (_head->Parent == nullptr)
	{
		return -1;
	}

	return heightHelper(_head->Parent);
}
int Set::heightHelper(Node* node) const 
{
	int height = 0;
	// ��ü���� = ����Ʈ���� ���� + 1;
	if (node->Left)
	{
		height = 1 + heightHelper(node->Left);
	}

	if (node->Right)
	{
		height = std::max(height, 1 + heightHelper(node->Right));
	}

	return height;
}

// Ʈ�� ������� Ȯ��
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

// Ʈ�� ũ�� ��ȯ
size_t Set::size() const
{
	return _size;
}

// Ʈ�� ����
void Set::clear()
{
	// ��Ʈ��带 �����
	while (false == empty())
	{
		erase(_head->Parent);
	}
	return;
}

// Ʈ���� �� ����
// ���� true �ȉ�ٸ� false
bool Set::insert(int value)
{
	// ���ο��� ����
	Node* newNode = new Node(value);

	// ��Ʈ��尡 ���ٸ�? ����������Ѵ�.
	// 1. ��Ʈ��� ����
	if (_head->Parent == nullptr)
	{
		// ���� ������
		_head->Parent = newNode;
		newNode->Parent = _head;

		++_size;

		return true;
	}

	// ���Ե� ����� �θ� �˾ƾ� �����Ҽ��ִ�.
	// 2. ���Ե� ��ġ�� �θ� ��� ã��
	Node* parent = nullptr;
	Node* p = _head->Parent; // p�� �̿��� ������

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}

	// 3. ���ο� ��� ����
	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}
	newNode->Parent = parent;

	++_size;

	return true;
}

// Ʈ���� �� ����
void Set::erase(int value)
{
	// value�� ��ġ�� ���ã��
	Node* removedNode = find(value);
	if (removedNode == nullptr)
	{
		return;
	}

	// erase(pos)
	erase(removedNode);
}

void Set::erase(Node* pos)
{
	// 5 �ڽ��� �Ѵ� ������
	if (pos->Left && pos->Right)
	{
		// �ļ� ��带 �����ؾ���
		Node* successor = nullptr;
		// �����������ѹ�����
		successor = pos->Right;
		// �������� ��!
		while (successor->Left)
		{
			successor = successor->Left;
		}
		// �ļ� ����� �����͸� �����
		pos->Data = successor->Data;

		// �ļӳ�� ����
		erase(successor);

		return;
	}

	// 1 �ڽ��� ���ʸ� ������ || �Ѵ� ���ٸ�
		// �� �θ𿡴ٰ� �� �ڽ�(�ִ��� || nullptr)�� �������ش�
		// ���� ���� �θ��� ���ʿ� ������? �����ʿ� ������?
	Node** child = nullptr;
	// pos�� ��Ʈ�����?
	if (pos == _head->Parent)
	{
		child = &_head->Parent;
	}
	// ��������ϴ� ��尡 ��Ʈ����� �ڽ��ΰ�� || ���� �����ʿ� ��ġ�Ѱ��
	else if (pos->Data < pos->Parent->Data)
	{
		child = &pos->Parent->Left;
	}
	// ���� ���ʿ� ��ġ�Ѱ��
	else
	{
		child = &pos->Parent->Right;
	}

	// �θ� �� �ڽ��� �����Ѵ�
	*child = nullptr;
	if (pos->Left)
	{
		*child = pos->Left;
		pos->Left->Parent = pos->Parent;
	}
	else if(pos->Right)
	{
		*child = pos->Right;
		pos->Right->Parent = pos->Parent;
	}
	
	delete pos;
	--_size;
}

// Ʈ������ �� ã�´�
Set::Node* Set::find(int value)	const
{
	Node* result = _head->Parent;

	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if(result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}

	return result;
}

// ������ȸ ����
void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}
// �� �ڽŸ��� �湮: ������ȸ
void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

// ������ȸ ����
void Set::traverseByInorderHelper(Node* node) const
{
	// �� -> �ڱ��ڽ� -> ��

	if (node == nullptr)
	{
		return;
	}
	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}
// ������ȸ
void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

// ������ȸ ����
void Set::traverseByPostorderHelper(Node* node) const
{
	// �� -> �� -> �ڱ��ڽ�

	if (node == nullptr)
	{
		return;
	}
	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}
// ������ȸ
void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

// ������ȸ (DFS)
void Set::traverseByLevelorder() const
{
	std::queue<Node*> que;
	if (_head->Parent)
	{
		que.push(_head->Parent);
	}

	while (que.empty() == false)
	{
		Node* node = que.front();
		que.pop();

		std::cout << node->Data << "->";

		if (node->Left)
		{
			que.push(node->Left);
		}

		if (node->Right)
		{
			que.push(node->Right);
		}
	}

}





