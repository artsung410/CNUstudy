#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// ���� �ʱ�ȭ �ϴ� �Լ�
	void (*Update)(void);	// ������Ʈ
	void (*Render)(void);	// ����
	void (*Release)(void);	// ������ ����� �ڿ��� ����
	void* Data;
} Scene;

typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE,
	SCENE_BETTING,
	SCENE_MAIN,
<<<<<<< HEAD
	SCENE_CLEAR,
=======
	SCENE_GAMECLEAR,
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	SCENE_SCOREINFO,
	SCENE_RESULT,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene;

/// <summary>
/// ���� ������ ��ȯ�� �����ΰ�?
/// </summary>
/// <returns>���� ������ ��ȯ�� �����̸� true, �ƴϸ� false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// ���� ���� �����Ѵ�.
/// </summary>
/// <param name="scene">��</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// �� ��ȯ
/// </summary>
/// <param name=""></param>
void Scene_Change(void);
