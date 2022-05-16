#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

#include "Player.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

void setCoord(COORD* coord, int16 x, int16 y)
{
	coord->X = x;
	coord->Y = y;
}

#pragma region TitleScene
typedef struct tagTitleSceneData
{
	Text TitleText[3][128]; // �ؽ�Ʈ ���� �迭 �����ϰ�,
	COORD TitleCoords[3]; // ������ ���
} TitleSceneData;



void reset_title(TitleSceneData* data)
{
	TextCopyWithMagenta(data->TitleText[0], L"ī"); // ù���� �ؽ�Ʈ ī��
	TextCopyWithMagenta(data->TitleText[1], L"��");
	TextCopyWithMagenta(data->TitleText[2], L"��");

	setCoord(&data->TitleCoords[0], 10, 0); // ù��° �ؽ�Ʈ ������ ������Ʈ
	setCoord(&data->TitleCoords[1], 25, 10); // �ι�° �ؽ�Ʈ ������ ������Ʈ
	setCoord(&data->TitleCoords[2], 35, 20); // ������ �ؽ�Ʈ ������ ������Ʈ
}

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	reset_title(data);
}

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if (data->TitleCoords[0].Y < 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;
			
			++data->TitleCoords[0].Y;
		}
	}

	if (data->TitleCoords[2].Y > 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			--data->TitleCoords[2].Y;
		}
	}

	if (Input_GetKeyDown('R'))
	{
		reset_title(data);
	}

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_BETTING);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
 		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_title(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region BettingScene
typedef struct tagBettingSceneData
{
	Text BettingText[6][128]; // �ؽ�Ʈ ���� �迭 �����ϰ�,
	COORD BettingCoords[6]; // ������ ���
} BettingSceneData;


void reset_betting(BettingSceneData* data)
{
	TextCopyWithWhite(data->BettingText[0], L"1ȸ��"); // ù���� �ؽ�Ʈ ī��
	TextCopyWithWhite(data->BettingText[1], L"Computer : Ȳ������");
	TextCopyWithWhite(data->BettingText[2], L"Player : �뿹����");
	TextCopyWithWhite(data->BettingText[3], L"���ñݾ��� ���ÿ�");
	TextCopyWithWhite(data->BettingText[4], L"[100��]  [200��]  [300��]  [400��]  [500��]");
	TextCopyWithWhite(data->BettingText[5], L"��");

	setCoord(&data->BettingCoords[0], 5, 10);
	setCoord(&data->BettingCoords[1], 5, 12); 
	setCoord(&data->BettingCoords[2], 5, 14); 
	setCoord(&data->BettingCoords[3], 5, 16); 
	setCoord(&data->BettingCoords[4], 5, 18); 
	setCoord(&data->BettingCoords[5], 7, 20); 
}

void init_betting(void)
{
	g_Scene.Data = malloc(sizeof(BettingSceneData));

	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;

	reset_betting(data);
}

void update_betting(void)
{
	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;
	COORD coord = data->BettingCoords[5];

	if (Input_GetKeyDown(VK_LEFT))
	{
		if (coord.X > 7)
		{
			coord.X -= 9;
		}
		setCoord(&data->BettingCoords[5], coord.X, coord.Y);
	}

	if (Input_GetKeyDown(VK_RIGHT))
	{
		if (coord.X < 36)
		{
			coord.X += 9;
		}
		setCoord(&data->BettingCoords[5], coord.X, coord.Y);
	}

	if (Input_GetKeyDown(VK_RETURN))
	{
		int32 bettingAmount;
		switch (coord.X)
		{
		case(7):
			bettingAmount = 100;
			break;
		case(16):
			bettingAmount = 200;
			break;
		case(25):
			bettingAmount = 300;
			break;
		case(34):
			bettingAmount = 400;
			break;
		}
		Scene_SetNextScene(SCENE_MAIN);
	}
}

void render_betting(void)
{
	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 6; ++i)
	{
		Text* text = data->BettingText[i];
		int32 len = TextLen(text);
		COORD coord = data->BettingCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}

}

