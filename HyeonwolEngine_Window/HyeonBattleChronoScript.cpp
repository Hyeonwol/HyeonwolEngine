#include "HyeonBattleChronoScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonBattleChronoScript::HyeonBattleChronoScript()
		:mState(HyeonBattleChronoScript::eState::DrawWeapon),
		 mDir(HyeonBattleChronoScript::Character::Chrono),
		 mChronoAnimator(nullptr), 
		 mTime(0.0f), 
		 mHp(0), 
		 mStamina(0)
	{
	}
	HyeonBattleChronoScript::~HyeonBattleChronoScript()
	{
	}
	void HyeonBattleChronoScript::Initialize()
	{
	}
	void HyeonBattleChronoScript::Update()
	{
		HyeonBattlePlayerScript::Update();
		/*if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case HyeonBattleChronoScript::eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case HyeonBattleChronoScript::eState::Attack:
			afterAttack();
			break;
		default:
			assert(false);
			break;
		}*/
	}
	void HyeonBattleChronoScript::LateUpdate()
	{
	}
	void HyeonBattleChronoScript::Render(HDC hdc)
	{
	}

	void HyeonBattleChronoScript::drawWeapon()
	{
		/*if ((HyeonInput::GetKeyPressed(eKeyCode::W) ||
			HyeonInput::GetKeyPressed(eKeyCode::A) ||
			HyeonInput::GetKeyPressed(eKeyCode::S) ||
			HyeonInput::GetKeyPressed(eKeyCode::D)))
				walking();*/

		
		/*if (mDir == HyeonBattlePlayerScript::eDir::Up)
		{
			mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"ChronoUpDrawWeapon", false);
		}
		else */if (mDir == HyeonBattleChronoScript::Character::Chrono)
		{
			mState = HyeonBattleChronoScript::eState::DrawWeapon;
			mChronoAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			//mDir = HyeonBattleChronoScript::eDir::Right;
		}
		/*else if (mDir == HyeonBattlePlayerScript::eDir::Down)
		{
			mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"ChronoDownDrawWeapon", false);
		}
		else if (mDir == HyeonBattlePlayerScript::eDir::Right)
		{
			mState = HyeonBattlePlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"ChronoRightDrawWeapon", false);
		}*/

		afterDrawWeapon();
	}
	/*void HyeonPlayerScript::move()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			pos.X += 100.0f * HyeonTime::GetDelataTime();
		}

		else if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{
			pos.X -= 100.0f * HyeonTime::GetDelataTime();
		}

		else if(HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			pos.Y -= 100.0f * HyeonTime::GetDelataTime();
		}

		else if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			pos.Y += 100.0f * HyeonTime::GetDelataTime();
		}

		
		tr->SetPosition(pos);

		if (HyeonInput::GetKeyUp(eKeyCode::W) || 
			HyeonInput::GetKeyUp(eKeyCode::A) ||
			HyeonInput::GetKeyUp(eKeyCode::S) ||
			HyeonInput::GetKeyUp(eKeyCode::D))
		{
			relaxing();
		}
	}*/
	void HyeonBattleChronoScript::afterDrawWeapon()
	{
		if (GetKeyState(VK_SPACE) & 0x8000)		//Attack
		{
			/*if (mDir == HyeonBattlePlayerScript::eDir::Up)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoUpAttack", false);
			}
			else */if (mDir == HyeonBattleChronoScript::Character::Chrono)
			{
				Vector2 Monster(450.0f, 450.0f);
				Vector2 BattlePos(600.0f, 700.0f);

				Vector2 nPosToMonster = Monster - BattlePos;
				float betweenlen = nPosToMonster.length();
				nPosToMonster.normalize();


				
				/*mState = HyeonBattleChronoScript::eState::Attack;
				mChronoAnimator->PlayAnimation(L"ChronoLeftAttack", false);*/
			}
			/*else if (mDir == HyeonBattlePlayerScript::eDir::Down)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoDownAttack", false);
			}
			else if (mDir == HyeonBattlePlayerScript::eDir::Right)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoRightAttack", false);
			}*/
		}

		if (HyeonInput::GetKeyDown(eKeyCode::K))	//Skill1
		{
			/*if (mDir == HyeonBattlePlayerScript::eDir::Right)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoRightSkill1", false);
			}
			else */if (mDir == HyeonBattleChronoScript::Character::Chrono)
			{
				mState = HyeonBattleChronoScript::eState::Attack;
				mChronoAnimator->PlayAnimation(L"ChronoLeftSkill1", false);
			}
		}

		if (HyeonInput::GetKeyDown(eKeyCode::L))
		{
			/*if (mDir == HyeonBattlePlayerScript::eDir::Right)
			{
				mState = HyeonBattlePlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoRightSkill2", false);
			}
			else */if (mDir == HyeonBattleChronoScript::Character::Chrono)
			{
				mState = HyeonBattleChronoScript::eState::Attack;
				mChronoAnimator->PlayAnimation(L"ChronoLeftSkill2", false);
			}
			
		}

		//if ((HyeonInput::GetKeyPressed(eKeyCode::W) ||	//Moving
		//	HyeonInput::GetKeyPressed(eKeyCode::A) ||
		//	HyeonInput::GetKeyPressed(eKeyCode::S) ||
		//	HyeonInput::GetKeyPressed(eKeyCode::D)))
		//		walking();
	}
	void HyeonBattleChronoScript::afterAttack()
	{
		mTime += HyeonTime::GetDelataTime();

		if (mTime > 0.8f)
		{
			//DrawWeapon
			/*if (mDir == HyeonBattlePlayerScript::eDir::Up)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoUpDrawWeapon", false);
			}
			else */if (mDir == HyeonBattleChronoScript::Character::Chrono)
			{
				mState = HyeonBattleChronoScript::eState::DrawWeapon;
				mChronoAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			}
			/*else if (mDir == HyeonBattlePlayerScript::eDir::Down)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoDownDrawWeapon", false);
			}
			else if (mDir == HyeonBattlePlayerScript::eDir::Right)
			{
				mState = HyeonBattlePlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoRightDrawWeapon", false);
			}*/
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