#include "HyeonPlayScene.h"
#include "HyeonPlayer.h"
#include "HyeonTransform.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"
#include "HyeonObject.h"
#include "HyeonResources.h"
#include "HyeonTexture.h"
#include "HyeonCamera.h"
#include "HyeonRenderer.h"
#include "HyeonPlayerScript.h"


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
		//메인 카메라
		HyeonGameObject* camera = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;


		//플레이어(크로노)
		mPlayer = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::BackGround);
		HyeonSpriteRenderer* sr = mPlayer->AddComponent<HyeonSpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<HyeonPlayerScript>();

		graphics::HyeonTexture* mPlayerTexture = HyeonResources::Find<graphics::HyeonTexture>(L"Chrono");
		sr->SetTexture(mPlayerTexture);

		//뒷배경
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));
		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"BG");
		bgSr->SetTexture(bgTexture);

		//포탈이미지
		HyeonGameObject* Portal = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::Object, Vector2(350.0f,280.0f));
		HyeonSpriteRenderer* Portalsr = Portal->AddComponent<HyeonSpriteRenderer>();
		graphics::HyeonTexture* PortalTexture = HyeonResources::Find<graphics::HyeonTexture>(L"Portal");
		Portalsr->SetTexture(PortalTexture);

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
