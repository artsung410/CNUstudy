#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"

Scene g_Scene;

static ESceneType s_nextScene;

typedef struct tagTitleSceneData
{
	Text TitleText[128];
} TitleSceneData;

void titleSceneInit(void) //init �����ͷε� , �ʱ�ȭ ���
{
	g_Scene.Data = malloc(sizeof (TitleSceneData));
}

Text arr[128];
void titleSceneUpdate(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	TextCopyWithWhite(data->TitleText, L"�׷�");

	//�����̽�Ű ������ "�޷�" ���
	if (Input_GetKey(VK_SPACE))
	{
		TextCopyWithWhite(data->TitleText, L"�޷�");
	}
	
}

void titleSceneRender(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawText(data->TitleText, TextLen(data->TitleText), 10, 5);
}

void titleSceneRelease(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

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
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);
	//������ �����ϱ�
	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene == SCENE_NULL); //�� ������?
	//���� ������ -> release�� ȣ��
	

	//������ �ε��� ���� ���缭 gScene�� ����
	

	//���� ���� �ʱ�ȭ -> initȣ��

	//s_nextscene�� 0���� �ʱ�ȭ
	
}
