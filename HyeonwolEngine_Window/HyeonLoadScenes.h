#pragma once
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"
#include "HyeonForestScene.h"
#include "HyeonTitleScene.h"
#include "HyeonForestBattleScene.h"
#include "HyeonToolScene.h"
#include "HyeonMtWoeScene.h"

namespace Hyeon
{
	void LoadScenes()
	{
		HyeonSceneManager::CreateScene<HyeonToolScene>(L"ToolScene");
		HyeonSceneManager::CreateScene<HyeonTitleScene>(L"TitleScene");
		HyeonSceneManager::CreateScene<HyeonForestScene>(L"ForestScene");
		HyeonSceneManager::CreateScene<HyeonForestBattleScene>(L"ForestBattleScene");
		HyeonSceneManager::CreateScene< HyeonMtWoeScene>(L"MtWoeScene");

		//HyeonSceneManager::LoadScene(L"TitleScene");
		HyeonSceneManager::LoadScene(L"ForestScene");
		//HyeonSceneManager::LoadScene(L"ForestBattleScene");
		//HyeonSceneManager::LoadScene(L"ToolScene");
	}
}