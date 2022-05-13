#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	Random_Init();

	return true;
}

void processInput()
{
	Input_Update();
}

char str[2][128];

Text text[128];
void update()
{
	//TextCopyWithWhite(text, L"Text practice", 0); //�̷��� ���δ�
	//TextCopy(text, L" ", 96);

	/*for (int32 i = 0; text[i].Char.UnicodeChar != '\0'; i++)
	{
		text[i].Attributes = TEXT_COLOR_MAGENTA | TEXT_COLOR_STRONG;
	}*/

	/*
	int32 minVal = -45;
	int32 maxVal = 32;
	int32 randInt = Random_GetNumberFromRange(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d ������ ���� : %d\n", minVal, maxVal, randInt);

	float fminVal = -12.342f;
	float fmaxVal = 25.982;
	float frand = Random_GetFNumberFromRange(fminVal, fmaxVal);
	assert(fminVal <= frand && frand <= maxVal);

	sprintf_s(str[1], sizeof(str[1]), "%f ~ %f ������ �Ǽ� : %f", fminVal, fmaxVal, frand);
	*/

	//swprintf_s ����Ұ�
	//char ��ſ� text����Ұ�
	//Text t;
	//t.Char.UnicodeChar = L'A';
}

void render()
{
	/*Renderer_DrawText(str[0], strlen(str[0]));
	Renderer_DrawText(str[1], strlen(str[1]));*/
	Renderer_Flip();
}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		// �ð��� ������Ʈ ���� ������ ���� ���� ����
		if (Timer_Update())
		{
			processInput();		// �Է� ó��
			update();			// ���� ������Ʈ
			render();			// ���� ���
		}
	}

	return 0;

}