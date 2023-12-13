#include "HyeonBattlePlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::HyeonBattlePlayerScript()
		:mState(HyeonBattlePlayerScript::eState::DrawWeapon), 
		 mChosenChar(HyeonBattlePlayerScript::Character::Chrono), 
		 mAnimator(nullptr), 
		 mTime(0.0f), 
		 mHp(0), 
		 mStamina(0)
	{
	}
	HyeonBattlePlayerScript::~HyeonBattlePlayerScript()
	{
	}
	void HyeonBattlePlayerScript::Initialize()
	{
	}
	void HyeonBattlePlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case HyeonBattlePlayerScript::eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case HyeonBattlePlayerScript::eState::Attack:
			afterAttack();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonBattlePlayerScript::LateUpdate()
	{
	}
	void HyeonBattlePlayerScript::Render(HDC hdc)
	{
	}

	void HyeonBattlePlayerScript::afterDrawWeapon()
	{
		if (GetKeyState(VK_F1) & 0x8000)
			mChosenChar = Character::Chrono;
		else if (GetKeyState(VK_F2) & 0x8000)
			mChosenChar = Character::Ayla;
		else if (GetKeyState(VK_F3) & 0x8000)
			mChosenChar = Character::Marle;


		if (GetKeyState(VK_SPACE) & 0x8000)		//Attack
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				playerToMonster = Vector2(650.0f, 750.0f) - Vector2(900.0f, 1200.0f);
				playerToMonster.normalize();


				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
			}
			
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightAttack", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::K))	//Skill1
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill1", false);
			}
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightSkill1", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::L))
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill2", false);
			}
			
		}
	}
	void HyeonBattlePlayerScript::afterAttack()
	{
		mTime += HyeonTime::GetDelataTime();

		if (mTime > 0.8f)
		{
			//DrawWeapon
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			}

			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);
			}
			mTime = 0.0f;
		}
	}

	/*void HyeonPlayerScript::walking()
	{
		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"ChronoRightWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"ChronoLeftWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"ChronoUpWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"ChronoDownWalk");
		}
	}*/
	/*void HyeonPlayerScript::relaxing()
	{
		if (HyeonInput::GetKeyUp(eKeyCode::W))
		{
			mState = HyeonPlayerScript::eState::Relax;
			mDir = HyeonPlayerScript::eDir::Up;
			mAnimator->PlayAnimation(L"ChronoUpRelax", false);
		}
		else if (HyeonInput::GetKeyUp(eKeyCode::S))
		{
			mState = HyeonPlayerScript::eState::Relax;
			mDir = HyeonPlayerScript::eDir::Down;
			mAnimator->PlayAnimation(L"ChronoDownRelax", false);
		}

		else if (HyeonInput::GetKeyUp(eKeyCode::D))
		{
			mState = HyeonPlayerScript::eState::Relax;
			mDir = HyeonPlayerScript::eDir::Right;
			mAnimator->PlayAnimation(L"ChronoRightRelax", false);
		}
		else if (HyeonInput::GetKeyUp(eKeyCode::A))
		{
			mState = HyeonPlayerScript::eState::Relax;
			mDir = HyeonPlayerScript::eDir::Left;
			mAnimator->PlayAnimation(L"ChronoLeftRelax", false);
		}
	}*/

	/*void HyeonBattlePlayerScript::setDir()
	{
		if (HyeonInput::GetKeyDown(eKeyCode::W))
			mDir = HyeonBattlePlayerScript::eDir::Up;
		else if (HyeonInput::GetKeyDown(eKeyCode::A))
			mDir = HyeonBattlePlayerScript::eDir::Left;
		else if (HyeonInput::GetKeyDown(eKeyCode::S))
			mDir = HyeonBattlePlayerScript::eDir::Down;
		else if (HyeonInput::GetKeyDown(eKeyCode::D))
			mDir = HyeonBattlePlayerScript::eDir::Right;
	}*/
}