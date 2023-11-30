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
			drawWeapon();
			break;
		case HyeonPlayerScript::eState::Attack:
			attack();
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
		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		//if (HyeonInput::GetKeyPressed(eKeyCode::A))
		//{
		//	mState = HyeonPlayerScript::eState::Walk;
		//}
		if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mState = HyeonPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::Z))
		{
			mState = HyeonPlayerScript::eState::DrawWeapon;
			mAnimator->PlayAnimation(L"DrawWeapon", false);
		}
		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			mState = HyeonPlayerScript::eState::Attack;
			mAnimator->PlayAnimation(L"Attack", false);
		}
	}
	void HyeonPlayerScript::move()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			pos.X += 100.0f * HyeonTime::GetDelataTime();
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
			HyeonInput::GetKeyUp(eKeyCode::S) ||
			HyeonInput::GetKeyUp(eKeyCode::D))
		{
			mState = HyeonPlayerScript::eState::Relax;
			mAnimator->PlayAnimation(L"Relax", false);
		}
	}
	void HyeonPlayerScript::drawWeapon()
	{
		if (HyeonInput::GetKeyDown(eKeyCode::W) ||
			HyeonInput::GetKeyDown(eKeyCode::S) ||
			HyeonInput::GetKeyDown(eKeyCode::D))
		{
			mState = HyeonPlayerScript::eState::Walk;
		}
	}
	void HyeonPlayerScript::attack()
	{
	}
}
