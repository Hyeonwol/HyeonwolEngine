#include "HyeonPlayScene.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	HyeonPlayScene::HyeonPlayScene()
	{
	}
	HyeonPlayScene::~HyeonPlayScene()
	{
	}
	void HyeonPlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++)
		{
			HyeonGameObject* obj = new HyeonGameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}
	}
	void HyeonPlayScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonPlayScene::LateUpdate()
	{
		HyeonScene::LateUpdate();
	}
	void HyeonPlayScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
	}
}
