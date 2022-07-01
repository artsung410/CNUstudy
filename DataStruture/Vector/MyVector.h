#pragma once

#include <utility>
class MyVector
{
public:
    // �⺻ ������
    MyVector();

    // count��ŭ ������ �Ҵ�� ������
    explicit MyVector(size_t count);
    //    : _container(new int[count]), _size(count), _capacity(count)
    //{
    //    for (size_t i = 0; i < count; i++)
    //    {
    //        _container[i] = 0; //�⺻�� �Ҵ�
    //    }
    //}

    // ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector(const MyVector& other);
    /*    : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }*/

    // �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector& operator=(MyVector rhs);
    //{
    //    std::swap(_container, rhs._container);
    //    std::swap(_size, rhs._size);
    //    std::swap(_capacity, rhs._capacity);
    //
    //    return *this; // �ڱ��ڽ��� ��ȯ����� �⺻Ÿ��ó�� ����Ҽ����� 
    //    /*
    //        int a, b;
    //        a = b = 5; ����
    //            a.operator=(b.operator(5)); 
    //
    //        vector v1, v2, v3;
    //        v1 = v2 = v3; ����
    //            v1.operator=(v2.operator(v3));
    //    */
    //}

    // �Ҹ��� : �ڿ�����
    ~MyVector();
    /*{
        clear();
    }*/

    // ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�. ��� �����̳ʿ��� �������ִ�
    int* begin()
    {
        // ���Ͱ� ����ִٸ� end() ��ȯ
        if (empty())
        {
            return end();
        }

        // ��������ʴ´ٸ� ù��° ���Ҹ� ����Ű�� �ݺ��� ��ȯ. �����͸� ��ȯ�Ϸ��� �ּҰ��� �Ѱ��ָ�ȴ�
        return _container;
    }
    const int* begin() const
    {
        //�ڵ��ߺ��� �����ϱ����� ����� ���� ���ú���
        // ���Ͱ� ����ִٸ� end() ��ȯ
        if (empty())
        {
            return end();
        }

        // ��������ʴ´ٸ� ù��° ���Ҹ� ����Ű�� �ݺ��� ��ȯ. �����͸� ��ȯ�Ϸ��� �ּҰ��� �Ѱ��ָ�ȴ�
        return _container;
    }

    // ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    int* end()
    {
        // _container : �����̳��� �ּ�
        // _size : ���簡�����ִ� ���Ұ���
        // _capacity : �ִ������ ����
        return _container + _size;
    }
    const int* end() const { return _container + _size; }

    // �����̳ʰ� ������� �˻��Ѵ�.
    bool                empty() const
    {
        if (0 == _size) // bigin() == end() ����
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // ������ ������ ��ȯ�Ѵ�.
    size_t              size() const { return _size; }

    // ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t              capacity() const { return _capacity; }

    //// pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�. ���� pos�� �������� ����� std::out_of_range ���ܰ� ��������.
    //int& at(size_t pos);
    //const int& at(size_t pos) const; ����ó���ȹ��

    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
    // vetor<int> v;
    // vector[2]
    int& operator[](size_t pos)
    {
        return _container[pos];
    }
    const int& operator[](size_t pos) const
    {
        return _container[pos];
    }

    // �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�. ����ִ��� �� ����ִ��� �˻����ʿ����?
    int& front()
    {
        return *begin(); //beginŸ���� �����Ϳ��� ������������ ����
    }
    const int& front() const
    {
        return *begin();
    }

    // �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
    int& back()
    {
        return *(end() - 1);
    }
    const int& back() const
    {
        return *(end() - 1);
    }

    // �����̳ʸ� ����.
    void                clear()
    {
        delete[] _container;
        //������ ��ȿȭ�ȿ����� ������ = ��۸�������
        // ��۸������Ϳ� �������ϸ� ��������. �������ͷ� �ٲ�����Ѵ�
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }

    // pos "����" ��ġ�� value�� �����Ѵ�.
    // value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
    int* insert(int* pos, int value)
    {
        //��� �ŰܾߵǴ��� �˾ƾ��ϰ�
        // capacity�� �˾ƾ��Ѵ� -> ���ο����Ȯ���� �̵�
        
        //1. ó�����κ��� �󸶳� �������ִ��� Ȯ��
        int distance = pos - begin(); 

        //2. �뷮Ȯ��
        if (_capacity == 0)
        {
            //��뷮�̶�� �뷮�Ҵ�
            reserve(1);

            // ���� ��ġ �����
            pos = begin() + distance;
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2); // ����ȿ������ 2��

            pos = begin() + distance; //��ġ���������
        }

        //3. ����
        for (int* iter = end(); iter != pos; iter--) //end���ͽ����� �����ϸ鼭
        {
            *iter = *(iter - 1); // �ڷ� �о��ش�
        }
        *pos = value; //pos�� ���Ե� ���� ����Ű�� �ݺ���

        //4. �ʵ� ������ �ֽ�ȭ
        ++_size;

        return pos; // ����Ű�� �����͸� ��ȯ�Ѵ�.
    }

    // pos�� ��ġ�� ���Ҹ� �����.
    // ������ ����� ���� �����͸� ��ȯ�Ѵ�.(��ġ�� ����������)
    int* erase(int* pos)
    {
        // If[first, last) is an empty range, then last is returned.
        // 1. ����ִٸ� end��ȯ
        if (_size == 0)
        {
            return end();
        }
        // If last == end() prior to removal, then the updated end() iterator is returned.
        // 2. ������ �̵�(����)
        int* last = end() - 1;
        for (int* iter = pos;  iter != last;  iter++)
        {
            *iter = *(iter + 1);
        }
        
        // 3. �ʵ� ������Ʈ
        --_size;

        return pos;
    }

    // �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
    void                push_back(int value)
    {
        insert(end(), value);
    }

    // �����̳��� ������ ���Ҹ� �����Ѵ�.
    void                pop_back()
    {
        erase(end() - 1);
    }

    // value�� �����ϴ��� �˻��Ѵ�.
    bool                contains(int value)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i] == value)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
    // newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
    // �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.
    //reserve() does not change the size of the vector. reserve�� ������ ����� �ٲ��� �ʴ´�
    /*
    reserve�ϸ� ���ο� �������Ҵ���(�޸��ּҴٸ�)
    �Ҵ��� ���� �޸𸮴� free�Ѵ�
    iter�� ��۸������Ͱ� �Ǹ鼭�� ������
    */
    void                reserve(size_t newCapacity)
    {
        //1. newCapacity�� _capacity���� ū�� ũ���
        if (newCapacity >= _capacity)
        {
            int* temp;
            //2. ���ο�޸��Ҵ�
            temp = new int[newCapacity];

            for (size_t i = 0; i < _size; i++)
            {
             //3. �����޸𸮵����� ����
                temp[i] = _container[i];
            }
             //4. �����޸� ����
            delete[] _container;

            //5. �ʵ� ������ ���� _capacity = newCapacity;
            _container = temp;
            _capacity = newCapacity;
        }
    }

private:
    int*    _container = nullptr; // �����̳��� �ּ�
    size_t  _size = 0;            // ���簡�����ִ� ���Ұ���
    size_t  _capacity = 0;        // �ִ������ ����
};
