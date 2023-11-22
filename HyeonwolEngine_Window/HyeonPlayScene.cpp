#include "HyeonPlayScene.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"

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
		bg = new HyeonPlayer();
		HyeonTransform* tr = bg->AddComponent<HyeonTransform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");
		HyeonSpriteRenderer* sr = bg->AddComponent<HyeonSpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Standard Ending Cutscene.png");

		AddGameObject(bg, eLayerType::BackGround);
	}
	void HyeonPlayScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonPlayScene::LateUpdate()
	{
		HyeonScene::LateUpdate();

		if (HyeonInput::GetKeyDown(eKeyCode::N))
		{
			HyeonSceneManager::LoadScene(L"TitleScene");
		}
	}
	void HyeonPlayScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void HyeonPlayScene::OnEnter()
	{
	}
	void HyeonPlayScene::OnExit()
	{
		HyeonTransform* tr = bg->GetComponent<HyeonTransform>();
		tr->SetPos(Vector2(0, 0));
	}
}
