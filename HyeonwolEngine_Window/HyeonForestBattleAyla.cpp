#pragma once
#include "HyeonForestBattleAyla.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonInput.h"

namespace Hyeon
{
	HyeonForestBattleAyla::HyeonForestBattleAyla()
		:mAylaState(HyeonBattlePlayerScript::eState::DrawWeapon),
		 mUsedSkills(eUsedSkills::Attack),
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0)
	{
	}
	HyeonForestBattleAyla::~HyeonForestBattleAyla()
	{
	}
	void HyeonForestBattleAyla::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
	}
	void HyeonForestBattleAyla::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mAylaState)
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
	}
	void HyeonForestBattleAyla::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonForestBattleAyla::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonForestBattleAyla::afterDrawWeapon()
	{
		if (GetKeyState(VK_SPACE) & 0x8000 && 
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
		{
			mUsedSkills = eUsedSkills::Attack;
			playerToMonster = calculatingVector();
			mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
			moving();
		}
		else if (HyeonInput::GetKeyDown(eKeyCode::K) && 
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
		{
			mUsedSkills = eUsedSkills::Skill1;
			playerToMonster = calculatingVector();
			mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
			moving();
		}
		else if (HyeonInput::GetKeyDown(eKeyCode::L) && 
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
		{
			mUsedSkills = eUsedSkills::Skill2;
			playerToMonster = calculatingVector();
			mAylaState = HyeonBattlePlayerScript::eState::MoveToMonster;
			moving();
		}
		else if (HyeonInput::GetKeyDown(eKeyCode::X) &&
			HyeonBattlePlayerScript::mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
		{
			mAylaState = HyeonBattlePlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"AylaDead", false);
			mChosenChar = HyeonBattlePlayerScript::eCharacter::Robo;
		}
	}
	void HyeonForestBattleAyla::afterAttack()
	{
	}
	void HyeonForestBattleAyla::moving()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 700.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 700.0f;

		tr->SetPosition(pos);
	}
	Vector2 HyeonForestBattleAyla::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();
		MonsterPos.X += 80.0f;
		MonsterPos.Y -= 50.0f;

		return (MonsterPos - pos).normalize();
	}
}