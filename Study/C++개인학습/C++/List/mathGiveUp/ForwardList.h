#pragma once
#include <stddef.h>

class ForwardList
{       
    // ���� ����Ʈ���� �����͸� �����ϱ� ���� Ÿ��
    // ��, ���� ����Ʈ�� �����͸� ���������� �ٷ�� ���� �ƴ϶�
    // Node��� ������ �ٷ�ϴ�.
    struct Node 
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int   Data = 0;         // ���� ������
        Node* Next = nullptr;   // ���� ����
    };

public:
    // �����͸� ������ �� ���� �ݺ���.
    // const int* 

    // ������ ������ ������ �ݺ���
    // int*

    // �⺻ ������
    ForwardList();

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit ForwardList(size_t count);

    // ���� ������.
    ForwardList(const ForwardList& other);

    // �Ҵ� ������
    ForwardList& operator=(const ForwardList& rhs);

    // �Ҹ���
    ~ForwardList();

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_begin();

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* begin();
    Node* begin() const;

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* end();
    Node* end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value);

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos);

    // ���� ��ҿ� value�� �����Ѵ�.
    void                push_front(int value);

    // ���� ��Ҹ� �����Ѵ�.
    void                pop_front();

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool                empty() const;

    // �����̳ʸ� ���������.
    void                clear();

    // value�� �ִ��� �˻��Ѵ�.
    bool                contains(int value) const;
private:
    // ���� ���; ���� �����͸� ���� ����. ������ ������ ���Ǽ����� ���ؼ� ����.
    Node* _head = new Node(); // before_begin()

    // ���� ���
    Node* _end = new Node(); // end()
};
