#include "HyeonBattlePlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTime.h"
#include "HyeonEntity.h"
#include "HyeonForestBattleScene.h"
#include "HyeonUIManager.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::HyeonBattlePlayerScript()
		:mChronoState(HyeonBattlePlayerScript::eState::DrawWeapon), 
		 mAylaState(HyeonBattlePlayerScript::eState::DrawWeapon), 
		 mRoboState(HyeonBattlePlayerScript::eState::DrawWeapon), 
		 mChosenChar(HyeonBattlePlayerScript::eCharacter::Chrono), 
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

		//stateSwitching();
	}
	void HyeonBattlePlayerScript::LateUpdate()
	{
	}
	void HyeonBattlePlayerScript::Render(HDC hdc)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionEnter(HyeonCollider* other)
	{
		mChronoState = HyeonBattlePlayerScript::eState::Attack;
		mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
		
		/*HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();*/
		
		/*while (pos.X < 900.0f && pos.Y < 1000.0f)
		{
			pos.Y -= playerToMonster.Y;
			pos.X -= playerToMonster.X;
			tr->SetPosition(pos);
		}*/
	}

	void HyeonBattlePlayerScript::OnCollisionStay(HyeonCollider* other)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionExit(HyeonCollider* other)
	{
	}

	/*void HyeonBattlePlayerScript::stateSwitching()
	{
		

		switch (mAylaState)
		{
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::Move:
			moving(mChosenChar);
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

		switch (mRoboState)
		{
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::Move:
			moving(mChosenChar);
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
	}*/

	void HyeonBattlePlayerScript::afterDrawWeapon()
	{
		if (GetKeyState(VK_F1) & 0x8000)
			mChosenChar = eCharacter::Chrono;
		else if (GetKeyState(VK_F2) & 0x8000)
			mChosenChar = eCharacter::Ayla;
		else if (GetKeyState(VK_F3) & 0x8000)
			mChosenChar = eCharacter::Robo;

		if (GetKeyState(VK_SPACE) & 0x8000)		//Attack
		{
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				/*playerToMonster = calculatingVector();
				mChronoState = HyeonBattlePlayerScript::eState::Move;
				moving();*/
				
			}
			
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightAttack", false);
			}

			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mRoboState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"RoboAttack", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::K))	//Skill1
		{
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mChronoState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill1", false);
			}
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::Attack;
				isAylaUseSkill1 = true;
				mAnimator->PlayAnimation(L"AylaRightSkill1", false);
			}
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mRoboState = HyeonBattlePlayerScript::eState::Attack;
				isRoboUseSkill = true;
				mAnimator->PlayAnimation(L"RoboSkill1", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::L))
		{
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mChronoState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftSkill2", false);
			}
			
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"AylaRightSkill2", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::X))	//Dead
		{
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mChronoState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"ChronoDead", false);
				mChosenChar = HyeonBattlePlayerScript::eCharacter::Ayla;
				mAylaState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"AylaDead", false);
				mChosenChar = HyeonBattlePlayerScript::eCharacter::Robo;
				mRoboState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mRoboState = HyeonBattlePlayerScript::eState::Dead;
				mAnimator->PlayAnimation(L"RoboDead", false);
				mChosenChar = HyeonBattlePlayerScript::eCharacter::Chrono;
				mChronoState = HyeonBattlePlayerScript::eState::DrawWeapon;
			}
		}
	}

	void HyeonBattlePlayerScript::moving()
	{	
		//벡터로 이동해서 공격 구현 중
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 400.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 400.0f;

		tr->SetPosition(pos);
		
	}
	void HyeonBattlePlayerScript::afterAttack()
	{
		mTime += HyeonTime::GetDelataTime();

		if ((mTime > 0.8f && isRoboUseSkill == false) && (mTime > 0.8f && isAylaUseSkill1 == false))
		{
			//DrawWeapon
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Chrono)
			{
				mChronoState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			}

			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);
			}

			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mRoboState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"RoboDrawWeapon", false);
			}
			mTime = 0.0f;
		}

		else if ((isRoboUseSkill == true && mTime > 5.5f) || (isAylaUseSkill1 == true && mTime > 1.5f))
		{
			if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Ayla)
			{
				mAylaState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"AylaRightDrawWeapon", false);
				isAylaUseSkill1 = false;
			}
			else if (mChosenChar == HyeonBattlePlayerScript::eCharacter::Robo)
			{
				mRoboState = HyeonBattlePlayerScript::eState::DrawWeapon;
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
		
		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();

		return (MonsterPos - pos).normalize();
	}
}