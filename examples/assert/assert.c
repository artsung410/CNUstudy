#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// ���� �����
int main(void)
{
    //// 1. ������ �ٷ�� ���� ��ü ����
    //FILE* fp = NULL;

    //// -------------------------------
    //// �ؽ�Ʈ ����
    //// -------------------------------

    //// 2. ������ ����.
    //// 1) �ؽ�Ʈ ���� : �ؽ�Ʈ �����ͷ� �� �� �ִ� ���Ϸ� �츮�� ���� �� �ִ� ���ڷ� ����
    //// 2) ���̳ʸ� ���� : �� ���� ��� ����

    //// Metaverse��� �̸��� ���� �ؽ�Ʈ ������ ����.
    //if (0 != fopen_s(&fp, "Metaverse", "w"))
    //{
    //    printf("���� �߻���.");

    //    return 1;
    //}

    //// 3. ������ �����Ѵ�.
    //// �ؽ�Ʈ ���Ͽ� �ۼ��� �� �ִ� �Լ� : fputs() / fputc() / fprintf()
    //// ���̳ʸ� ���Ͽ� �ۼ��� �� �ִ� �Լ� : fwrite()
    //fputs("Hello File!", fp);
    //fputc('J', fp);
    //fprintf(fp, "\nThe name of the queen : %s\n", "������");

    //// 4. ������ �ݴ´�.
    //fclose(fp);

    //if (0 != fopen_s(&fp, "Metaverse", "r"))
    //{
    //    printf("���� �߻���.");

    //    return 1;
    //}

    //// �ؽ�Ʈ ���Ͽ��� �о���� �� �ִ� �Լ� : fgets() / fgetc() / fscanf()
    //// ���̳ʸ� ���Ͽ��� �о���� �� �ִ� �Լ� : fread()
    //char ch = fgetc(fp);
    //char str[128] = "";
    //fgets(str, sizeof(str), fp); // ���� ���ڱ��� �޾Ƶ��δ�.
    //char str2[128] = "";
    //fscanf_s(fp, "The name of the queen : %s", str2, sizeof(str2));

    //printf("�о���� ���� : %c\n", ch);
    //printf("�о���� ���ڿ� : %s\n", str);
    //printf("���� ����? : %s\n", str2);

    //fclose(fp);

    //// -------------------------------
    //// ���̳ʸ� ����
    //// -------------------------------
    //if (0 != fopen_s(&fp, "Metaverse2", "wb"))
    //{
    //    printf("���� �߻���.");

    //    return 1;
    //}

    //struct Student
    //{
    //    int Age;                  // 4����Ʈ
    //    enum { A, B, O, AB } BloodType;
    //    char Name[24];
    //};

    //struct Student s = { 20, A, "�ּ���" };

    //if (1 != fwrite(&s, sizeof(s), 1, fp))
    //{
    //    printf("���� �߻���.");

    //    fclose(fp);

    //    return 1;
    //}

    //fclose(fp);

    //if (0 != fopen_s(&fp, "Metaverse2", "rb"))
    //{
    //    printf("���� �߻���.");

    //    fclose(fp);

    //    return 1;
    //}

    //struct Student s2 = { 0 };
    //if (1 != fread(&s2, sizeof(s2), 1, fp))
    //{
    //    printf("���� �߻���.");

    //    fclose(fp);

    //    return 1;
    //}

    //printf("���� : %d, ������ : %d, �̸� : %s\n", s2.Age, s2.BloodType, s2.Name);

    //fclose(fp);

    //return 0;

    //const char* input = "�� �ô��� ������ ���� ����? ������";

    //char str[128] = "";
    //sscanf_s(input, "�� �ô��� ������ ���� ����? %s", str, (unsigned int)sizeof str);

    //char str2[128] = "";
    //sprintf_s(str2, sizeof(str2), "�׷���. ���� %s����.", str, sizeof str);

    //puts(str2);

    //return 0;

    printf("�ʿ��� ���� ��������")
    int* p = malloc(sizeof(int));


    //�޸𸮸� �������� 
    return 0;
}
