#include "HyeonBattleScene.h"
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
#include "HyeonAnimator.h"
#include "HyeonMonster.h"
#include "HyeonAnimation.h"
#include "HyeonBattleMonsterScript.h"
#include "HyeonBoxCollider2D.h"
#include "HyeonCollisionManager.h"
#include "HyeonMovePlayerScript.h"



namespace Hyeon
{
	HyeonBattleScene::HyeonBattleScene()
	{
		
	}
	HyeonBattleScene::~HyeonBattleScene()
	{
	}
	void HyeonBattleScene::Initialize()
	{
		//뒷배경
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		bgSr->SetSize(Vector2(4.0f, 4.0f));

		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"BG");
		bgSr->SetTexture(bgTexture);

		//imp
		GreenImp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

		GreenImp->AddComponent<HyeonBattleMonsterScript>();

		graphics::HyeonTexture* ImpTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Imp");

		HyeonAnimator* GreenImpAnimator = GreenImp->AddComponent<HyeonAnimator>();

		GreenImpAnimator->CreateAnimation(L"GreenImpIdle", ImpTex, 
			Vector2(352.0f, 367.0f), Vector2(23.0f, 27.0f), 
			Vector2::Zero, 1, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpLaugh", ImpTex,
			Vector2(300.0f, 483.0f), Vector2(35.0f, 27.0f),
			Vector2::Zero, 2, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpMove", ImpTex,
			Vector2(208.0f, 357.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpAttacked", ImpTex,
			Vector2(340.0f, 514.0f), Vector2(24.0f, 37.0f),
			Vector2::Zero, 1, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpAttack", ImpTex,
			Vector2(208.0f, 527.0f), Vector2(30.0f, 37.0f),
			Vector2::Zero, 2, 0.1f);

		GreenImpAnimator->PlayAnimation(L"GreenImpIdle");

		GreenImp->GetComponent<HyeonTransform>()->SetPosition(Vector2(450.0f, 450.0f));
		GreenImp->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));

		//플레이어(크로노)
		Chrono = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Chrono->AddComponent<HyeonBattlePlayerScript>();

		graphics::HyeonTexture* mChronoTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");

		graphics::HyeonTexture* mChronoTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet2");

		HyeonAnimator* ChronoAnimator = Chrono->AddComponent<HyeonAnimator>();

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

		//Skill1
		ChronoAnimator->CreateAnimation(L"ChronoRightSkill1", mChronoTexture2,
			Vector2(0.0f, 228.0f), Vector2(40.0f, 50.0f),
			Vector2::Zero, 5, 0.12f);
		ChronoAnimator->CreateAnimation(L"ChronoLeftSkill1", mChronoTexture2,
			Vector2(0.0f, 285.0f), Vector2(40.0f, 56.0f),
			Vector2::Zero, 5, 0.12f);
		//Skill2
		ChronoAnimator->CreateAnimation(L"ChronoRightSkill2", mChronoTexture2,
			Vector2(0.0f, 340.0f), Vector2(30.0f, 50.0f),
			Vector2::Zero, 5, 0.12f);
		ChronoAnimator->CreateAnimation(L"ChronoLeftSkill2", mChronoTexture2,
			Vector2(147.0f, 340.0f), Vector2(30.0f, 50.0f),
			Vector2::Zero, 5, 0.12f);

		ChronoAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(600.0f, 700.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));

		//에이라
		Ayla = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Ayla->AddComponent<HyeonBattlePlayerScript>();

		graphics::HyeonTexture* mAylaTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Ayla");

		graphics::HyeonTexture* mAylaTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"AylaSheet2");

		HyeonAnimator* AylaAnimator = Ayla->AddComponent<HyeonAnimator>();
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
		AylaAnimator->CreateAnimation(L"AylaRightDrawWeapon", mAylaTexture,
			Vector2(262.0f, 44.0f), Vector2(26.0f, 37.0f),
			Vector2::Zero, 3, 0.1f);
	//	//Attack
	//	//AylaAnimator->CreateAnimation(L"DownAttack", mChronoTexture2,
	//	//	Vector2(0.0f, 165.0f), Vector2(39.6f, 58.0f),
	//	//	Vector2::Zero, 5, 0.1f);
	//	AylaAnimator->CreateAnimation(L"UpAttack", mAylaTexture,
	//		Vector2(275.0f, 190.0f), Vector2(31.6f, 53.8f),
	//		Vector2::Zero, 5, 0.1f);
		AylaAnimator->CreateAnimation(L"AylaRightAttack", mAylaTexture,
			Vector2(277.0f, 245.0f), Vector2(34.3f, 54.5f),
			Vector2::Zero, 5, 0.1f);
	//	//AylaAnimator->CreateAnimation(L"LeftAttack", mChronoTexture2,
	//	//	Vector2(0.0f, 93.0f), Vector2(34.0f, 57.0f),
	//	//	Vector2::Zero, 5, 0.1f);

		AylaAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);

		Ayla->GetComponent<HyeonTransform>()->SetPosition(Vector2(200.0f, 700.0f));
		Ayla->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));

		HyeonScene::Initialize();
	}
	void HyeonBattleScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonBattleScene::LateUpdate()
	{
		HyeonScene::LateUpdate();
	}
	void HyeonBattleScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Battle Scene";
		TextOut(hdc, 0, 0, str, 13);
	}
}