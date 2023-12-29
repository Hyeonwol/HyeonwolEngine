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
		HyeonGameObject* camera = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::None);
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;

		//background
		HyeonGameObject* bg = object::Instantiate<HyeonGameObject>
			(enums::eLayerType::BackGround/*, Vector2(-230.0f, -130)*/);
		HyeonSpriteRenderer* bgSr = bg->AddComponent<HyeonSpriteRenderer>();
		bgSr->SetSize(Vector2(6.0f, 6.0f));

		graphics::HyeonTexture* bgTexture = HyeonResources::Find<graphics::HyeonTexture>(L"MountainBG");
		bgSr->SetTexture(bgTexture);


	}
	void HyeonMtWoeScene::Update()
	{
	}
	void HyeonMtWoeScene::LateUpdate()
	{
	}
	void HyeonMtWoeScene::Render(HDC hdc)
	{
	}
	void HyeonMtWoeScene::OnEnter()
	{
		HyeonScene::OnEnter();
		HyeonCollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		//HyeonUIManager::Push(eUIType::Hpbar);
		renderer::mainCamera->SetTarget(Chrono);
		renderer::mainCamera->Update();
	}
	void HyeonMtWoeScene::OnExit()
	{
	}
}