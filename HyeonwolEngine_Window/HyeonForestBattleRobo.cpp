#pragma once
#include "HyeonForestBattleRobo.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonInput.h"

namespace Hyeon
{
	HyeonForestBattleRobo::HyeonForestBattleRobo()
		:mRoboState(HyeonBattlePlayerScript::eState::DrawWeapon),
		 mUsedSkills(eUsedSkills::Attack),
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0)
	{
	}
	HyeonForestBattleRobo::~HyeonForestBattleRobo()
	{
	}
	void HyeonForestBattleRobo::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
	}
	void HyeonForestBattleRobo::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mRoboState)
		{
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::MoveToMonster:
			moving();
			break;
		case eState::Attack:
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
		switch (mUsedSkills)
		{
		case eUsedSkills::Attack:
			mRoboState = eState::Attack;
			mAnimator->PlayAnimation(L"RoboAttack", false);
			break;
		default:
			break;
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
		if (GetKeyState(VK_SPACE) & 0x8000 &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
		{
			mUsedSkills = eUsedSkills::Attack;
			playerToMonster = calculatingVector();
			mRoboState = HyeonBattlePlayerScript::eState::MoveToMonster;
			moving();
		}
		else if (HyeonInput::GetKeyDown(eKeyCode::K) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
		{
			mUsedSkills = eUsedSkills::Skill1;
			mRoboState = eState::Attack;
			mAnimator->PlayAnimation(L"RoboSkill1", false);
		}
		else if (HyeonInput::GetKeyDown(eKeyCode::X) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
		{
			mRoboState = HyeonBattlePlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"RoboDead", false);
			mChosenChar = HyeonBattlePlayerScript::eCharacter::Chrono;
		}
	}
	void HyeonForestBattleRobo::afterAttack()
	{
	}
	void HyeonForestBattleRobo::moving()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);
	}
	Vector2 HyeonForestBattleRobo::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		MonsterPos.Y -= 250.0f;

		return (MonsterPos - pos).normalize();
	}
}