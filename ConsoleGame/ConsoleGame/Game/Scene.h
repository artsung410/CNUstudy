#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// �� �ʱ�ȭ �Լ�
	void (*Update)(void);	// ������Ʈ
	void (*Render)(void);	// ����
	void (*Release)(void);	// ������ ����� �ڿ�����
	void* Data;
} Scene;


typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene; // ���� �׸����ִ� ��

/// <summary>
/// ���� ������ ��Ȱ�� �����ΰ�>?
/// </summary>
/// <returns>��ȯ�� �����̸� true, �״�θ� false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// �������� �����Ѵ�
/// </summary>
/// <param name="scene">��</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// �� ��ȯ
/// </summary>
/// <param name="scene"></param>
void Scene_Change(void);