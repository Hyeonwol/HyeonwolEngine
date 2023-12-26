#include "HyeonBattlePlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTime.h"
#include "HyeonEntity.h"
#include "HyeonBattleScene.h"
#include "HyeonUIManager.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::HyeonBattlePlayerScript()
		:mState(HyeonBattlePlayerScript::eState::DrawWeapon), 
		 mChosenChar(HyeonBattlePlayerScript::Character::Chrono), 
		 mAnimator(nullptr), 
		 mTime(0.0f), 
		 mHp(0), 
		 isAylaUseSkill1(false), 
		 isRoboUseSkill(false), 
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
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::Attack:
			afterAttack();
			break;
		case eState::Dead:
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

	void HyeonBattlePlayerScript::OnCollisionEnter(HyeonCollider* other)
	{
		mState = HyeonBattlePlayerScript::eState::Attack;
		mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
	}

	void HyeonBattlePlayerScript::OnCollisionStay(HyeonCollider* other)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionExit(HyeonCollider* other)
	{
	}

	void HyeonBattlePlayerScript::afterDrawWeapon()
	{
		if (GetKeyState(VK_F1) & 0x8000)
			mChosenChar = Character::Chrono;
		else if (GetKeyState(VK_F2) & 0x8000)
			mChosenChar = Character::Ayla;
		else if (GetKeyState(VK_F3) & 0x8000)
			mChosenChar = Character::Robo;

		if (GetKeyState(VK_SPACE) & 0x8000)		//Attack
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				//벡터로 이동해서 공격 구현 중
				playerToMonster = Vector2(650.0f, 800.0f) - Vector2(900.0f, 1000.0f);
				playerToMonster.normalize();

				HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
				Vector2 pos = tr->GetPosition();
				
				while (pos.X > 700.0f && pos.Y > 800.0f)
				{
					pos.X += playerToMonster.X;
					pos.Y += playerToMonster.Y;
					tr->SetPosition(pos);
				}

				/*mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftAttack", false);*/
			}
			
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightAttack", false);
			}

			else if (mChosenChar == HyeonBattlePlayerScript::Character::Robo)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"RoboAttack", false);
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
				isAylaUseSkill1 = true;
				mAnimator->PlayAnimation(L"AylaRightSkill1", false);
			}
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Robo)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				isRoboUseSkill = true;
				mAnimator->PlayAnimation(L"RoboSkill1", false);
			}
			
		}

		if (HyeonInput::GetKeyDown(eKeyCode::L))
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill2", false);
			}
			
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightSkill2", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::X))	//Dead
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Chrono)
			{
				mState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"ChronoDead", false);
				mChosenChar = HyeonBattlePlayerScript::Character::Ayla;
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"AylaDead", false);
				mChosenChar = HyeonBattlePlayerScript::Character::Robo;
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Robo)
			{
				mState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"RoboDead", false);
				mChosenChar = HyeonBattlePlayerScript::Character::Chrono;
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
		}
	}
	void HyeonBattlePlayerScript::afterAttack()
	{
		mTime += HyeonTime::GetDelataTime();

		if ((mTime > 0.8f && isRoboUseSkill == false) && (mTime > 0.8f && isAylaUseSkill1 == false))
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

			else if (mChosenChar == HyeonBattlePlayerScript::Character::Robo)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"RoboDrawWeapon", false);
			}
			mTime = 0.0f;
		}

		else if ((isRoboUseSkill == true && mTime > 5.5f) || (isAylaUseSkill1 == true && mTime > 1.5f))
		{
			if (mChosenChar == HyeonBattlePlayerScript::Character::Ayla)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);
				isAylaUseSkill1 = false;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::Character::Robo)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"RoboDrawWeapon", false);
				isRoboUseSkill = false;
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