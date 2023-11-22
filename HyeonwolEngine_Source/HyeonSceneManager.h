#pragma once
#include "HyeonScene.h"

namespace Hyeon
{
	class HyeonSceneManager
	{
	public:
		template <typename T>
		static HyeonScene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}
		static HyeonScene* LoadScene(const std::wstring& name)
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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::map<std::wstring, HyeonScene*> mScene;
		static HyeonScene* mActiveScene;
	};
}