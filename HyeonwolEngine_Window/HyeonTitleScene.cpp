#include "HyeonTitleScene.h"
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
	HyeonTitleScene::HyeonTitleScene()
	{
	}
	HyeonTitleScene::~HyeonTitleScene()
	{
	}
	void HyeonTitleScene::Initialize()
	{
		HyeonGameObject* titleBg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround);
		
		HyeonSpriteRenderer* sr = titleBg->AddComponent<HyeonSpriteRenderer>();
		graphics::HyeonTexture* titleBgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"Title");
		sr->SetTexture(titleBgTexture);

		HyeonScene::Initialize();
		
	}
	void HyeonTitleScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonTitleScene::LateUpdate()
	{
		HyeonScene::LateUpdate();

		if (HyeonInput::GetKeyDown(eKeyCode::N))
		{
			HyeonSceneManager::LoadScene(L"ForestScene");
		}
	}
	void HyeonTitleScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void HyeonTitleScene::OnEnter()
	{
		HyeonScene::OnEnter();
	}
	void HyeonTitleScene::OnExit()
	{
		HyeonScene::OnExit();
	}
}