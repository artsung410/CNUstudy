#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{


	char text[1000001] = { 0 };
	scanf("%1000000s", text);
	// ó�� : ���� ���� ���� ���ĺ��� �������� �˾Ƴ�����.

	// �� ���ĺ��� ��� ���ƴ��� ������. => ��ü�� �ʿ��ϴ�.

	int counts[26] = { 0 };
	// Index�� ���ĺ��� ���� => ��� ���ĺ��� index�� ������ų��
	// a, A => 0
	// b, B => 1
	// c, C => 2
	// d, D => 3
	
	// 1. �ܾ �ִ� ��� ���ĺ��� ������ �� �Ŀ� �ű⼭ �ִ��� ã�´�.
	// 2. ���� ���鼭 �ִ��� ã�´�. 

	int maxCount = 0;// 3. �ִ��� ��������?
	char maxAlphabet = '\0'// 4. �׿� �����ϴ� ���ĺ��� ��������?

	//printf("%s", pickAlphabet);

	//for (int i = 0; alphabet[i] != NULL; ++i)
	//{
	//	for (int j = 0; sword[j] != NULL; ++j)
	//	{
	//		if (alphabet[i] == sword[j])
	//		{
	//			++pickAlphabet[i];
	//		}
	//	}
	//	pickAlphabet[i] = 1;
	//}

	//printf("%s", pickAlphabet);
	//for (int i = 0; pickAlphabet[i] != NULL; ++i)
	//{
	//	printf("%c ", pickAlphabet[i]);
	//}

	return 0;
}
