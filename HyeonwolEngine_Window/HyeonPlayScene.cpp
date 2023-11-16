#include "HyeonPlayScene.h"
#include "HyeonGameObject.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"

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

		HyeonPlayer* pl = new HyeonPlayer();
		HyeonTransform* tr = pl->AddComponent<HyeonTransform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TR");
		HyeonSpriteRenderer* sr = pl->AddComponent<HyeonSpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);
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
