#pragma once
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"
#include "HyeonPlayScene.h"

namespace Hyeon
{
	void LoadScenes()
	{
		HyeonSceneManager::CreateScene<HyeonPlayScene>(L"PlayScene");
		HyeonSceneManager::LoadScene(L"PlayScene");
	}
}