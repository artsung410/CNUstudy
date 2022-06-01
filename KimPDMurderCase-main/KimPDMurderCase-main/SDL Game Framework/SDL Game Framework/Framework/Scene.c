#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "CsvParser.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

#pragma region TitleScene

typedef struct TitleSceneData
{
	Image	TitleBackGroundImage;
	Image	GameStartImage;
	Image	CursorImage;
	COORD	CursorPos;
	Music	BGM;
} TitleSceneData;

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));
	memset(g_Scene.Data, 0, sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Image_LoadImage(&data->TitleBackGroundImage, "TitleImage.png");
	Image_LoadImage(&data->GameStartImage, "GameStartImage.png");
	Image_LoadImage(&data->CursorImage, "CursorImage.png");

	Audio_LoadMusic(&data->BGM, "Background.mp3");
	Audio_Play(&data->BGM, INFINITY_LOOP);
}

#define GameStartPosX 528
#define GameStartPosY 533

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if ((Input_GetKeyDown(VK_UP) || Input_GetKeyDown(VK_DOWN)) && data->CursorPos.X == 0 && data->CursorPos.Y == 0)
	{
		data->CursorPos.X = GameStartPosX;
		data->CursorPos.Y = GameStartPosY;
	}
	else if ((Input_GetKeyDown(VK_UP) || Input_GetKeyDown(VK_DOWN)) && data->CursorPos.X != 0 && data->CursorPos.Y != 0)
	{
		data->CursorPos.X = 0;
		data->CursorPos.Y = 0;
	}

	if (Input_GetKeyDown(VK_SPACE) && data->CursorPos.X == GameStartPosX && data->CursorPos.Y == GameStartPosY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->TitleBackGroundImage, 0, 0);
	Renderer_DrawImage(&data->GameStartImage, 559, 545);

	if (data->CursorPos.X != 0 && data->CursorPos.Y != 0)
	{
		Renderer_DrawImage(&data->CursorImage, data->CursorPos.X, data->CursorPos.Y);
	}
}

void release_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Audio_FreeMusic(&data->BGM);
	SafeFree(g_Scene.Data);
}
#pragma endregion

#pragma region ContentScene
typedef struct tagConetentSceneData {
	int32		id;
	Image		BackGroundImage;
	Image		BackPaper;
	Image		CursorImage;
	Music		BGM;
	SoundEffect Effect[2];
	Text		TitleLine[1];
	Text		TextLine[TEXTLINE_COUNT];
	Text		SelectLine[3];
	int32		CursorX;
	int32		CursorY;
	int32		X;
	int32		Y;
} ContentSceneData;

static int32 id[83] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82};
static int32 n = 0;


#define CursorpointY 485
#define CursorpointY_1 545
#define CursorpointY_2 605 

