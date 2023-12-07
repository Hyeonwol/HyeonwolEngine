#include "HyeonLayer.h"

namespace Hyeon
{
	HyeonLayer::HyeonLayer()
			: mGameObjects{}
	{
	}

	HyeonLayer::~HyeonLayer()
	{
		for (HyeonGameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;
			delete gameobj;
			gameobj = nullptr;
		}
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
			HyeonGameObject::eState state = gameObj->GetActive();
			if (state == HyeonGameObject::eState::Paused
				|| state == HyeonGameObject::eState::Dead)
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
			HyeonGameObject::eState state = gameObj->GetActive();
			if (state == HyeonGameObject::eState::Paused
				|| state == HyeonGameObject::eState::Dead)
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
			HyeonGameObject::eState state = gameObj->GetActive();
			if (state == HyeonGameObject::eState::Paused
				|| state == HyeonGameObject::eState::Dead)
				continue;

			gameObj->Render(hdc);
		}
	}

	void HyeonLayer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin();
			iter != mGameObjects.end(); )
		{
			HyeonGameObject::eState active = (*iter)->GetActive();
			if (active == HyeonGameObject::eState::Dead)
			{
				HyeonGameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}

	void HyeonLayer::AddGameObject(HyeonGameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}
}