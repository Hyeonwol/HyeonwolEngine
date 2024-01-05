#include "HyeonMtWoeScene.h"
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
#include "HyeonTile.h"
#include "HyeonTileMapRenderer.h"
#include "HyeonUIManager.h"

namespace Hyeon
{
	void HyeonMtWoeScene::Initialize()
	{
		//camera
		/*HyeonGameObject* camera = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::None);
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;*/

		//background
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround/*, Vector2(-230.0f, -130)*/);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		bgSr->SetSize(Vector2(6.0f, 6.0f));

		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"MountainBG");
		bgSr->SetTexture(bgTexture);

		//Monk Gargoyle
		HyeonMonster* Gargoyle = object::Instantiate<HyeonMonster>(enums::eLayerType::Monster);
		Gargoyle->AddComponent<HyeonMonsterScript>();
		graphics::HyeonTexture* GargoyleTex = HyeonResources::Find<graphics::HyeonTexture>
			(L"Gargoyle");

		HyeonAnimator* GargoyleAnimator = Gargoyle->AddComponent<HyeonAnimator>();
		GargoyleAnimator->CreateAnimation(L"GargoyleCome", GargoyleTex,
			Vector2(35.0f, 313.0f), Vector2(31.0f, 42.0f),
			Vector2::Zero, 4, 0.1f);

		GargoyleAnimator->CreateAnimation(L"GargoylePunch", GargoyleTex,
			Vector2(31.0f, 194.0f), Vector2(35.0f, 38.0f),
			Vector2::Zero, 3, 0.1f);

		GargoyleAnimator->CreateAnimation(L"GargoyleKick", GargoyleTex,
			Vector2(33.0f, 488.0f), Vector2(35.0f, 42.0f),
			Vector2::Zero, 3, 0.1f);
		
		GargoyleAnimator->PlayAnimation(L"ImpLaugh", false);
		Gargoyle->GetComponent<HyeonTransform>()->SetPosition(Vector2(300.0f, 300.0f));
		Gargoyle->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));
		
		//Chrono

		Chrono = object::Instantiate<HyeonPlayer>
			(enums::eLayerType::Player, Vector2(0.0f, 0.0f));

		//object::DontDestroyOnLoad(Chrono);

		Chrono->AddComponent<HyeonMovePlayerScript>();

		HyeonBoxCollider2D* ChronoBoxCollider = Chrono->AddComponent<HyeonBoxCollider2D>();
		ChronoBoxCollider->SetSize(Vector2(0.8f, 1.6f));
		//AylaBoxCollider->SetOffset(Vector2(-10, -10));

		graphics::HyeonTexture* mChronoTexture = HyeonResources::Find<graphics::HyeonTexture>
			(L"Chrono");
		graphics::HyeonTexture* mChronoTexture2 = HyeonResources::Find<graphics::HyeonTexture>
			(L"ChronoSheet2");

		HyeonAnimator* ChronoAnimator = Chrono->AddComponent<HyeonAnimator>();

		//Relax
		ChronoAnimator->CreateAnimation(L"DownRelax", mChronoTexture,
			Vector2(62.0f, 4.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);
		ChronoAnimator->CreateAnimation(L"UpRelax", mChronoTexture,
			Vector2(60.0f, 47.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 1, 0.1f);
		ChronoAnimator->CreateAnimation(L"RightRelax", mChronoTexture,
			Vector2(60.0f, 82.0f), Vector2(22.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);
		ChronoAnimator->CreateAnimation(L"LeftRelax", mChronoTexture2,
			Vector2(130.0f, 0.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 2, 0.1f);

		//Walk
		ChronoAnimator->CreateAnimation(L"DownWalk", mChronoTexture,
			Vector2(113.0f, 4.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"UpWalk", mChronoTexture,
			Vector2(113.0f, 48.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"RightWalk", mChronoTexture,
			Vector2(0.0f, 0.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);
		ChronoAnimator->CreateAnimation(L"LeftWalk", mChronoTexture2,
			Vector2(0.0f, 40.0f), Vector2(20.0f, 36.0f),
			Vector2::Zero, 6, 0.1f);

		ChronoAnimator->PlayAnimation(L"DownRelax", false);
		
		Chrono->GetComponent<HyeonTransform>()->SetPosition(Vector2(600.0f, 600.0f));
		Chrono->GetComponent<HyeonTransform>()->SetScale(Vector2(6.0f, 6.0f));

		HyeonScene::Initialize();
	}
	void HyeonMtWoeScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonMtWoeScene::LateUpdate()
	{
		HyeonScene::LateUpdate();
	}
	void HyeonMtWoeScene::Render(HDC hdc)
	{
		//HyeonScene::Render(hdc);
	}
	void HyeonMtWoeScene::OnEnter()
	{
		HyeonScene::OnEnter();
		HyeonCollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		//HyeonUIManager::Push(eUIType::Hpbar);
		/*renderer::mainCamera->SetTarget(Chrono);
		renderer::mainCamera->Update();*/
	}
	void HyeonMtWoeScene::OnExit()
	{
	}
}