#pragma once
#include "HyeonBattleGreenImpScript.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonGameObject.h"
#include "HyeonCamera.h"
#include "HyeonRenderer.h"
#include "HyeonForestBattleScene.h"
#include "HyeonBattlePlayerScript.h"
#include "HyeonTransform.h"
#include "HyeonTime.h"

extern Hyeon::HyeonCamera* Hyeon::renderer::mainCamera;

namespace Hyeon
{
	HyeonBattleGreenImpScript::HyeonBattleGreenImpScript()
		:mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0), 
		 mTargetNum(-1), 
		 AnimationTimer(0.0f), 
		 isSetTarget(false)
	{
	}
	HyeonBattleGreenImpScript::~HyeonBattleGreenImpScript()
	{
	}
	void HyeonBattleGreenImpScript::Initialize()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		startPosition = tr->GetPosition();

		mHp = 300;
	}
	void HyeonBattleGreenImpScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		//HyeonForestImpsScript::Update();

		switch (GreenImpState)
		{
		case eState::Idle:
			break;
		case eState::Attacked:
			mAnimator->PlayAnimation(L"GreenImpAttacked");
			afterAttacked();
			break;
		case eState::MoveToPlayer:
			moveToPlayer();
			break;
		case eState::MoveToStartPoint:
			moveToStartPoint();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonBattleGreenImpScript::LateUpdate()
	{
	}
	void HyeonBattleGreenImpScript::Render(HDC hdc)
	{
	}

	void HyeonBattleGreenImpScript::OnCollisionEnter(HyeonCollider* other)
	{
		if (isMonsterTurn == true)
		{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			
			MonsterToPlayer.X = HyeonForestBattleScene::GetMonsterPos().X - tr->GetPosition().X;
			MonsterToPlayer.Y = HyeonForestBattleScene::GetMonsterPos().Y - tr->GetPosition().Y;
			MonsterToPlayer.normalize();
			GreenImpState = eState::MoveToStartPoint;
		}
	}

	void HyeonBattleGreenImpScript::OnCollisionStay(HyeonCollider* other)
	{
	}

	void HyeonBattleGreenImpScript::OnCollisionExit(HyeonCollider* other)
	{
	}

	void HyeonBattleGreenImpScript::afterAttacked()
	{
		AnimationTimer += HyeonTime::GetDelataTime();

		if (AnimationTimer >= 0.5f)
			mAnimator->PlayAnimation(L"GreenImpIdle");
	}

	void HyeonBattleGreenImpScript::moveToPlayer()
	{
		if (isSetTarget == false)
		{
			setAttackTarget();
			isSetTarget = true;
		}

		//if (mChosenMonster == eChosenMonster::Imp1)
		//{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPosition();

			pos.X += MonsterToPlayer.X * HyeonTime::GetDelataTime() * 2000.0f;
			pos.Y += MonsterToPlayer.Y * HyeonTime::GetDelataTime() * 2000.0f;

			tr->SetPosition(pos);
		//}
	}

	void HyeonBattleGreenImpScript::moveToStartPoint()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		pos.X += MonsterToPlayer.X * HyeonTime::GetDelataTime() * 2000.0f;
		pos.Y += MonsterToPlayer.Y * HyeonTime::GetDelataTime() * 2000.0f;

		tr->SetPosition(pos);

		if (pos.Y <= startPosition.Y)
		{
			AnimationTimer = 0.0f;
			GreenImpState = HyeonBattleGreenImpScript::eState::Idle;
			isMonsterTurn = false;
			isSetTarget = false;
		}
	}

	void HyeonBattleGreenImpScript::setAttackTarget()
	{
		mTargetNum = rand() % 3;
		switch (mTargetNum)
		{
		case 0:
			mTarget = HyeonBattlePlayerScript::eCharacter::Chrono;
			break;
		case 1:
			mTarget = HyeonBattlePlayerScript::eCharacter::Ayla;
			break;
		case 2:
			mTarget = HyeonBattlePlayerScript::eCharacter::Robo;
			break;
		}

		MonsterToPlayer = calculatingVector();
	}

	Vector2 HyeonBattleGreenImpScript::calculatingVector()
	{
		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		Vector2 ChronoPos = HyeonForestBattleScene::GetChronoPos();
		Vector2 AylaPos = HyeonForestBattleScene::GetAylaPos();
		Vector2 RoboPos = HyeonForestBattleScene::GetRoboPos();

		switch (mTarget)
		{
		case HyeonBattlePlayerScript::eCharacter::Chrono:
			/*MonsterPos.X += 80.0f;
			MonsterPos.Y -= 50.0f;*/
			return (ChronoPos - MonsterPos).normalize();
			break;
		case HyeonBattlePlayerScript::eCharacter::Ayla:
			/*MonsterPos.X += 80.0f;
			MonsterPos.Y -= 50.0f;*/
			return (AylaPos - MonsterPos).normalize();
			break;
		case HyeonBattlePlayerScript::eCharacter::Robo:
			/*MonsterPos.Y -= 250.0f;*/
			return (RoboPos - MonsterPos).normalize();
			break;
		default:
			assert(false);
			break;
		}
	}
}