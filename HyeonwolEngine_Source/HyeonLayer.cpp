#include "HyeonLayer.h"

namespace Hyeon
{
	HyeonLayer::HyeonLayer()
			: mGameObjects{}
	{
	}

	HyeonLayer::~HyeonLayer()
	{
	}

	void HyeonLayer::Initialize()
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Initialize();
		}
	}

	void HyeonLayer::Update()
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}

	void HyeonLayer::LateUpdate()
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->LateUpdate();
		}
	}

	void HyeonLayer::Render(HDC hdc)
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Render(hdc);
		}
	}
	void HyeonLayer::AddGameObject(HyeonGameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}
}