void init_content(void)
{
	g_Scene.Data = malloc(sizeof(ContentSceneData));
	memset(g_Scene.Data, 0, sizeof(ContentSceneData));

	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Image_LoadImage(&data->BackGroundImage, ReturnBackGroundImage(id[n]));
	Image_LoadImage(&data->BackPaper, "BackPaper.png");
	Image_LoadImage(&data->CursorImage, ReturnCursorImageImage(id[n]));

	Audio_LoadMusic(&data->BGM, ReturnBGM(id[n]));
	Audio_Play(&data->BGM, INFINITY_LOOP);
	
	data->CursorX = 30;
	data->CursorY = 485;


	for (int32 i = 0; i < 2; i++)
	{
		if (SoundEffectExisted(id[n], i))
		{
			Audio_LoadSoundEffect(&data->Effect[i], ReturnSoundEffect(id[n], i));
			Audio_PlaySoundEffect(&data->Effect[i], 1);
		}
	}

	if (TitleExisted(id[n]))
	{
		wchar_t* title = ReturnTitleText(id[n]);
		Text_CreateText(&data->TitleLine[0], "GongGothicMedium.ttf", 40, title, wcslen(title));
	}

	for (int32 i = 0; i < TEXTLINE_COUNT; i++)
	{
		wchar_t* content = ReturnContentText(id[n], i);
		Text_CreateText(&data->TextLine[i], "GongGothicLight.ttf", 20, content, wcslen(content));
	}

	for (int32 i = 0; i < 3; i++)
	{
		if (SelectExisted(id[n], i)) 
		{
			Text_CreateText(&data->SelectLine[i], "GongGothicMedium.ttf", 30, ReturnSelect(id[n], i), wcslen(ReturnSelect(id[n], i)));
		}
	}



}
static bool a = false;
void update_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	// Ŀ���̵�
	if ((Input_GetKeyDown(VK_DOWN)) && data->CursorX == 30 && data->CursorY == CursorpointY)
	{
		data->CursorY = CursorpointY_1;
	}
	else if ((Input_GetKeyDown(VK_UP)) && data->CursorX == 30 && data->CursorY == CursorpointY_1)
	{
		data->CursorY = CursorpointY;
	}
	else if ((Input_GetKeyDown(VK_DOWN)) && data->CursorX == 30 && data->CursorY == CursorpointY_1)
	{
		data->CursorY = CursorpointY_2;
	}
	else if ((Input_GetKeyDown(VK_UP)) && data->CursorX == 30 && data->CursorY == CursorpointY_2)
	{
		data->CursorY = CursorpointY_1;
	}

	if (Input_GetKeyDown(VK_SPACE) && id[n] == 1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 1;
	}

	if (id[n] == 2 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 2;
	}

	if (id[n] == 3 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 6;
	}
	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 7;
	}
	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 7 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 8 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 8;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 9;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 5;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 10;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 11;
	}

	if (id[n] == 8 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 9 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 10 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 5;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 2;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 12;
	}

	if (id[n] == 12 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 16;
	}

	if (id[n] == 12 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 17;
	}
	
	if (id[n] == 12 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 12;
	}

	if (id[n] == 17 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 25;
	}

	if (id[n] == 17 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 26;
	}

	if (id[n] == 17 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 11;
	}

	if (id[n] == 26 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 16;
	}

	if (id[n] == 27 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 16;
	}

	//���ǵ� �繫�� -å��������
	if (id[n] == 18 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 27;
	}
	// Ȯ�οϷ�
	if (id[n] == 28 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 17;
	}

	//���ǵ� �繫�� -������ �����
	if (id[n] == 18 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 28;
	}
	//Ȯ�οϷ�
	if (id[n] == 29 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 17;
	}

	//������ҷ�
	if (id[n] == 18 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 11; 
	}

	//��ȭ��Ʈ��
	if (id[n] == 13 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 18;
	}

	// Ȯ�οϷ�
	if (id[n] == 19 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 12;
	}

	//�Ϸ����� ���ҷ�
	if (id[n] == 13 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 19;
	}

	// �Ϸ��� å����
	if (id[n] == 20 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 29;
	}

	// Ȯ�οϷ�
	if (id[n] == 30 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 19;
	}

	// �Ϸ��� ������
	if (id[n] == 20 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 30;
	}

	// Ȯ�οϷ�
	if (id[n] == 31 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 19;
	}

	// �ٸ�����ã��
	if (id[n] == 20 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 20;
	}

	// �ٸ�����ã�� �����ٹ�
	if (id[n] == 21 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 31;
	}

	// �ٸ�����ã�� �����ٹ� Ȯ�οϷ�
	if (id[n] == 32 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 20;
	}

	// �ٸ�����ã�� ���� Ȯ��
	if (id[n] == 21 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 32;
	}

	// �ٸ�����ã�� ���� Ȯ��
	if (id[n] == 33 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 20;
	}

	// �ٸ�����ã�� Ȯ�οϷ�
	if (id[n] == 21 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 12;
	}

	//������ҷ�
	if (id[n] == 13 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 13;
	}

	// �����ڵ� ���ھ�
	if (id[n] == 14 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 21;
	}

	// �����ڵ� ���ھ� å������
	if (id[n] == 22 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 33;
	}

	// �����ڵ� ���ھ� å������ Ȯ�οϷ�
	if (id[n] == 34 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 21;
	}

	// �����ڵ� ���ھ� ��������
	if (id[n] == 22 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 34;
	}

	// �����ڵ� ���ھ� �������� Ȯ�οϷ�
	if (id[n] == 35 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 21;
	}

	// �����ڵ� ���ھ� Ȯ�οϷ�
	if (id[n] == 22 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 13;
	}

	// �����ڵ� �������� ��
	if (id[n] == 14 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 22;
	}

	// �����ڵ� �������� �� ���۰���
	if (id[n] == 23 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 35;
	}

	// �����ڵ� �������� �� ���۰��� Ȯ�οϷ�
	if (id[n] == 36 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 22;
	}

	// �����ڵ� �������� �� ������
	if (id[n] == 23 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 36;
	}

	// �����ڵ� �������� �� ������ Ȯ�οϷ�
	if (id[n] == 37 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 22;
	}

	// �����ڵ� �������� �� Ȯ�οϷ�
	if (id[n] == 23 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 13;
	}

	// ���� ��ҷ� �ڰ��� ����� ��ü���Ȯ��
	if (id[n] == 14 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 14;
	}

	// �����ڵ� �ڰ�����
	if (id[n] == 15 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 23;
	}

	// �����ڵ� �ڰ����� å����
	if (id[n] == 24 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 37;
	}

	// �����ڵ� �ڰ����� å���� Ȯ�οϷ�
	if (id[n] == 38 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 23;
	}

	// �����ڵ� �ڰ����� ������
	if (id[n] == 24 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 38;
	}

	// �����ڵ� �ڰ����� ������ Ȯ�οϷ�
	if (id[n] == 39 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 23;
	}

	// �����ڵ� �ڰ����� Ȯ�οϷ�
	if (id[n] == 24 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 14;
	}

	// �����ڵ� �����繫��
	if (id[n] == 15 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 24;
	}

	// �����ڵ� �����繫�� å����
	if (id[n] == 25 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 39;
	}

	// �����ڵ� �����繫�� å���� Ȯ�οϷ�
	if (id[n] == 40 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 24;
	}

	// �����ڵ� �����繫�� ������
	if (id[n] == 25 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 40;
	}

	// �����ڵ� �����繫�� ������ Ȯ�οϷ�
	if (id[n] == 41 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 24;
	}

	// �����ڵ� �����繫�� Ȯ�οϷ�
	if (id[n] == 25 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 14;
	}

	// �����ڵ� ��ü��� Ȯ�οϷ� �� ������ Ž��
	if (id[n] == 15 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 15;
	}
	
	// �����ڵ� Ž���Ͽ� ���� Ȯ���ϱ�
	if (id[n] == 16 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 41;
	}

	// �ٽ� ���캸��
	if (id[n] == 16 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 11;
	}

	// �����ڵ� Ž���Ͽ� ���� Ȯ���ϱ�
	if (id[n] == 16 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 41;
	}

	// ���ھ� �ǽ�
	if (id[n] == 42 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 44;
	}

	// ���ھ� �ǽ� Ȯ�οϷ�
	if (id[n] == 45 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 41;
	}

	// �����׾� �ǽ�
	if (id[n] == 42 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 45;
	}

	// �����׾� �ǽ� Ȯ�οϷ�
	if (id[n] == 46 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 41;
	}

	// ���� �����ڷ�
	if (id[n] == 42 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 42;
	}

	// �ڰ��� �ǽ�
	if (id[n] == 43 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 46;
	}

	// �ڰ��� �ǽ� Ȯ�οϷ�
	if (id[n] == 47 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 42;
	}

	// �Ϸ��� �ǽ�
	if (id[n] == 43 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 47;
	}

	// �Ϸ��� �ǽ� Ȯ�οϷ�
	if (id[n] == 48 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 42;
	}

	// ���������� �� Ž���Ϸ�
	if (id[n] == 43 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 43;
	}

	// ����� �ǽ�
	if (id[n] == 44 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 48;
	}

	// ����� �ǽ�
	if (id[n] == 49 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 43;
	}

	// �ٽ� ���캸��
	if (id[n] == 44 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 41;
	}

	// ���� Ȯ�οϷ�
	if (id[n] == 44 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 49;
	}

	// ����ã�� ������ ����
	if (id[n] == 50 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 52;
	}

	// ����ã�� ������ ���� �ǵ��ư���
	if (id[n] == 53 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 49;
	}

	// ����ã�� ������ ����
	if (id[n] == 50 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 53;
	}

	// ����ã�� ������ ���� �ǵ��ư���
	if (id[n] == 54 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 49;
	}

	// ����ã�� ���� �����ڵ��
	if (id[n] == 50 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 50;
	}

	// ����ã�� �ڰ��� ����
	if (id[n] == 51 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 54;
	}

	// ����ã�� �ڰ��� ���� �ǵ��ư���
	if (id[n] == 55 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 50;
	}

	// ����ã�� �Ϸ��� ����
	if (id[n] == 51 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 55;
	}

	// ����ã�� �Ϸ��� ���� �ǵ��ư���
	if (id[n] == 56 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 50;
	}

	// ����ã�� ���������ڵ��2
	if (id[n] == 51 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 51;
	}

	// ����ã�� ����� ����
	if (id[n] == 52 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 56;
	}

	// ����ã�� ����� ���� ����� ������
	if (id[n] == 57 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 58;
	}

	// �ٽ� �����ϱ�
	if (id[n] == 52 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 49;
	}

	// �������(ȸ�ǽ�)���ƺ���
	if (id[n] == 59 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 62;
	}

	// �������(ȸ�ǽ�)���ƺ��� �ǵ��ư���
	if (id[n] == 63 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 58;
	}

	// ���ǵ� �繫�浹�ƺ���
	if (id[n] == 59 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 63;
	}

	// ���ǵ� �繫�浹�ƺ��� �ǵ��ư���
	if (id[n] == 64 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 58;
	}

	// ���� �����ڵ��
	if (id[n] == 59 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 59;
	}

	// ������ �繫�� ���ƺ���
	if (id[n] == 60 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 64;
	}

	// ������ �繫�� ���ƺ��� �ǵ��ư���
	if (id[n] == 65 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 59;
	}

	// �������� �� ���ƺ���
	if (id[n] == 60 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 65;
	}

	// �������� �� ���ƺ���
	if (id[n] == 66 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 59;
	}

	// ���� �����ڵ��2
	if (id[n] == 60 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 60;
	}

	// �ڰ����� �� ���ƺ���
	if (id[n] == 61 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 66;
	}

	// �ڰ����� �� ���ƺ��� �ǵ��ư���
	if (id[n] == 67 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 60;
	}

	// �Ϸ��ۼ��� ���ƺ���
	if (id[n] == 61 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 67;
	}

	// �Ϸ��ۼ��� ���ƺ��� �ǵ��ư���
	if (id[n] == 68 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 60;
	}

	// ���ο� ��� ���캸��
	if (id[n] == 61 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 61;
	}

	// ���ǵ��� ��
	if (id[n] == 62 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 68;
	}

	// �ǵ��ư���
	if (id[n] == 62 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 58;
	}

	// ���ǵ��� �� å�������Ǳ�
	if (id[n] == 69 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 73;
	}

	// ���ǵ��� �� å�������Ǳ� �ǵ��ư���
	if (id[n] == 74 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 68;
	}

	// ���ǵ��� �� ��������ã��
	if (id[n] == 69 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 74;
	}

	// ���ǵ��� �� ��������ã��
	if (id[n] == 75 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 68;
	}

	// ���ǵ��� �� �����ܼ� ã��
	if (id[n] == 69 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 69;
	}

	// ���ǵ��� �� ������
	if (id[n] == 70 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 75;
	}

	// ���ǵ��� �� ������ �ǵ��ư���
	if (id[n] == 76 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 69;
	}

	// ���ǵ��� �� å���
	if (id[n] == 70 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 76;
	}

	// ���ǵ��� �� å���
	if (id[n] == 77 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 69;
	}

	// ���ǵ��� �� ��������
	if (id[n] == 70 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 70;
	}

	// �������� �ǵ��ư���
	if (id[n] == 71 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 68;
	}

	// ������ �����ϱ�
	if (id[n] == 71 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 71;
	}

	// ������ ����
	if (id[n] == 72 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 77;
	}

	// ������ ���� �ǵ��ư���
	if (id[n] == 78 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 71;
	}

	// �ڰ��� ����
	if (id[n] == 72 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 78;
	}

	// �ڰ��� ����
	if (id[n] == 79 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 71;
	}

	// �ٸ������� ����
	if (id[n] == 72 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 72;
	}

	// �Ϸ��� ����
	if (id[n] == 73 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 79;
	}

	// �Ϸ��� ����
	if (id[n] == 80 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 72;
	}

	// ������ ����
	if (id[n] == 73 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 80;
	}

	// �ǵ��ư��� �ٸ� ������ ����
	if (id[n] == 73 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 71;
	}

	// ����� ������.......
	if (id[n] == 81 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 81;
	}

	// ����� ������....... ��
	if (id[n] == 82 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_ENDING);
	}
	
}
void render_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->BackGroundImage, 0, 0);
	Renderer_DrawImage(&data->BackPaper, 0, 0);
	Renderer_DrawImage(&data->CursorImage, data->CursorX, data->CursorY);

	if (TitleExisted(id[n]))
	{
		SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
		Renderer_DrawTextSolid(&data->TitleLine[0], 100, 30, color);
	}

	for (int32 i = 0; i < TEXTLINE_COUNT; ++i)
	{
		SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
		Renderer_DrawTextSolid(&data->TextLine[i], 100, 150 + 40 * i, color);
	}

	for (int32 i = 0; i < 3; ++i) {
		if (SelectExisted(id[n], i)) {
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->SelectLine[i], 70, 500 + 60 * i, color);
		}
	}

}

