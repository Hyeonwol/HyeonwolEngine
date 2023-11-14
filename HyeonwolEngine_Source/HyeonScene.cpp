#include "HyeonScene.h"

namespace Hyeon 
{
	HyeonScene::HyeonScene()
		: mGameObjects{}
	{

	}
	HyeonScene::~HyeonScene()
	{
	}
	void HyeonScene::Initialize()
	{
	}
	void HyeonScene::Update()
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}
	void HyeonScene::LateUpdate()
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}
	void HyeonScene::Render(HDC hdc)
	{
		for (HyeonGameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}
	void HyeonScene::AddGameObject(HyeonGameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}