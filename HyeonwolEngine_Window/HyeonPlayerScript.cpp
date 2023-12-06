#include "HyeonPlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"

namespace Hyeon
{
	HyeonPlayerScript::HyeonPlayerScript()
		:mState(HyeonPlayerScript::eState::Relax), 
		 mDir(HyeonPlayerScript::eDir::Down), 
		 mTime(0.0f), 
		 mAnimator(nullptr)
	{
	}
	HyeonPlayerScript::~HyeonPlayerScript()
	{
	}
	void HyeonPlayerScript::Initialize()
	{
	}
	void HyeonPlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case HyeonPlayerScript::eState::Relax:
			relax();
			break;
		case HyeonPlayerScript::eState::Walk:
			move();
			break;
		case HyeonPlayerScript::eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case HyeonPlayerScript::eState::Attack:
			afterAttack();
			break;
		default:
			break;
		}
	}
	void HyeonPlayerScript::LateUpdate()
	{
	}
	void HyeonPlayerScript::Render(HDC hdc)
	{
	}

	void HyeonPlayerScript::relax()
	{

		if ((HyeonInput::GetKeyPressed(eKeyCode::W) ||
			HyeonInput::GetKeyPressed(eKeyCode::A) ||
			HyeonInput::GetKeyPressed(eKeyCode::S) ||
			HyeonInput::GetKeyPressed(eKeyCode::D)))
				walking();

		
		if (HyeonInput::GetKeyPressed(eKeyCode::Z))  //DrawWeapon
		{
			if (mDir == HyeonPlayerScript::eDir::Up)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoUpDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Left)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Down)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoDownDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Right)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoRightDrawWeapon", false);
			}
		}

		if (mState == eState::DrawWeapon)
			afterDrawWeapon();
	}
	void HyeonPlayerScript::move()
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
	}
	void HyeonPlayerScript::afterDrawWeapon()
	{
		if (GetKeyState(VK_SPACE) & 0x8000)		//Attack
		{
			if (mDir == HyeonPlayerScript::eDir::Up)
			{
				mState = HyeonPlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoUpAttack", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Left)
			{
				mState = HyeonPlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Down)
			{
				mState = HyeonPlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoDownAttack", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Right)
			{
				mState = HyeonPlayerScript::eState::Attack;
				mAnimator->PlayAnimation(L"ChronoRightAttack", false);
			}
		}

		if ((HyeonInput::GetKeyPressed(eKeyCode::W) ||	//Moving
			HyeonInput::GetKeyPressed(eKeyCode::A) ||
			HyeonInput::GetKeyPressed(eKeyCode::S) ||
			HyeonInput::GetKeyPressed(eKeyCode::D)))
				walking();
	}
	void HyeonPlayerScript::afterAttack()
	{
		mTime += HyeonTime::GetDelataTime();

		if (mTime > 1.0f)
		{
			//DrawWeapon
			if (mDir == HyeonPlayerScript::eDir::Up)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoUpDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Left)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoLeftDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Down)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoDownDrawWeapon", false);
			}
			else if (mDir == HyeonPlayerScript::eDir::Right)
			{
				mState = HyeonPlayerScript::eState::DrawWeapon;
				mAnimator->PlayAnimation(L"ChronoRightDrawWeapon", false);
			}
			mTime = 0.0f;
		}
	}

	void HyeonPlayerScript::walking()
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
	}
	void HyeonPlayerScript::relaxing()
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
	}
}