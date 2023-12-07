#include "HyeonSceneManager.h"

namespace Hyeon
{
	map<wstring, HyeonScene*> HyeonSceneManager::mScene = {};
	HyeonScene* HyeonSceneManager::mActiveScene = nullptr;

	HyeonScene* HyeonSceneManager::LoadScene(const wstring& name)
	{
		if (mActiveScene)
		{
			mActiveScene->OnExit();
		}

		std::map<std::wstring, HyeonScene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

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

	void HyeonSceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}