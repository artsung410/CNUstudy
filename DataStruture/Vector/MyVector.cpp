#include "MyVector.h"

MyVector::MyVector()
{
	// �⺻������
}

MyVector::MyVector(size_t count)
	: _container(new int[count]), _size(count), _capacity(count)
{
	for (size_t i = 0; i < count; i++)
	{
		_container[i] = 0;
	}
}

// ���������. ��������
MyVector::MyVector(const MyVector& other)
	: _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
{
	for (size_t i = 0; i < _size; i++)
	{
		_container[i] = other._container[i];
	}
}

// �Ҵ翬����. ��������
MyVector& MyVector::operator=(MyVector rhs)
{
	std::swap(_container, rhs._container);
	std::swap(_size, rhs._size);
	std::swap(_capacity, rhs._capacity);

	return *this; // �ڱ��ڽ��� ��ȯ�ؼ� �⺻Ÿ��ó�� ��� ����
}

MyVector::~MyVector()
{
	MyVector::clear();
}