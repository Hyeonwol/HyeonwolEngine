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
#include "HyeonMonsterScript.h"
#include "HyeonBoxCollider2D.h"
#include "HyeonCollisionManager.h"


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
		//imp
		HyeonMonster* imp = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);

		imp->AddComponent<HyeonMonsterScript>();

		graphics::HyeonTexture* ImpTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Imp");

		imp->GetComponent<HyeonTransform>()->SetPosition(Vector2(300.0f, 300.0f));
		imp->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));

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

		ChronoAnimator->PlayAnimation(L"ChronoDownDrawWeapon");

		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(100.0f, 100.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(2.0f, 2.0f));

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