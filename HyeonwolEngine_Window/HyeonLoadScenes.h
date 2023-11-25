#pragma once
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"
#include "HyeonPlayScene.h"
#include "HyeonTitleScene.h"

namespace Hyeon
{
	void LoadScenes()
	{
		HyeonSceneManager::CreateScene<HyeonTitleScene>(L"TitleScene");
		HyeonSceneManager::CreateScene<HyeonPlayScene>(L"PlayScene");
		
		HyeonSceneManager::LoadScene(L"TitleScene");
		//HyeonSceneManager::LoadScene(L"PlayScene");
	}
}