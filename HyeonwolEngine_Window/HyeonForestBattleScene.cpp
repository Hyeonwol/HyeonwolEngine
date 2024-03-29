#include "HyeonForestBattleScene.h"
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
#include "HyeonBattleGreenImpScript.h"
#include "HyeonBoxCollider2D.h"
#include "HyeonCollisionManager.h"
#include "HyeonMovePlayerScript.h"
#include "HyeonForestBattleChrono.h"
#include "HyeonForestBattleAyla.h"
#include "HyeonForestBattleRobo.h"
#include "HyeonSelectedChar.h"

namespace Hyeon
{
	HyeonBattleGreenImpScript::eState GreenImpState = HyeonBattleGreenImpScript::eState::Idle;
	bool isMonsterTurn = false;

	Vector2 HyeonForestBattleScene::ImpPos = Vector2::Zero;
	Vector2 HyeonForestBattleScene::Imp2Pos = Vector2::Zero;
	Vector2 HyeonForestBattleScene::Imp3Pos = Vector2::Zero;
	Vector2 HyeonForestBattleScene::ChronoPos = Vector2::Zero;
	Vector2 HyeonForestBattleScene::AylaPos = Vector2::Zero;
	Vector2 HyeonForestBattleScene::RoboPos = Vector2::Zero;

	HyeonForestBattleScene::HyeonForestBattleScene()
	{
	}
	HyeonForestBattleScene::~HyeonForestBattleScene()
	{
	}
	void HyeonForestBattleScene::Initialize()
	{
		//뒷배경
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		bgSr->SetSize(Vector2(5.0f, 5.0f));

		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"ForestBattleBG");
		bgSr->SetTexture(bgTexture);

		//imp1
		GreenImp = object::Instantiate <HyeonMonster>
			(enums::eLayerType::Monster);
		GreenImp->AddComponent<HyeonBattleGreenImpScript>();
		graphics::HyeonTexture* ImpTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Imp"); 

		HyeonBoxCollider2D* ImpBoxCollider = GreenImp->AddComponent<HyeonBoxCollider2D>();
		//ImpBoxCollider->SetSize(Vector2(0.85, 0.85));
		HyeonAnimator* GreenImpAnimator = GreenImp->AddComponent<HyeonAnimator>();

