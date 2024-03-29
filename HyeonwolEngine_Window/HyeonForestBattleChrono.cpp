#pragma once
#include "HyeonForestBattleChrono.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonInput.h"
#include "HyeonBattleGreenImpScript.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::eState mChronoState = HyeonBattlePlayerScript::eState::DrawWeapon;

	HyeonForestBattleChrono::HyeonForestBattleChrono()
		:mUsedSkills(eUsedSkills::Attack), 
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0), 
		 AnimationTimer(0.0f)
	{
	}
	HyeonForestBattleChrono::~HyeonForestBattleChrono()
	{
	}
	void HyeonForestBattleChrono::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		startPosition = tr->GetPosition();

		mHp = 100;
	}
	void HyeonForestBattleChrono::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		HyeonBattlePlayerScript::Update();

		switch (mChronoState)
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
	void HyeonForestBattleChrono::LateUpdate()
	{
		HyeonBattlePlayerScript::LateUpdate();
	}
	void HyeonForestBattleChrono::Render(HDC hdc)
	{
		HyeonBattlePlayerScript::Render(hdc);
	}
	void HyeonForestBattleChrono::OnCollisionEnter(HyeonCollider* other)
	{
		if (isMonsterTurn == false)
		{
			switch (mUsedSkills)
			{
			case eUsedSkills::Attack:
				mChronoState = eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
				break;
			case eUsedSkills::Skill1:
				mChronoState = eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill1", false);
				break;
			case eUsedSkills::Skill2:
				mChronoState = eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill2", false);
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
				mAnimator->PlayAnimation(L"ChronoDead", false);
				mChronoState = eState::Dead;
			}
		}
	}
	void HyeonForestBattleChrono::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonForestBattleChrono::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonForestBattleChrono::afterDrawWeapon()
	{
		if (isMonsterTurn == false)
		{
			if (GetKeyState(VK_SPACE) & 0x8000 &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mUsedSkills = eUsedSkills::Attack;
				playerToMonster = calculatingVector();
				mChronoState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
			else if (HyeonInput::GetKeyDown(eKeyCode::K) &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mUsedSkills = eUsedSkills::Skill1;
				playerToMonster = calculatingVector();
				mChronoState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
			else if (HyeonInput::GetKeyDown(eKeyCode::L) &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mUsedSkills = eUsedSkills::Skill2;
				playerToMonster = calculatingVector();
				mChronoState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::X) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
		{
			mChronoState = HyeonBattlePlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"ChronoDead", false);
			mChosenChar = HyeonBattlePlayerScript::eCharacter::Ayla;
		}
	}
	void HyeonForestBattleChrono::afterAttack()
	{
		AnimationTimer += HyeonTime::GetDelataTime();

		if (AnimationTimer >= 1.0f)
		{
			mChronoState = HyeonBattlePlayerScript::eState::MoveToStartPoint;
		}
	}
	void HyeonForestBattleChrono::moveToMonster()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);
	}
	void HyeonForestBattleChrono::moveToStartPoint()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);

		if (pos.X >= startPosition.X ||
			pos.Y >= startPosition.Y)
		{
			mChronoState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			AnimationTimer = 0.0f;
			isMonsterTurn = true;
			GreenImpState = HyeonBattleGreenImpScript::eState::MoveToPlayer;
		}
	}
	Vector2 HyeonForestBattleChrono::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();
		
		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		/*MonsterPos.X += 80.0f;
		MonsterPos.Y -= 50.0f;*/

		return (MonsterPos - pos).normalize();
	}
}