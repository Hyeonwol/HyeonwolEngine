#pragma once
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"
#include "HyeonPlayScene.h"
#include "HyeonTitleScene.h"
#include "HyeonBattleScene.h"
#include "HyeonToolScene.h"

namespace Hyeon
{
	void LoadScenes()
	{
		HyeonSceneManager::CreateScene<HyeonToolScene>(L"ToolScene");
		HyeonSceneManager::CreateScene<HyeonTitleScene>(L"TitleScene");
		HyeonSceneManager::CreateScene<HyeonPlayScene>(L"PlayScene");
		HyeonSceneManager::CreateScene<HyeonBattleScene>(L"ForestBattleScene");

		//HyeonSceneManager::LoadScene(L"TitleScene");
		//HyeonSceneManager::LoadScene(L"PlayScene");
		//HyeonSceneManager::LoadScene(L"ForestBattleScene");
		HyeonSceneManager::LoadScene(L"ToolScene");
	}
}