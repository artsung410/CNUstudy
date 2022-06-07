//-------------------------------------------------------------------------------------------------
// ���� (vector) Ŭ���� �����ϱ�
//
// �� header ���Ͽ�����, ���� �Ի��������� ����������, ������ ���͸� �����ϱ� ����,
// MyVector ��� Ŭ������ �����ϰ� �ֽ��ϴ�.
//
// �ҽ��� �ּ��� �����Ͽ�, �ʿ��� ��ɵ��� �����Ͽ�,
// MyVector.h ���ϰ� MyVector.cpp, 2���� ������ �������ֽø� �˴ϴ�.
// (�����Ͻô� ���ϵ��� ���ڵ��� utf-8 �� �����ֽø� �����ϰڽ��ϴ�.)
//
// ����: std::vector �� ����, �̹� ������ ���͸� ���δ½����� �������� ���ð�,
//    ���� �ڽ��� �ڵ�� ����� ���� ��Ź�帳�ϴ�.
//
// ����: ����� �ۼ��� �κ��� ���� �Ϳ� ���� ������ �帮�ڸ�,
//    ���� �Ƿ��� �߿��ϰ� ����ٱ� ���ٴ�, �����⸦ ������ ���� �ѱ� ������ ã��,
//    ��� �ؼ��� ������ ������, ����/�н��ϴ� �ɷ��� �߿��ϱ� �����Դϴ�.
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// ���Ͷ�? (http://www.cplusplus.com/reference/vector/vector/)
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers
// to its elements, and just as efficiently as in arrays. But unlike arrays,
// their size can change dynamically, with their storage being handled automatically
// by the container.
//
// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.
//
// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to
// contain its elements (i.e., its size). Libraries can implement different strategies for growth
// to balance between memory usage and reallocations, but in any case,
// reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with
// amortized constant time complexity.
//-------------------------------------------------------------------------------------------------

#include <string>
#include <utility>

//-------------------------------------------------------------------------------------------------
// MyVector �� �����ϴ� ������Ʈ
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector Ŭ����.
//-------------------------------------------------------------------------------------------------
class MyVector
{
private:

    MyObject* _MyObjs = nullptr; // ������ ũ��
    size_t _size = 0; // ������ ����
    size_t _capacity = 0; // ������ �뷮

public:

    // Constructor.
    MyVector(int capacity) : _capacity(capacity)
    {}

    // Copy constructor. -> �ʵ尪�鿡 �� �Ҵ������ ����. 
    MyVector(const MyVector& other) : _MyObjs(new MyObject[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _MyObjs[i] = other._MyObjs[i];
        }
    }

    // Assignment operator.
    MyVector& operator=(const MyVector& other)
    {
        _MyObjs = other._MyObjs;
        _size = other._size;
        _capacity = other._capacity;
    }

    // Destructor.
    ~MyVector()
    {
        clear();
    }

public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

    // Returns current capacity of this vector.
    int GetCapacity() const
    {
        return _capacity;
    }

    // Returns current size of this vector.
    int GetSize() const
    {
        return _size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id)
    {
        if (_capacity == _size)
        {
            return;
        }

        MyObject* MyObj = new MyObject;
        MyObject* MyObjs = new MyObject[_capacity];

        MyObj->_id = id;

        for (size_t i = 0; i < _capacity; i++)
        {
            MyObjs[i] = _MyObjs[i];

            if (i == (_size + 1))
            {
                MyObjs[i] = *MyObj;
            }
        }
    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        for (int i = 0; i < _size; i++)
        {
            if (_MyObjs[i]._id == MyObjectId)
            {
                return &_MyObjs[i];
            }
        }
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()
    {
        if (_capacity == _size)
        {
            return;
        }

        _capacity = _size;
    }

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index)
    {
        return _MyObjs[index];
    }

    // Returns string representation of the vector.
    //std::string ToString() const
    //{
    //    std::string myStr;
    //    for (int i = 0; i < _size; i++) 
    //    {
    //        _MyObjs
    //    }
    //    return myStr;
    //}

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        for (int i = 0; i < _size; i++)
        {
            if (_MyObjs[i]._id == MyObjectId)
            {
                delete &_MyObjs[i];
            }
        }
    }

    // Returns a newly allocated array of MyVector objects,
    // 
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups)
    {
    }

    void clear()
    {
        delete[] _MyObjs;
        _MyObjs = nullptr;
        _size = 0;
        _capacity = 0;
    }
};


int main()
{

}
