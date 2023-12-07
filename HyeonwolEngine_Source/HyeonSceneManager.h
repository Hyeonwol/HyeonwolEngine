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
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static HyeonScene* LoadScene(const wstring& name);
		static HyeonScene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();
	private:
		static std::map<std::wstring, HyeonScene*> mScene;
		static HyeonScene* mActiveScene;
	};
}