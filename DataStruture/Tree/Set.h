#pragma once

class Set
{
    struct Node
    {
        Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

    

        int     Data = 0;
        Node*   Parent = nullptr;
        Node*   Left = nullptr;
        Node*   Right = nullptr;
    };

public:
    ~Set();

    // Ʈ���� ���̸� ���Ѵ�.
    int         height() const; // ť�� �̿��Ѵ�.
    int         height2() const; // ��͸� �̿��Ѵ�.

    // Ʈ���� ������� Ȯ���Ѵ�.
    bool        empty() const;

    // Ʈ���� ũ�⸦ ��ȯ�Ѵ�.
    size_t      size() const;

    // Ʈ���� ����.
    void        clear();

    // Ʈ���� ���� �����Ѵ�.
    bool        insert(int value);

    // Ʈ������ ���� �����Ѵ�.
    void        erase(int value);
    void        erase(Node* value);

    // Ʈ������ ���� ã�´�.
    Node* find(int value) const;

    // ��ȸ
    void        traverseByPreorder() const;
    void        traverseByInorder() const;
    void        traverseByPostorder() const;
    void        traverseByLevelorder() const;

private:
    void        traverseByPreorderHelper(Node* node) const;
    void        traverseByInorderHelper(Node* node) const;
    void        traverseByPostorderHelper(Node* node) const;

    int         heightHelper(Node* node) const;

private:
    Node* root() const
    {
        return _head->Parent;
    }

private:
    // head �������
    Node* _head = new Node(); // _head != root node    _head->parent�� root node ����
    size_t  _size = 0;
};
