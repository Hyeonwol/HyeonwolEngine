#pragma once
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"
#include "HyeonPlayScene.h"

namespace Hyeon
{
	void LoadScenes()
	{
		HyeonSceneManager::CreateScene<HyeonPlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		HyeonSceneManager::LoadScene(L"PlayScene");
	}
}