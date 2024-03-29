#pragma once
#include "HyeonForestBattleAyla.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonInput.h"
#include "HyeonBattleGreenImpScript.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::eState mAylaState = HyeonBattlePlayerScript::eState::DrawWeapon;

	HyeonForestBattleAyla::HyeonForestBattleAyla()
		:mUsedSkills(eUsedSkills::Attack),
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0), 
		 AnimationTimer(0.0f)
	{
	}
	HyeonForestBattleAyla::~HyeonForestBattleAyla()
	{
	}
	void HyeonForestBattleAyla::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		startPosition = tr->GetPosition();

		mHp = 80;
	}
	void HyeonForestBattleAyla::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		HyeonBattlePlayerScript::Update();

		switch (mAylaState)
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
	void HyeonForestBattleAyla::LateUpdate()
	{
		HyeonBattlePlayerScript::LateUpdate();
	}
	void HyeonForestBattleAyla::Render(HDC hdc)
	{
		HyeonBattlePlayerScript::Render(hdc);
	}
	void HyeonForestBattleAyla::OnCollisionEnter(HyeonCollider* other)
	{
		if (isMonsterTurn == false)
		{
			switch (mUsedSkills)
			{
			case eUsedSkills::Attack:
				mAylaState = eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightAttack", false);
				break;
			case eUsedSkills::Skill1:
				mAylaState = eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightSkill1", false);
				break;
			case eUsedSkills::Skill2:
				mAylaState = eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightSkill2", false);
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
				mAnimator->PlayAnimation(L"AylaDead", false);
				mAylaState = eState::Dead;
			}
		}
	}
	void HyeonForestBattleAyla::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonForestBattleAyla::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonForestBattleAyla::afterDrawWeapon()
	{
		if (isMonsterTurn == false)
		{
			if (GetKeyState(VK_SPACE) & 0x8000 &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mUsedSkills = eUsedSkills::Attack;
				playerToMonster = calculatingVector();
				mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
			else if (HyeonInput::GetKeyDown(eKeyCode::K) &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mUsedSkills = eUsedSkills::Skill1;
				playerToMonster = calculatingVector();
				mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
			else if (HyeonInput::GetKeyDown(eKeyCode::L) &&
				HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mUsedSkills = eUsedSkills::Skill2;
				playerToMonster = calculatingVector();
				mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
				moveToMonster();
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::X) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
		{
			mAylaState = HyeonBattlePlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"AylaDead", false);
			mChosenChar = HyeonBattlePlayerScript::eCharacter::Robo;
		}
	}
	void HyeonForestBattleAyla::afterAttack()
	{
		AnimationTimer += HyeonTime::GetDelataTime();

		if (AnimationTimer >= 1.5f)
		{
			mAylaState = HyeonBattlePlayerScript::eState::MoveToStartPoint;
		}
	}
	void HyeonForestBattleAyla::moveToMonster()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);
	}
	void HyeonForestBattleAyla::moveToStartPoint()
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
			mAylaState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);
			AnimationTimer = 0.0f;
			isMonsterTurn = true;
			GreenImpState = HyeonBattleGreenImpScript::eState::MoveToPlayer;
		}
	}
	Vector2 HyeonForestBattleAyla::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		/*MonsterPos.X += 80.0f;
		MonsterPos.Y -= 50.0f;*/

		return (MonsterPos - pos).normalize();
	}
}