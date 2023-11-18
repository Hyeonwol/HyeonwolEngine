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
		HyeonPlayer* bg = new HyeonPlayer();
		HyeonTransform* tr = bg->AddComponent<HyeonTransform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");
		HyeonSpriteRenderer* sr = bg->AddComponent<HyeonSpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Guardia Forest.png");

		AddGameObject(bg);
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
