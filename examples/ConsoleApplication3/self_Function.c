#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int factorial(int n);
//
//
//int pibonazzi(int n);


// 10������ 2������ ?



// 3. ���� 1�� �� ������ �ݺ��Ѵ�.
// 4. ���� �������� ���� ����� ������� �������.

void binarry(int n)
{
	//3. ���� 1�� �� ������ �ݺ��Ѵ�.
	if (n == 0)
	{
		return;
	}

	// 1 . 2�� ������ ��� �������� ����Ѵ�.
	int quo = n / 2;
	int rem = n % 2;

	// 2. �ٽ� �� �� ���ؼ� 2�� ������.
	binarry(quo);

	// 4. �������� �������� ����Ѵ�.
	printf("%d", rem);
}

// binary(15) : quo(7), rem(1)
// binary(7) : quo(3), rem(1)
// binary(3) : quo(1), rem(1)
// binary(1) : quo(0), rem(1)
// binary(0) => ����

int main()
{
	int N;
	scanf("%d", &N);
	binarry(N);
	return 0;
}

//int factorial(int n)
//{
//
//	if (n == 1)
//	{
//		return 1;
//	}
//
//	return n * factorial(n - 1);
//}
//
//
//int pibonazzi(int n)
//{
//	if (n <= 1)
//	{
//		return n;
//	}
//	return pibonazzi(n - 1) + pibonazzi(n - 2);
//}


