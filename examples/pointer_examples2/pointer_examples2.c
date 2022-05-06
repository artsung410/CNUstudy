#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

void myprintf(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 0) // %다음에 0이나올수도 있으니 예외처리를 해준다.
			{
				break;
			}

			char* str; // 문자열 출력을 위한 char 타입 1차원 배열 선언
			int val; // 정수형 출력을 위한 int 타입 변수 선언.
			double dou;

			switch (*format)
			{

			case 'c':
				val = va_arg(args, int);
				putchar(val);
				break;

			case 'd':
				val = va_arg(args, int);
				int cnt = 0;
				char arrInt[100] = { 0 };

				// const int isNegative = n & (1 << 31);
				//if (isNegative)
				//{
				//	putchar('-');
				//	n -= 1;
				//	n = ~n;
				//}

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
					cnt--; // 인덱스 4부터 접근하기위해서 cnt = 5 - 1을 해줘야함.
					putchar(arrInt[cnt]);
				}
				break;

			case 's':
				str = va_arg(args, char*);
				while (*str != NULL)
				{
					putchar(*str);
					str++;
				}
				break;

			case 'f':
				dou = va_arg(args, double);
				printf("%f", dou);
				//while (*str != NULL)
				//{
				//	putchar(*str);
				//	str++;
				//}
				//break;

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
	va_end(args);
}


int main ()
{
	char* str1 = "artsung";
	char ch = 'k';
	int val = -12345;
	double pi = 3.141592;
	myprintf("char형 : %c, 문자열 : %s, 정수형 : %d, 소수형 : %f", ch, str1, val, pi);
	return 0;
}