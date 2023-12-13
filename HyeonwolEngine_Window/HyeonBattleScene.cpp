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
		bgSr->SetSize(Vector2(6.0f, 6.0f));

		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"BG");
		bgSr->SetTexture(bgTexture);

		//imp
		GreenImp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

		GreenImp->AddComponent<HyeonBattleMonsterScript>();

		graphics::HyeonTexture* ImpTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Imp");

		HyeonBoxCollider2D* ImpBoxCollider = GreenImp->AddComponent<HyeonBoxCollider2D>();

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

		GreenImp->GetComponent<HyeonTransform>()->SetPosition(Vector2(650.0f, 750.0f));
		GreenImp->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));

		//플레이어(크로노)
		Chrono = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Chrono->AddComponent<HyeonBattlePlayerScript>();

		graphics::HyeonTexture* mChronoTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");

		graphics::HyeonTexture* mChronoTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet2");

		HyeonBoxCollider2D* ChronoCollider = Chrono->AddComponent<HyeonBoxCollider2D>();

		HyeonAnimator* ChronoAnimator = Chrono->AddComponent<HyeonAnimator>();

		//DrawWeapon
		ChronoAnimator->CreateAnimation(L"ChronoLeftDrawWeapon", mChronoTexture,
			Vector2(280.0f, 97.0f), Vector2(31.8f, 39.8f),
			Vector2::Zero, 6, 0.1f);

		//Attack
		ChronoAnimator->CreateAnimation(L"ChronoLeftAttack", mChronoTexture2,
			Vector2(0.0f, 93.0f), Vector2(34.0f, 57.0f),
			Vector2::Zero, 5, 0.1f);

		//Skill1
		ChronoAnimator->CreateAnimation(L"ChronoLeftSkill1", mChronoTexture2,
			Vector2(0.0f, 285.0f), Vector2(40.0f, 56.0f),
			Vector2::Zero, 5, 0.12f);

		//Skill2
		ChronoAnimator->CreateAnimation(L"ChronoLeftSkill2", mChronoTexture2,
			Vector2(147.0f, 340.0f), Vector2(30.0f, 50.0f),
			Vector2::Zero, 5, 0.12f);

		ChronoAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(900.0f, 1200.0f));
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
		//DrawWeapon
		AylaAnimator->CreateAnimation(L"AylaRightDrawWeapon", mAylaTexture,
			Vector2(262.0f, 44.0f), Vector2(26.0f, 37.0f),
			Vector2::Zero, 3, 0.1f);
		//Attack
		AylaAnimator->CreateAnimation(L"AylaRightAttack", mAylaTexture,
			Vector2(261.0f, 126.0f), Vector2(31.0f, 36.0f),
			Vector2::Zero, 3, 0.2f);

		//Skill1
		AylaAnimator->CreateAnimation(L"AylaRightSkill1", mAylaTexture2,
			Vector2(130.0f, 40.0f), Vector2(30.0f, 40.0f),
			Vector2::Zero, 6, 0.1f);

		AylaAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);

		Ayla->GetComponent<HyeonTransform>()->SetPosition(Vector2(400.0f, 1200.0f));
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
	void HyeonBattleScene::OnEnter()
	{
		
	}
	void HyeonBattleScene::OnExit()
	{
	}
}