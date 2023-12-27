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
		/*mState = HyeonBattlePlayerScript::eState::Attack;
		mAnimator->PlayAnimation(L"ChronoLeftAttack", false);*/

		/*HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		while (pos.X < 900.0f && pos.Y < 1000.0f)
		{
			pos.X += MonsterToPlayer.X;
			pos.Y += MonsterToPlayer.Y;
			tr->SetPosition(pos);
		}*/
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
				HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
				Vector2 pos = tr->GetPosition();
				playerToMonster = calculatingVector();

				while (pos.X > 650.0f && pos.Y > 800.0f)
				{
					pos.X += HyeonTime::GetDelataTime() * playerToMonster.X;
					pos.Y += HyeonTime::GetDelataTime() * playerToMonster.Y;
					tr->SetPosition(pos);
				}
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

	Vector2 HyeonBattlePlayerScript::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();
		
		Vector2 MonsterPos = HyeonBattleScene::GetMonsterPos();

		return (MonsterPos - pos).normalize();
	}
}