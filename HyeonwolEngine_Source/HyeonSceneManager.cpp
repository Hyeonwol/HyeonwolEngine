#include "HyeonSceneManager.h"

namespace Hyeon
{
	std::map<std::wstring, HyeonScene*> HyeonSceneManager::mScene = {};
	HyeonScene* HyeonSceneManager::mActiveScene = nullptr;

	void HyeonSceneManager::Initialize()
	{
	}

	void HyeonSceneManager::Update()
	{
		mActiveScene->Update();
	}

	void HyeonSceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void HyeonSceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}