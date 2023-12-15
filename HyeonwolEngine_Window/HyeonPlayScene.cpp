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
#include "HyeonBattlePlayerScript.h"
#include "HyeonMovePlayerScript.h"
#include "HyeonAnimator.h"
#include "HyeonMonster.h"
#include "HyeonMonsterScript.h"
#include "HyeonBoxCollider2D.h"
#include "HyeonCollisionManager.h"


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
		HyeonCollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		
		//메인 카메라
		HyeonGameObject* camera = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::None);
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;

		//뒷배경
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround/*, Vector2(-230.0f, -130)*/);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		bgSr->SetSize(Vector2(6.0f, 6.0f));
	
		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"BG");
		bgSr->SetTexture(bgTexture);

		//포탈이미지
		HyeonGameObject* Portal = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::Object, Vector2(350.0f,280.0f));
		HyeonSpriteRenderer* Portalsr = Portal->AddComponent<HyeonSpriteRenderer>();
		graphics::HyeonTexture* PortalTexture = HyeonResources::Find<graphics::HyeonTexture>(L"Portal");
		Portalsr->SetTexture(PortalTexture);

		//imp
		HyeonMonster* imp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

		imp->AddComponent<HyeonMonsterScript>();

		HyeonBoxCollider2D* impBoxCollider = imp->AddComponent<HyeonBoxCollider2D>();
		//impBoxCollider->SetSize(Vector2(0.8f, 0.8f));
		impBoxCollider->SetOffset(Vector2(-10, 10));

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
			Vector2(208.0f, 450.0f), Vector2(30.0f, 35.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpLaugh", ImpTex,
			Vector2(293.0f, 481.0f), Vector2(40.0f, 34.0f),
			Vector2::Zero, 2, 0.1f);

		impAnimator->PlayAnimation(L"ImpLaugh", false);
		imp->GetComponent<HyeonTransform>()->SetPosition(Vector2(1300.0f, 1300.0f));
		imp->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		
		//동료(에이라)
		Ayla = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Ayla->AddComponent<HyeonMovePlayerScript>();
		
		cameraComp->SetTarget(Ayla);

		HyeonBoxCollider2D* AylaBoxCollider = Ayla->AddComponent<HyeonBoxCollider2D>();
		AylaBoxCollider->SetSize(Vector2(0.8f, 1.6f));
		AylaBoxCollider->SetOffset(Vector2(-10, -10));

		graphics::HyeonTexture* mAylaTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Ayla");
		graphics::HyeonTexture* mAylaTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"AylaSheet2");
		
		HyeonAnimator* AylaAnimator = Ayla->AddComponent<HyeonAnimator>();
		
		//Relax
		AylaAnimator->CreateAnimation(L"DownRelax", mAylaTexture,
			Vector2(62.0f, 4.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);
		AylaAnimator->CreateAnimation(L"UpRelax", mAylaTexture,
			Vector2(60.0f, 47.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 1, 0.1f);
		AylaAnimator->CreateAnimation(L"RightRelax", mAylaTexture,
			Vector2(60.0f, 82.0f), Vector2(22.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);
		AylaAnimator->CreateAnimation(L"LeftRelax", mAylaTexture2,
			Vector2(130.0f, 0.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);
		
		//Walk
		AylaAnimator->CreateAnimation(L"DownWalk", mAylaTexture,
			Vector2(113.0f, 4.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		AylaAnimator->CreateAnimation(L"UpWalk", mAylaTexture,
			Vector2(113.0f, 48.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		AylaAnimator->CreateAnimation(L"RightWalk", mAylaTexture2,
			Vector2(0.0f, 0.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		AylaAnimator->CreateAnimation(L"LeftWalk", mAylaTexture2,
			Vector2(0.0f, 40.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		
		//Run
		AylaAnimator->CreateAnimation(L"DownRun", mAylaTexture,
			Vector2(60.0f, 123.0f), Vector2(24.0f, 42.0f),
			Vector2::Zero, 3, 0.1f);
		AylaAnimator->CreateAnimation(L"UpRun", mAylaTexture,
			Vector2(131.0f, 123.0f), Vector2(28.00f, 42.0f),
			Vector2::Zero, 3, 0.1f);
		AylaAnimator->CreateAnimation(L"RightRun", mAylaTexture,
			Vector2(114.5f, 165.0f), Vector2(32.0f, 34.0f),
			Vector2::Zero, 3, 0.1f);
		AylaAnimator->CreateAnimation(L"LeftRun", mAylaTexture2,
			Vector2(180.0f, 0.0f), Vector2(40.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		
		AylaAnimator->PlayAnimation(L"DownRelax", false);
		
		Ayla->GetComponent<HyeonTransform>()->SetPosition(Vector2(1600.0f, 600.0f));
		Ayla->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		
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
		renderer::mainCamera->SetTarget(Ayla);
		renderer::mainCamera->Update();
	}
	void HyeonPlayScene::OnExit()
	{
	}
}