void release_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Audio_FreeMusic(&data->BGM); 
	Audio_FreeSoundEffect(&data->Effect[0]);
	Audio_FreeSoundEffect(&data->Effect[1]);

	
	SafeFree(g_Scene.Data);
}
#pragma endregion

#pragma region EndingScene
const wchar_t* str2[] = {
	L"�� PD ���λ��",
	L"",
	L"�������̺�",
	L"",
	L"����",
	L"",
	L"��ȹ",
	L"",
	L"�� ����",
	L"�� ��",
	L"",
	L"���α׷���",
	L"",
	L"�� ����",
	L"�� �ǹ�",
	L"�� ����",
	L"",
	L"The End"
};

typedef struct EndingSceneData
{
	Text		GuideLine[GUIDELINE_COUNT];
	Music		BGM;
	float		Volume;
	SoundEffect Effect;
	Image		BackGround;
	Image		BackPaper;
	float		Speed;
	int32		X;
	int32		Y;
	int32		Alpha;
} EndingSceneData;

void init_ending(void)
{
	g_Scene.Data = malloc(sizeof(EndingSceneData));
	memset(g_Scene.Data, 0, sizeof(EndingSceneData));

	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;
	Image_LoadImage(&data->BackGround, "TitleImage.png");
	Image_LoadImage(&data->BackPaper, "BackPaper.png");

	for (int32 i = 0; i < GUIDELINE_COUNT; ++i)
	{
		Text_CreateText(&data->GuideLine[i], "GongGothicBold.ttf", 30, str2[i], wcslen(str2[i]));
	}

	Audio_LoadMusic(&data->BGM, "Denouement.mp3");
	Audio_PlayFadeIn(&data->BGM, INFINITY_LOOP, 3000);

	data->Volume = 1.0f;

	data->Speed = 400.0f;
	data->X = 400;
	data->Y = 400;
	data->Alpha = 255;
}

void update_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

}

int upPixel = 0;
int count = 0;

void render_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->BackGround, 0, 0);
	Renderer_DrawImage(&data->BackPaper, 0, 0);

	for (int32 i = 0; i < GUIDELINE_COUNT; ++i)
	{
		if (900 - upPixel > 100)
		{
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->GuideLine[i], 75, 900 + 30 * i - upPixel, color);
		}
		else
		{
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->GuideLine[i], 75, 100 + 30 * i, color);
		}
	}

	upPixel += 5;
}

void release_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 10; ++i)
	{
		Text_FreeText(&data->GuideLine[i]);
	}
	Audio_FreeMusic(&data->BGM);
	Audio_FreeSoundEffect(&data->Effect);

	SafeFree(g_Scene.Data);
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
	assert(SCENE_NULL < scene&& scene < SCENE_MAX);

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
	case SCENE_CONTENT:
		g_Scene.Init = init_content;
		g_Scene.Update = update_content;
		g_Scene.Render = render_content;
		g_Scene.Release = release_content;
		break;
	case SCENE_ENDING:
		g_Scene.Init = init_ending;
		g_Scene.Update = update_ending;
		g_Scene.Render = render_ending;
		g_Scene.Release = release_ending;
		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}