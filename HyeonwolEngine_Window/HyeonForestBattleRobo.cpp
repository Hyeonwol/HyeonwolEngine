#pragma once
#include "HyeonForestBattleRobo.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonInput.h"
#include "HyeonBattleGreenImpScript.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::eState mRoboState = HyeonBattlePlayerScript::eState::DrawWeapon;
	
	HyeonForestBattleRobo::HyeonForestBattleRobo()
		:mUsedSkills(eUsedSkills::Attack),
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0), 
		 AnimationTimer(0.0f)
	{
	}
	HyeonForestBattleRobo::~HyeonForestBattleRobo()
	{
	}
	void HyeonForestBattleRobo::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		startPosition = tr->GetPosition();

		mHp = 120;
	}
	void HyeonForestBattleRobo::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		HyeonBattlePlayerScript::Update();

		switch (mRoboState)
		{
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::MoveToMonster:
			moveToMonster();
			break;
		case eState::Attack:
			Hyeon::GreenImpState = HyeonBattleGreenImpScript::eState::Attacked;
			afterAttack();
			break;
		case eState::MoveToStartPoint:
			moveToStartPoint();
			break;
		case eState::Dead:
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonForestBattleRobo::LateUpdate()
	{
		HyeonBattlePlayerScript::LateUpdate();
	}
	void HyeonForestBattleRobo::Render(HDC hdc)
	{
		HyeonBattlePlayerScript::Render(hdc);
	}
	void HyeonForestBattleRobo::OnCollisionEnter(HyeonCollider* other)
	{
		if (isMonsterTurn == false)
		{
			switch (mUsedSkills)
			{
			case eUsedSkills::Attack:
				mRoboState = eState::Attack;
				mAnimator->PlayAnimation(L"RoboAttack", false);
				break;
			default:
				break;
			}

			playerToMonster.X *= -1;
			playerToMonster.Y *= -1;
		}

		else
		{
			mHp -= 30;
			if (mHp <= 0)
			{
				mAnimator->PlayAnimation(L"RoboDead", false);
				mRoboState = eState::Dead;
			}
		}
	}
	void HyeonForestBattleRobo::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonForestBattleRobo::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonForestBattleRobo::afterDrawWeapon()
	{
		if (isMonsterTurn == false)
		{
			if (GetKeyState(VK_SPACE) & 0x8000 &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mUsedSkills = eUsedSkills::Attack;
				playerToMonster = calculatingVector();
				mRoboState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
			else if (HyeonInput::GetKeyDown(eKeyCode::K) &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mUsedSkills = eUsedSkills::Skill1;
				mRoboState = eState::Attack;
				mAnimator->PlayAnimation(L"RoboSkill1", false);
			}
		}
		
		if (HyeonInput::GetKeyDown(eKeyCode::X) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
		{
			mRoboState = HyeonBattlePlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"RoboDead", false);
			mChosenChar = HyeonBattlePlayerScript::eCharacter::Chrono;
		}
	}
	void HyeonForestBattleRobo::afterAttack()
	{
		AnimationTimer += HyeonTime::GetDelataTime();

		if (mUsedSkills == eUsedSkills::Skill1)
		{
			mAnimator->PlayAnimation(L"RoboSkillEffect", false);
			if (AnimationTimer >= 4.5f)
				mRoboState = HyeonBattlePlayerScript::eState::MoveToStartPoint;
		}
		else
		{
			if (AnimationTimer >= 1.0f)
				mRoboState = HyeonBattlePlayerScript::eState::MoveToStartPoint;
		}
		
	}
	void HyeonForestBattleRobo::moveToMonster()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);
	}
	void HyeonForestBattleRobo::moveToStartPoint()
	{
		//벡터로 이동해서 공격 구현 중
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);

		if (pos.X <= startPosition.X ||
			pos.Y >= startPosition.Y)
		{
			mRoboState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"RoboDrawWeapon", false);
			AnimationTimer = 0.0f;
			isMonsterTurn = true;
			GreenImpState = HyeonBattleGreenImpScript::eState::MoveToPlayer;
		}
	}
	Vector2 HyeonForestBattleRobo::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		/*MonsterPos.Y -= 250.0f;*/

		return (MonsterPos - pos).normalize();
	}
}