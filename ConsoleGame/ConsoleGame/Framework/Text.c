//#include "Text.h"
//
//void TextCopy(Text* dest, const TCHAR* src)
//{
//	while (*src)
//	{
//		dest->Char.UnicodeChar = src;
//		dest->Attributes = TEXT_COLOR_WHITE;// �̰� ����? ���ڼӼ�
//		src++;
//		dest++;
//	}
//}
//
//int32 TextLen(const Text* text)
//{
//	int32 cnt = 0;
//	while (text != '\0') // ������ ������?
//	{
//		text++;
//		cnt++;
//	}
//	return cnt;
//}

#include "Text.h"

void TextCopy(Text* dest, const WCHAR* src, WORD attributes)
{
    while (*src)
    {
        dest->Char.UnicodeChar = *src;
        dest->Attributes = attributes;

        ++dest;
        ++src;
    }
}

int32 TextLen(const Text* text)
{
    int32 result = 0;
    while (text->Char.UnicodeChar)
    {
        ++result;
        ++text;
    }

    return result;
}
