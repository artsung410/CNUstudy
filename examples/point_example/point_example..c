//#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdarg.h>

// My printf(1, 2 ,3) My Variadic Function : 1, 2, 3
// "My Variadic Function : ~"


//void myprintf(int count, ...)
//{
//    va_list args;
//    va_start(args, count);
//    
//
//    printf("My Variadic Function : ", count);
//    
//    for (int i = 0; i < count; ++i)
//    {
//        int number = va_arg(args, int);
//        printf(" %d", number);
//    }
//
//    va_end(args);
//}



void PrintFloats(int n, ...)
{
    int i;
    double val;
    printf("Printing floats:");
    va_list vl;
    va_start(vl, n);
    for (i = 0; i < n; i++)
    {
        val = va_arg(vl, double);
        printf(" [%.2f]", val);
    }
    va_end(vl);
    printf("\n");
}


int main()
{

    PrintFloats(3, 3.14159, 2.71828, 1.41421);
    return 0;
    // Output : Hello My Printf : 10, A, 3.14000, Hello
}

// ���� : printf�� �����ϰ� �����ϳ� ����� ���ѵ�.

//void myprintf(int count, ...)
//{
//    va_list args; // ���� ���ڸ� �ٷ� ��ü�� �����. 8����Ʈ ������(���ڵ��� ���� �迭)
//    va_start(args, count); // ���� ������ ���� ��ġ�� �˷��ش�. 
//
//    printf("My Variadic Function :");
//    for (int i = 0; i < count; ++i)
//    {
//        int number = va_arg(args, int);
//        printf(" %d", number);
//    }
//
//    va_end(args);
//}