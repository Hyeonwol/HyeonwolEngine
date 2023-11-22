#include "HyeonPlayScene.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"
#include "HyeonObject.h"


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
		//µÞ¹è°æ
		bg = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::BackGround, Vector2(0.0f, 0.0f));
		HyeonSpriteRenderer* sr = bg->AddComponent<HyeonSpriteRenderer>();
		sr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Guardia Forest.png");

		//Æ÷Å»ÀÌ¹ÌÁö
		Portal = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Object, Vector2(350, 280));
		HyeonSpriteRenderer* Portalsr = Portal->AddComponent<HyeonSpriteRenderer>();
		Portalsr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\Chrono Trigger - Gate.png");

		HyeonScene::Initialize();
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
		//HyeonTransform* tr = bg->GetComponent<HyeonTransform>();
		//tr->SetPos(Vector2(0, 0));
	}
}