void release_betting(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region MainScene

typedef struct tagMainSceneData
{
	Text MainText[14][128]; // �ؽ�Ʈ ���� �迭 �����ϰ�,
	COORD MainCoords[14]; // ������ ���
} MainSceneData;



void reset_Main(MainSceneData* data)
{
	TextCopyWithWhite(data->MainText[0], L"��������������������������������������������������������������������������������������������������������������"); // ù���� �ؽ�Ʈ ī��
	TextCopyWithWhite(data->MainText[1], L"��	  ����	     ����	        ����	       ����	     ����");
	TextCopyWithWhite(data->MainText[2], L"��	  ����	     ����	        ����	       ����	        ��");
	TextCopyWithWhite(data->MainText[3], L"��	  ����	     ����	        ����	       ����	        ��");
	TextCopyWithWhite(data->MainText[4], L"��	  ����	     ����	        ����	       ����	        ��");
	TextCopyWithWhite(data->MainText[5], L"��	  ����	     ����	        ����	       ����	        ��");
	TextCopyWithWhite(data->MainText[6], L"��������������������������������������������������������������������������������������������������������������");
	TextCopyWithWhite(data->MainText[7], L"����������������������������������������������������������������������"); // ù���� �ؽ�Ʈ ī��
	TextCopyWithWhite(data->MainText[8], L"��	     ����	            ����	       ����	              ����                ��");
	TextCopyWithWhite(data->MainText[9], L"��	     ����	            ����	       ����	              ����                ��");
	TextCopyWithWhite(data->MainText[10], L"��	     ����	            ����	       ����	              ����                ��");
	TextCopyWithWhite(data->MainText[11], L"��	     ����	            ����	       ����	              ����                ��");
	TextCopyWithWhite(data->MainText[12], L"��	     ����	            ����	       ����	              ����                ��");
	TextCopyWithWhite(data->MainText[13], L"����������������������������������������������������������������������");


	for (int i = 0; i < 14; i++)
	{
		setCoord(&data->MainCoords[i], 0, i);
	}
}

void init_Main(void)
{
	g_Scene.Data = malloc(sizeof(MainSceneData));

	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	reset_Main(data);
}

void update_Main(void)
{

}

void render_Main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 14; ++i)
	{
		Text* text = data->MainText[i];
		int32 len = TextLen(text);
		COORD coord = data->MainCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_Main(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region EndingScene

typedef struct tagEndingSceneData
{
	Text TitleText[3][128]; // �ؽ�Ʈ ���� �迭 �����ϰ�,
	COORD TitleCoords[3]; // ������ ���
} EndingSceneData;

void reset_ending(EndingSceneData* data)
{
	TextCopyWithMagenta(data->TitleText[0], L"asdfasdf"); // ù���� �ؽ�Ʈ ī��
	TextCopyWithMagenta(data->TitleText[1], L"xcvxcv");
	TextCopyWithMagenta(data->TitleText[2], L"asdfasdf");

	setCoord(&data->TitleCoords[0], 10, 0); // ù��° �ؽ�Ʈ ������ ������Ʈ
	setCoord(&data->TitleCoords[1], 25, 10); // �ι�° �ؽ�Ʈ ������ ������Ʈ
	setCoord(&data->TitleCoords[2], 35, 20); // ������ �ؽ�Ʈ ������ ������Ʈ
}

void init_ending(void)
{
	g_Scene.Data = malloc(sizeof(EndingSceneData));

	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	reset_ending(data);
}

void update_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	if (data->TitleCoords[0].Y < 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			++data->TitleCoords[0].Y;
		}
	}

	if (data->TitleCoords[2].Y > 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			--data->TitleCoords[2].Y;
		}
	}

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}
}

void render_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_ending(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion


bool Scene_IsSetNextScene(void)
{
	if (SCENE_NULL == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scene_SetNextScene(ESceneType scene)
{
	assert(s_nextScene == SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene != SCENE_NULL);

	if (g_Scene.Release)
	{
		g_Scene.Release();
	}

	switch (s_nextScene)
	{
	case SCENE_TITLE:
		g_Scene.Init = init_title;
		g_Scene.Update = update_title;
		g_Scene.Render = render_title;
		g_Scene.Release = release_title;
		break;

	case SCENE_BETTING:
		g_Scene.Init = init_betting;
		g_Scene.Update = update_betting;
		g_Scene.Render = render_betting;
		g_Scene.Release = release_betting;
		break;

	case SCENE_MAIN:
		g_Scene.Init = init_Main;
		g_Scene.Update = update_Main;
		g_Scene.Render = render_Main;
		g_Scene.Release = release_Main;
		break;
	//case SCENE_GAMECLEAR:
	//	g_Scene.Init = init_gameclear;
	//	g_Scene.Update = update_gameclear;
	//	g_Scene.Render = render_gameclear;
	//	g_Scene.Release = release_gameclear;
	//	break;
	//case SCENE_SCOREINFO:
	//	g_Scene.Init = init_scoreinfo;
	//	g_Scene.Update = update_scoreinfo;
	//	g_Scene.Render = render_scoreinfo;
	//	g_Scene.Release = release_scoreinfo;


		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}