#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


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

int strlen(const char* str)
{
	int legnthCount = 0;
	for (int i = 0; str[i] != NULL; ++i)
	{
		++legnthCount;
	}
	return legnthCount;
}


// strchr() : ���ڿ����� Ư�� ������ ��ġ�� ã�� ��
// �Է� : ���ڿ�(const char*), ���� ã�� ����(const char)
// 1. ���ڰ� �ִ� ��� => �� ������ ��ġ
// 2. ���ڰ� ���� ��� => NULL

// strrchr()
char* strchr(const char* str, const char ch)
{

	while (*str != '\0')
	{
		if (*str == ch)
		{
			return str;
		}
		++str;
	}
	return NULL;
}


int main()
{
	////int arr[10];
	//const char * str = "// �迭�� �������� �����͸� ����ؾ� �Ѵ�.�迭�� �Ű������� �޴� �Լ��� �迭�� ũ�⸦ ���� �޴´�. ���ڿ��� ���� �� ����(Null Character)��. => ���� �迭�� ũ�⸦ ���� �ʾƵ� ���� �� �� �ִ�.�Ű����� 1�� => ���ڿ��� �����ϱ� ���� ��ü => pointer to char";
	
	const char* str = "hello";
	char ch = 'l';
	printf("%p", strchr(str, ch));

	return 0;
}

