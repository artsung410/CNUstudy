/*
"�ʴ� 30���������� ȭ���� �����ϸ鼭 ���� ������ �ִ� Ű(A~Z)�� ǥ���ϴ� �ڵ带 �ۼ��Ͻÿ�

��� ȭ�鿡�� ���� ������ �ǽð����� ǥ�õ˴ϴ�.
1. ������ ��ȣ( 1~30���� �þ�� 31�� �Ǹ� �ٽ� 1�� �ٲ� )
2. �����Ӵ� �ð�
3. ���� ������ �ִ� ���ĺ� Ű( ��ҹ��� ���� ���� ���ĺ� ǥ�� )"


*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// �� �������� ���۽ð�, ���ð����� �ʿ�

//�����ӵ�����
// ���۽ð� ~ ó�������ð�

int main()
{
	// 1. �ʱ�ȭ ����
	clock_t startTime, endTime; // 1/1000�� ������ �ð��� ���ڷ� ǥ�����ִ� �ڷ��� clock_t
	float processTime = 0.0f;
	int delayTime = 0;
	int sum = 0;
	char ch = ' ';
	int fixedFps = 30;

	while (true) // �� �������� ���ư�����
	{
		system("cls");
		// ���⼭ ���۽ð��� �����ʿ�
		startTime = clock(); // ����ð��� ��ȯ
		//cout << "start : " << startTime << endl;

		// 2. Input
		sum++;
		if (sum > fixedFps)
		{
			sum = 0;
		}

		// Ű�Է��� ������
		if (_kbhit())
		{
			ch = _getch(); // �Է�Ű���� ����.
		}


		// 4. Render
		cout << "������ ��ȣ :  " << sum << endl;

		cout << "�����Ӵ� �ð� : " << delayTime << endl;

		cout << "���� ���ĺ� Ű : " << ch << endl;

		// ��³����� ����ð��� ����
		endTime = clock();
		//cout << "end : " << endTime << endl;
		
		// ����ð� - ���۽ð� = ó���ϴµ� �ɸ� �ð�
		processTime = (float)(endTime - startTime);
		cout << "Updating... " << processTime << endl;


		delayTime = fixedFps - processTime;
		cout << "delay... " << delayTime << endl;
		// 1/30 - (����ð� - ���۽ð�)


		Sleep(delayTime);
	}

}