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
#include "HyeonAnimator.h"
#include "HyeonMonster.h"
#include "HyeonMonsterScript.h"


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
			(enums::eLayerType::None, Vector2(392.0f, 395.0f));
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<HyeonPlayerScript>();

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


		//임프

		/*HyeonMonster* imp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

		imp->AddComponent<HyeonMonsterScript>();

		graphics::HyeonTexture* ImpTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Imp");
		HyeonAnimator* impAnimator = imp->AddComponent<HyeonAnimator>();
		impAnimator->CreateAnimation(L"ImpDownWalk", ImpTex,
			Vector2(208.0f, 357.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpUpWalk", ImpTex,
			Vector2(208.0f, 420.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpLeftWalk", ImpTex,
			Vector2(208.0f, 390.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpRightWalk", ImpTex,
			Vector2(208.0f, 450.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpLaugh", ImpTex,
			Vector2(293.0f, 481.0f), Vector2(40.0f, 34.0f),
			Vector2::Zero, 2, 0.1f);
		impAnimator->CreateAnimation(L"ImpJump", ImpTex,
			Vector2(208.0f, 510.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);

		impAnimator->PlayAnimation(L"ImpLaugh", false);
		imp->GetComponent<HyeonTransform>()->SetPosition(Vector2(300.0f, 300.0f));
		imp->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));*/


		//플레이어(크로노)
		mPlayer = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f,0.0f));
		mPlayer->AddComponent<HyeonPlayerScript>();

		graphics::HyeonTexture* mPlayerTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");
		HyeonAnimator* animator = mPlayer->AddComponent<HyeonAnimator>();
		animator->CreateAnimation(L"Relax", mPlayerTexture, 
			Vector2(57.0f, 11.0f), Vector2(20.0f, 42.0f), 
			Vector2::Zero, 3, 0.1f);
		animator->CreateAnimation(L"DownWalk", mPlayerTexture,
			Vector2(128.0f, 11.0f), Vector2(20.0f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"UpWalk", mPlayerTexture,
			Vector2(128.0f, 56.0f), Vector2(20.0f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"RightWalk", mPlayerTexture,
			Vector2(123.0f, 98.0f), Vector2(24.0f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"DrawWeapon", mPlayerTexture,
			Vector2(280.0f, 11.0f), Vector2(22.0f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"Attack", mPlayerTexture,
			Vector2(280.0f, 135.0f), Vector2(24.0f, 56.0f),
			Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"Relax");

		mPlayer->GetComponent<HyeonTransform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));
		

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
