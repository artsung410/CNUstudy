#include <iostream>


class A
{
	int _privateData;

public:
	int publicData;
};

A a;


// �޸𸮿� ǥ���Ǵ� ���� C�� ����ü�� �װͰ� ����.
// [_data(4)] [padding(4)[ _data(8)]

int main()
{
	a._privateData;
	a.publicData;

	return 0;
}