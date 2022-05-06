#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

void myprintf(const char* format, ...) // ...�� ���� �μ���., ù��° ���ڸ� pointer to const char�� ���� ������ printf�Լ��� ������ ���� �Ű������� pointer to const char�����̱� �����̴�.
{
	// va_list : �Լ��� ���޵Ǵ� �μ����� ���ÿ� ����Ǹ� �Լ��� ���ÿ��� �μ��� ���� ����. ���ÿ� �ִ� ���� �μ��� ���� �� ���� �а� �ִ� ������ ����ϱ� ���� ������ �����̴�.
	va_list args; 

	// va_start : format�� ����� ���ؼ� ���������� �����ּұ��� �޸𸮻��� �Ÿ��� �����ִ� ��ũ�ΰ� ����ִ�.���� �Լ� ������ ������ ���� �������� �� ù��° ������ �ּҸ� ������ �� �� �ְԵȴ�.
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char* str;
			int val;
			switch (*format)
			{

			case 'c':
				// va_arg(args, �μ�Ÿ��) : args ��ġ���� Ÿ�Կ� �´� ���� �о� �������ָ� ���� ap�� ���� ���� �μ� ��ġ�� �Ű��ش�.
				val = va_arg(args, char);
				putchar(val);
				break;

			case 's':
				str = va_arg(args, char*);
				while (*str != NULL)
				{
					putchar(*str);
					str++;
				}
				break;

			case 'd':
				val = va_arg(args, int);
				int cnt = 0;
				char arrInt[100] = { 0 };
				if (val < 0)
				{
					putchar(45);
					val = val * (-1);
				}

				while (val > 0)
				{
					arrInt[cnt] = (val % 10) + 48;
					val /= 10;
					cnt++;
					// 54321, cnt = 5
				}
				
				while (cnt > 0)
				{
					cnt--; // �ε��� 4���� �����ϱ����ؼ� cnt = 5 - 1�� �������.
					putchar(arrInt[cnt]);
				}
				break;

			case '%':
				putchar(*format);
				break;

			default:
				break;
			}
		}

		else
		{
			putchar(*format);
		}
		format++;
	}
	// �����μ��� �� ���� �� args�� NULL�� ����Ű�� �ȴ�.
	va_end(args);
}


int main ()
{
	char* str1 = "artsung12341asdf;lkjas;dfl";
	char ch = 'k';

	int val = -12345;
	int val2 = 12345;
	myprintf("char�� : %c, ���ڿ� : %s, �������� : %d �������� : %d, �Ҽ��� : ", ch, str1, val2, val);
	return 0;
}