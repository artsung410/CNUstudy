/*
"�ʴ� 30���������� ȭ���� �����ϸ鼭 ���� ������ �ִ� Ű(A~Z)�� ǥ���ϴ� �ڵ带 �ۼ��Ͻÿ�
��� ȭ�鿡�� ���� ������ �ǽð����� ǥ�õ˴ϴ�.
1. ������ ��ȣ( 1~30���� �þ�� 31�� �Ǹ� �ٽ� 1�� �ٲ� )
2. �ʴ� ������( fps )
3. ���� ������ �ִ� ���ĺ� Ű( ��ҹ��� ���� ���� ���ĺ� ǥ�� )"
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	//float fixedTime = 1.0 / 30;
	clock_t prevTime = clock();

	while (true) // �ѹ������ 1������
	{
		clock_t currentTime = clock();

		float elapsedTime = 0;

		// �������Ӵ� �ɸ��� �ð�

		float deltaTime = (float)(currentTime - prevTime) / CLOCKS_PER_SEC;
		elapsedTime += deltaTime;

		if (elapsedTime <= 1)
		{

			cout << "������ ��ȣ : " << elapsedTime << endl;

			deltaTime = 0;
		}

		/*cout << "�ʴ� ������ : " <<  endl;

		cout << "���� ������ �ִ� ���ĺ� Ű : ";
		char input = _getch();
		cout << input << endl;
		system("cls");*/

		//Sleep(10);
	}

}