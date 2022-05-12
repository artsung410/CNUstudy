#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "function1Macro.h"

// MACRO
#define SPEED_OF_LIGHT 299792458
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT(msg) puts(#msg);
#define DECLARE_MYTYPE(typename) struct MyType##typename
#define SIMPLE_PRINT( ... ) puts(#__VA_ARGS__)
#define FORMAT_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)

// LOG
#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)


// 2���� ������ �޾� ���� �����͸� ��ȯ

//void swap(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//// islower() : �� ���� ���ڸ� �޾� �ҹ������� �Ǻ��Ѵ�.
//
//int isLower(char alphabet)
//{
//	if ( 'a' <= alphabet && alphabet <= 'z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}

//int isLower(char alphabet)
//{
//	if ('a' <= alphabet && alphabet <= 'z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

// tolower() / toupper()

//char tolower(char ch)
//{
//	ch = (int)ch + 32;
//	return ch;
//}
//
//char toupper(char ch)
//{
//	ch = (int)ch - 32;
//	return ch;
//}


// strlen() : ���ڿ��� ���̸� ���ϴ� �Լ�
// �迭�� �������� �����͸� ����ؾ� �Ѵ�.
// �迭�� �Ű������� �޴� �Լ��� �迭�� ũ�⸦ ���� �޴´�.
// ���ڿ��� ���� �� ����(Null Character)��. => ���� �迭�� ũ�⸦ ���� �ʾƵ� ���� �� �� �ִ�.
// �Ű����� 1�� => ���ڿ��� �����ϱ� ���� ��ü => pointer to char


// ��� ���ڿ��� ���̸� ���� �� ������?

// 1. str�� ���ڿ��̴�.
// 2. ���ڿ��� ���� �� ���ڴ�.

//int strlen(const char* str)
//{
//	int legnthCount = 0;
//	for (int i = 0; str[i] != NULL; ++i)
//	{
//		++legnthCount;
//	}
//	return legnthCount;
//}
//
//
//// strchr() : ���ڿ����� Ư�� ������ ��ġ�� ã�� ��
//// �Է� : ���ڿ�(const char*), ���� ã�� ����(const char)
//// 1. ���ڰ� �ִ� ��� => �� ������ ��ġ
//// 2. ���ڰ� ���� ��� => NULL
//
//// strrchr()
//char* strchr(const char* str, const char ch)
//{
//
//	while (*str != '\0')
//	{
//		if (*str == ch)
//		{
//			return str;
//		}
//		++str;
//	}
//	return NULL;
//}


int main(void)
{
	////int arr[10];
	//const char * str = "// �迭�� �������� �����͸� ����ؾ� �Ѵ�.�迭�� �Ű������� �޴� �Լ��� �迭�� ũ�⸦ ���� �޴´�. ���ڿ��� ���� �� ����(Null Character)��. => ���� �迭�� ũ�⸦ ���� �ʾƵ� ���� �� �� �ִ�.�Ű����� 1�� => ���ڿ��� �����ϱ� ���� ��ü => pointer to char";
	//
	//const char* str = "hello";
	//char ch = 'l';
	//printf("%p", strchr(str, ch));


	// 0506 MACRO
	//printf("���� �ӵ��� %d m/s�̴�. \n", SPEED_OF_LIGHT);

	//if (MIN(10 ? 5 : 4, 0 ? 1 : 10))
	//{
	//	printf("10�� 20 �߿� ���� ���� 10�Դϴ�. \n");
	//}

	//PRINT(�ȳ��ϼ���);

	//DECLARE_MYTYPE(Student)
	//{
	//	int a;
	//}a;

	//SIMPLE_PRINT(1, 'a', "Hello");
	//FORMAT_PRINT("Hellow : %d, %c, %s", 12, 'c', "Hello");

	// 0506 LOG
	printf("FILE : %s\n", __FILE__);
	printf("LINE : %d\n", __LINE__);
	printf("DATE : %s\n", __DATE__);
	printf("TIME : %s\n", __TIME__);

	if (1)
	{
		PRINT_ERROR("������ �߻��߽��ϴ�.");
	}

	return 0;
}