		GreenImpAnimator->CreateAnimation(L"GreenImpIdle", ImpTex, 
			Vector2(352.0f, 367.0f), Vector2(23.0f, 27.0f), 
			Vector2::Zero, 1, 0.1f);
		//GreenImpAnimator->CreateAnimation(L"GreenImpLaugh", ImpTex,
		//	Vector2(300.0f, 483.0f), Vector2(35.0f, 27.0f),
		//	Vector2::Zero, 2, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpMove", ImpTex,
			Vector2(208.0f, 357.0f), Vector2(30.0f, 30.0f),
			Vector2::Zero, 3, 0.1f);
		GreenImpAnimator->CreateAnimation(L"GreenImpAttacked", ImpTex,
			Vector2(340.0f, 514.0f), Vector2(24.0f, 37.0f),
			Vector2::Zero, 1, 1.0f);
		GreenImpAnimator->CreateAnimation(L"GreenImpAttack", ImpTex,
			Vector2(208.0f, 527.0f), Vector2(30.0f, 37.0f),
			Vector2::Zero, 2, 0.1f);

		GreenImpAnimator->PlayAnimation(L"GreenImpIdle");

		GreenImp->GetComponent<HyeonTransform>()->SetPosition(Vector2(650.0f, 550.0f));
		GreenImp->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		ImpPos.X = GreenImp->GetComponent<HyeonTransform>()->GetPosition().X;
		ImpPos.Y = GreenImp->GetComponent<HyeonTransform>()->GetPosition().Y;

		////imp2
		//GreenImp2 = object::Instantiate <HyeonMonster>
		//	(enums::eLayerType::Monster);
		//GreenImp2->AddComponent<HyeonBattleGreenImpScript>();
		//graphics::HyeonTexture* ImpTex2 = HyeonResources::Find<graphics::HyeonTexture>
		//	(L"Imp");

		//HyeonBoxCollider2D* ImpBoxCollider2 = GreenImp2->AddComponent<HyeonBoxCollider2D>();
		////ImpBoxCollider->SetSize(Vector2(0.85, 0.85));
		//HyeonAnimator* GreenImpAnimator2 = GreenImp2->AddComponent<HyeonAnimator>();

		//GreenImpAnimator2->CreateAnimation(L"GreenImpIdle", ImpTex,
		//	Vector2(352.0f, 367.0f), Vector2(23.0f, 27.0f),
		//	Vector2::Zero, 1, 0.1f);
		////GreenImpAnimator->CreateAnimation(L"GreenImpLaugh", ImpTex,
		////	Vector2(300.0f, 483.0f), Vector2(35.0f, 27.0f),
		////	Vector2::Zero, 2, 0.1f);
		//GreenImpAnimator2->CreateAnimation(L"GreenImpMove", ImpTex,
		//	Vector2(208.0f, 357.0f), Vector2(30.0f, 30.0f),
		//	Vector2::Zero, 3, 0.1f);
		//GreenImpAnimator2->CreateAnimation(L"GreenImpAttacked", ImpTex,
		//	Vector2(340.0f, 514.0f), Vector2(24.0f, 37.0f),
		//	Vector2::Zero, 1, 1.0f);
		//GreenImpAnimator2->CreateAnimation(L"GreenImpAttack", ImpTex,
		//	Vector2(208.0f, 527.0f), Vector2(30.0f, 37.0f),
		//	Vector2::Zero, 2, 0.1f);

		//GreenImpAnimator2->PlayAnimation(L"GreenImpIdle");

		//GreenImp2->GetComponent<HyeonTransform>()->SetPosition(Vector2(500.0f, 550.0f));
		//GreenImp2->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		//Imp2Pos.X = GreenImp2->GetComponent<HyeonTransform>()->GetPosition().X;
		//Imp2Pos.Y = GreenImp2->GetComponent<HyeonTransform>()->GetPosition().Y;

		////imp3
		//GreenImp3 = object::Instantiate <HyeonMonster>
		//	(enums::eLayerType::Monster);
		//GreenImp3->AddComponent<HyeonBattleGreenImpScript>();
		//graphics::HyeonTexture* ImpTex3 = HyeonResources::Find<graphics::HyeonTexture>
		//	(L"Imp");

		//HyeonBoxCollider2D* ImpBoxCollider3 = GreenImp3->AddComponent<HyeonBoxCollider2D>();
		////ImpBoxCollider->SetSize(Vector2(0.85, 0.85));
		//HyeonAnimator* GreenImpAnimator3 = GreenImp3->AddComponent<HyeonAnimator>();

		//GreenImpAnimator3->CreateAnimation(L"GreenImpIdle", ImpTex,
		//	Vector2(352.0f, 367.0f), Vector2(23.0f, 27.0f),
		//	Vector2::Zero, 1, 0.1f);
		////GreenImpAnimator->CreateAnimation(L"GreenImpLaugh", ImpTex,
		////	Vector2(300.0f, 483.0f), Vector2(35.0f, 27.0f),
		////	Vector2::Zero, 2, 0.1f);
		//GreenImpAnimator3->CreateAnimation(L"GreenImpMove", ImpTex,
		//	Vector2(208.0f, 357.0f), Vector2(30.0f, 30.0f),
		//	Vector2::Zero, 3, 0.1f);
		//GreenImpAnimator3->CreateAnimation(L"GreenImpAttacked", ImpTex,
		//	Vector2(340.0f, 514.0f), Vector2(24.0f, 37.0f),
		//	Vector2::Zero, 1, 1.0f);
		//GreenImpAnimator3->CreateAnimation(L"GreenImpAttack", ImpTex,
		//	Vector2(208.0f, 527.0f), Vector2(30.0f, 37.0f),
		//	Vector2::Zero, 2, 0.1f);

		//GreenImpAnimator3->PlayAnimation(L"GreenImpIdle");

		//GreenImp3->GetComponent<HyeonTransform>()->SetPosition(Vector2(800.0f, 550.0f));
		//GreenImp3->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		//Imp3Pos.X = GreenImp3->GetComponent<HyeonTransform>()->GetPosition().X;
		//Imp3Pos.Y = GreenImp3->GetComponent<HyeonTransform>()->GetPosition().Y;
		//
		//플레이어(크로노)
		Chrono = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Chrono->AddComponent<HyeonForestBattleChrono>();

		graphics::HyeonTexture* mChronoTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");

		graphics::HyeonTexture* mChronoTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet2");

		graphics::HyeonTexture* mChronoTexture3 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet3");

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

		//Dead
		ChronoAnimator->CreateAnimation(L"ChronoDead", mChronoTexture3,
			Vector2(0.0f, 0.0f), Vector2(35.0f, 40.0f),
			Vector2::Zero, 3, 0.12f);

		ChronoAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(850.0f, 700.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		ChronoPos.X = Chrono->GetComponent<HyeonTransform>()->GetPosition().X;
		ChronoPos.Y = Chrono->GetComponent<HyeonTransform>()->GetPosition().Y;


		//에이라
		Ayla = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Ayla->AddComponent<HyeonForestBattleAyla>();

		graphics::HyeonTexture* mAylaTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Ayla");

		graphics::HyeonTexture* mAylaTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"AylaSheet2");

		HyeonBoxCollider2D* AylaCollider = Ayla->AddComponent<HyeonBoxCollider2D>();

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
			Vector2::Zero, 6, 0.2f);
		//Skill2
		AylaAnimator->CreateAnimation(L"AylaRightSkill2", mAylaTexture2,
			Vector2(130.0f, 90.0f), Vector2(30.0f, 40.0f),
			Vector2::Zero, 5, 0.1f);

		//Dead
		AylaAnimator->CreateAnimation(L"AylaDead", mAylaTexture2,
			Vector2(0.0f, 90.0f), Vector2(40.0f, 40.0f),
			Vector2::Zero, 3, 0.1f);

		AylaAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);

		Ayla->GetComponent<HyeonTransform>()->SetPosition(Vector2(400.0f, 700.0f));
		Ayla->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		AylaPos.X = Ayla->GetComponent<HyeonTransform>()->GetPosition().X;
		AylaPos.Y = Ayla->GetComponent<HyeonTransform>()->GetPosition().Y;

		//Robo
		Robo = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));
		Robo->AddComponent<HyeonForestBattleRobo>();

		graphics::HyeonTexture* mRoboTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Robo");
		graphics::HyeonTexture* mRoboTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"RoboSheet2");

		HyeonBoxCollider2D* RoboCollider = Robo->AddComponent<HyeonBoxCollider2D>();

		HyeonAnimator* RoboAnimator = Robo->AddComponent<HyeonAnimator>();

		//DrawWeapon
		RoboAnimator->CreateAnimation(L"RoboDrawWeapon", mRoboTexture,
			Vector2(0.0f, 221.0f), Vector2(28.0f, 37.0f),
			Vector2::Zero, 3, 0.1f);

		//Attack
		RoboAnimator->CreateAnimation(L"RoboAttack", mRoboTexture,
			Vector2(230.0f, 179.0f), Vector2(31.0f, 37.0f),
			Vector2::Zero, 2, 0.1f);

		//Skill1
		RoboAnimator->CreateAnimation(L"RoboSkill1", mRoboTexture2,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 40.0f),
			Vector2::Zero, 6, 0.15f);

		//Dead
		RoboAnimator->CreateAnimation(L"RoboDead", mRoboTexture,
			Vector2(512.0f, 268.0f), Vector2(35.0f, 29.0f),
			Vector2::Zero, 3, 0.15f);

		RoboAnimator->PlayAnimation(L"RoboDrawWeapon", false);

		Robo->GetComponent<HyeonTransform>()->SetPosition(Vector2(625.0f, 800.0f));
		Robo->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		RoboPos.X = Robo->GetComponent<HyeonTransform>()->GetPosition().X;
		RoboPos.Y = Robo->GetComponent<HyeonTransform>()->GetPosition().Y;

		//선택된 캐릭터 표시
		SelectedChar = object::Instantiate<HyeonPlayer>
			(eLayerType::Player, Vector2(0.0f, 0.0f));
		SelectedChar->AddComponent<HyeonSelectedChar>();

		HyeonScene::Initialize();
	}
	void HyeonForestBattleScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonForestBattleScene::LateUpdate()
	{
		HyeonScene::LateUpdate();
	}
	void HyeonForestBattleScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Forest Battle Scene";
		TextOut(hdc, 0, 0, str, 13);
	}
	void HyeonForestBattleScene::OnEnter()
	{
		HyeonCollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		renderer::mainCamera->SetTarget(GreenImp);
		renderer::mainCamera->Update();
	}
	void HyeonForestBattleScene::OnExit()
	{
	}
}