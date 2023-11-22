#include "HyeonTitleScene.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"
#include "HyeonObject.h"

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
		titleBg = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::BackGround, Vector2(0, 0));
		
		HyeonSpriteRenderer* sr = titleBg->AddComponent<HyeonSpriteRenderer>();
		sr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\Title.png");
		HyeonScene::Initialize();
		/*titleBg = new HyeonPlayer();
		HyeonTransform* tr = titleBg->AddComponent<HyeonTransform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");
		HyeonSpriteRenderer* sr = titleBg->AddComponent<HyeonSpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\Title.png");

		AddGameObject(titleBg, enums::eLayerType::BackGround);*/
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
			HyeonSceneManager::LoadScene(L"PlayScene");
		}
	}
	void HyeonTitleScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}