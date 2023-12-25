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
			if (gameObj->isActive() == false)
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
			if (gameObj->isActive() == false)
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
			if (gameObj->isActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void HyeonLayer::Destroy()
	{
		vector<HyeonGameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);
	}

	void HyeonLayer::AddGameObject(HyeonGameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}

	void HyeonLayer::EraseGameObject(HyeonGameObject* eraseGameObj)
	{
		erase_if(mGameObjects,
			[=](HyeonGameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
	}

	void HyeonLayer::findDeadGameObjects(OUT vector<HyeonGameObject*>& gameObjs)
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			HyeonGameObject::eState active = gameObj->GetState();
			if (active == HyeonGameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void HyeonLayer::deleteGameObjects(vector<HyeonGameObject*> deleteObjs)
	{
		for (HyeonGameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void HyeonLayer::eraseDeadGameObject()
	{
		erase_if(mGameObjects,
			[](HyeonGameObject* gameObj)
			{
				return (gameObj)->isDead();
			});
	}
}