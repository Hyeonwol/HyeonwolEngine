#include "HyeonSceneManager.h"
#include "HyeonDontDestroyOnLoad.h"

namespace Hyeon
{
	map<wstring, HyeonScene*> HyeonSceneManager::mScene = {};
	HyeonScene* HyeonSceneManager::mActiveScene = nullptr;
	HyeonScene* HyeonSceneManager::mDontDestroyOnLoad = nullptr;

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
		mDontDestroyOnLoad = CreateScene<HyeonDontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void HyeonSceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}

	void HyeonSceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}

	void HyeonSceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}

	void HyeonSceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyOnLoad->Destroy();
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