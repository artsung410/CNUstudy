#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int N;

const char* str[4] = 
{
    "\"����Լ��� ������?\"", 
    "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.", 
    "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
    "���� ���� ��κ� �ǾҴٰ� �ϳ�.�׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""
};

void PrintWithTab(int tabCount, const char* str)
{
    for (int i = 0; i < tabCount; ++i)
    {
        printf("____");
    }
    puts(str);
}

void Dochatbot(int count)
{
    // ���� ����
    if (count == N)
    {
        PrintWithTab(count, str[0]);
        return;
    }

}

int main()
{
    scanf("%d", &N);

    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    Dochatbot(N);
}