#include "HyeonPlayScene.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"
#include "HyeonObject.h"
#include "HyeonResources.h"
#include "HyeonTexture.h"


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
			(enums::eLayerType::BackGround);
		HyeonSpriteRenderer* sr = bg->AddComponent<HyeonSpriteRenderer>();
		
		graphics::HyeonTexture* bg = HyeonResources::Find<graphics::HyeonTexture>(L"BG");
		sr->SetTexture(bg);

		//Æ÷Å»ÀÌ¹ÌÁö
		Portal = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Object, HyeonMath::Vector2(350,280));
		HyeonSpriteRenderer* Portalsr = Portal->AddComponent<HyeonSpriteRenderer>();
		graphics::HyeonTexture* Portal = HyeonResources::Find<graphics::HyeonTexture>(L"Portal");
		Portalsr->SetTexture(Portal);

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
	}
}
