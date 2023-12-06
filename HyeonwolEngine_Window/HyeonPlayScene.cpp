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
		//camera->AddComponent<HyeonPlayerScript>();  카메라 오류 있음. 질문할 것

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

		//imp
		HyeonMonster* imp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

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
			Vector2(208.0f, 450.0f), Vector2(30.0f, 35.0f),
			Vector2::Zero, 3, 0.1f);
		impAnimator->CreateAnimation(L"ImpLaugh", ImpTex,
			Vector2(293.0f, 481.0f), Vector2(40.0f, 34.0f),
			Vector2::Zero, 2, 0.1f);

		impAnimator->PlayAnimation(L"ImpLaugh", false);
		imp->GetComponent<HyeonTransform>()->SetPosition(Vector2(300.0f, 300.0f));
		imp->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));


		//플레이어(크로노)
		Chrono = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f,0.0f));
		Chrono->AddComponent<HyeonPlayerScript>();

		graphics::HyeonTexture* mChronoTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");

		graphics::HyeonTexture* mChronoTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet2");
		
		HyeonAnimator* ChronoAnimator = Chrono->AddComponent<HyeonAnimator>();

		//Relax
		ChronoAnimator->CreateAnimation(L"ChronoDownRelax", mChronoTexture, 
			Vector2(57.0f, 11.0f), Vector2(20.0f, 42.0f), 
			Vector2::Zero, 3, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoUpRelax", mChronoTexture,
			Vector2(77.0f, 56.0f), Vector2(20.0f, 42.0f),
			Vector2::Zero, 1, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoRightRelax", mChronoTexture,
			Vector2(56.0f, 95.0f), Vector2(20.0f, 42.0f),
			Vector2::Zero, 3, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoLeftRelax", mChronoTexture2,
			Vector2(240.0f, 0.0f), Vector2(20.0f, 42.0f),
			Vector2::Zero, 3, 0.1f);
		
		//Walk
		ChronoAnimator->CreateAnimation(L"ChronoDownWalk", mChronoTexture,
			Vector2(128.0f, 11.0f), Vector2(20.8f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoUpWalk", mChronoTexture,
			Vector2(128.0f, 56.0f), Vector2(20.8f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoRightWalk", mChronoTexture,
			Vector2(123.0f, 98.0f), Vector2(23.0f, 39.8f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoLeftWalk", mChronoTexture2,
			Vector2(82.0f, 0.0f), Vector2(24.8f, 39.0f),
			Vector2::Zero, 6, 0.1f);
		
		//DrawWeapon
		ChronoAnimator->CreateAnimation(L"ChronoDownDrawWeapon", mChronoTexture,
			Vector2(280.0f, 11.0f), Vector2(22.4f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoUpDrawWeapon", mChronoTexture,
			Vector2(280.0f, 59.0f), Vector2(22.68f, 41.8f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoLeftDrawWeapon", mChronoTexture,
			Vector2(280.0f, 97.0f), Vector2(31.8f, 39.8f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"ChronoRightDrawWeapon", mChronoTexture2,
			Vector2(0.0f, 44.0f), Vector2(32.6f, 42.0f),
			Vector2::Zero, 6, 0.1f);
		
		//Attack
		ChronoAnimator->CreateAnimation(L"ChronoDownAttack", mChronoTexture2,
			Vector2(0.0f, 165.0f), Vector2(39.6f, 58.0f),
			Vector2::Zero, 5, 0.1f);

		ChronoAnimator->CreateAnimation(L"ChronoUpAttack", mChronoTexture,
			Vector2(275.0f, 190.0f), Vector2(31.6f, 53.8f),
			Vector2::Zero, 5, 0.1f);

		ChronoAnimator->CreateAnimation(L"ChronoRightAttack", mChronoTexture,
			Vector2(277.0f, 245.0f), Vector2(34.3f, 54.5f),
			Vector2::Zero, 5, 0.1f);
		
		ChronoAnimator->CreateAnimation(L"ChronoLeftAttack", mChronoTexture2,
			Vector2(0.0f, 93.0f), Vector2(34.0f, 57.0f),
			Vector2::Zero, 5, 0.1f);

		ChronoAnimator->PlayAnimation(L"ChronoDownRelax");

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(100.0f, 100.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));
		
		//동료(에이라)
	//	Ayla = object::Instantiate<HyeonPlayer>
	//		(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
	//	Ayla->AddComponent<HyeonPlayerScript>();

	//	graphics::HyeonTexture* mAylaTexture = HyeonResources::Find<graphics::HyeonTexture>
	//		(L"Ayla");

	//	HyeonAnimator* AylaAnimator = Ayla->AddComponent<HyeonAnimator>();

	//	//Relax
	//	AylaAnimator->CreateAnimation(L"DownRelax", mAylaTexture,
	//		Vector2(57.0f, 11.0f), Vector2(20.0f, 42.0f),
	//		Vector2::Zero, 3, 0.1f);
	//	AylaAnimator->CreateAnimation(L"UpRelax", mAylaTexture,
	//		Vector2(77.0f, 56.0f), Vector2(20.0f, 42.0f),
	//		Vector2::Zero, 1, 0.1f);
	//	AylaAnimator->CreateAnimation(L"RightRelax", mAylaTexture,
	//		Vector2(56.0f, 95.0f), Vector2(20.0f, 42.0f),
	//		Vector2::Zero, 3, 0.1f);
	//	/*AylaAnimator->CreateAnimation(L"LeftRelax", mChronoTexture2,
	//		Vector2(240.0f, 0.0f), Vector2(20.0f, 42.0f),
	//		Vector2::Zero, 3, 0.1f);*/

	//	//Walk
	//	AylaAnimator->CreateAnimation(L"DownWalk", mAylaTexture,
	//		Vector2(128.0f, 11.0f), Vector2(20.8f, 42.0f),
	//		Vector2::Zero, 6, 0.1f);
	//	AylaAnimator->CreateAnimation(L"UpWalk", mAylaTexture,
	//		Vector2(128.0f, 56.0f), Vector2(20.8f, 42.0f),
	//		Vector2::Zero, 6, 0.1f);
	//	AylaAnimator->CreateAnimation(L"RightWalk", mAylaTexture,
	//		Vector2(123.0f, 98.0f), Vector2(23.0f, 39.8f),
	//		Vector2::Zero, 6, 0.1f);
	//	/*AylaAnimator->CreateAnimation(L"LeftWalk", mChronoTexture2,
	//		Vector2(82.0f, 0.0f), Vector2(24.8f, 39.0f),
	//		Vector2::Zero, 6, 0.1f);*/

	//	//DrawWeapon
	//	AylaAnimator->CreateAnimation(L"DownDrawWeapon", mAylaTexture,
	//		Vector2(280.0f, 11.0f), Vector2(22.4f, 42.0f),
	//		Vector2::Zero, 6, 0.1f);
	//	AylaAnimator->CreateAnimation(L"UpDrawWeapon", mAylaTexture,
	//		Vector2(280.0f, 59.0f), Vector2(22.68f, 41.8f),
	//		Vector2::Zero, 6, 0.1f);
	//	AylaAnimator->CreateAnimation(L"LeftDrawWeapon", mAylaTexture,
	//		Vector2(280.0f, 97.0f), Vector2(31.8f, 39.8f),
	//		Vector2::Zero, 6, 0.1f);
	///*	AylaAnimator->CreateAnimation(L"RightDrawWeapon", mAylaTexture,
	//		Vector2(0.0f, 44.0f), Vector2(32.6f, 42.0f),
	//		Vector2::Zero, 6, 0.1f);*/

	//	//Attack
	//	//AylaAnimator->CreateAnimation(L"DownAttack", mChronoTexture2,
	//	//	Vector2(0.0f, 165.0f), Vector2(39.6f, 58.0f),
	//	//	Vector2::Zero, 5, 0.1f);

	//	AylaAnimator->CreateAnimation(L"UpAttack", mAylaTexture,
	//		Vector2(275.0f, 190.0f), Vector2(31.6f, 53.8f),
	//		Vector2::Zero, 5, 0.1f);

	//	AylaAnimator->CreateAnimation(L"RightAttack", mAylaTexture,
	//		Vector2(277.0f, 245.0f), Vector2(34.3f, 54.5f),
	//		Vector2::Zero, 5, 0.1f);

	//	//AylaAnimator->CreateAnimation(L"LeftAttack", mChronoTexture2,
	//	//	Vector2(0.0f, 93.0f), Vector2(34.0f, 57.0f),
	//	//	Vector2::Zero, 5, 0.1f);

	//	AylaAnimator->PlayAnimation(L"DownRelax");

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(100.0f, 100.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));



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
