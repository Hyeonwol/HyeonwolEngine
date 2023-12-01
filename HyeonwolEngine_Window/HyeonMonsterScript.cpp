#include "HyeonMonsterScript.h"
#include "HyeonAnimator.h"
#include "HyeonGameObject.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonMonsterScript::HyeonMonsterScript()
		:mState(HyeonMonsterScript::eState::Laugh), 
		 mAnimator(nullptr),
		 mTime(0.0f)
	{
	}
	HyeonMonsterScript::~HyeonMonsterScript()
	{
	}
	void HyeonMonsterScript::Initialize()
	{
	}
	void HyeonMonsterScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator->GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case eState::Laugh:
			laugh();
			break;
		case eState::Walk:
			move();
			break;
		case eState::Jump:
			jump();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonMonsterScript::LateUpdate()
	{
	}
	void HyeonMonsterScript::Render(HDC hdc)
	{
	}
	void HyeonMonsterScript::laugh()
	{
		mTime += HyeonTime::GetDelataTime();
		if (mTime > 2.0f)
		{
			mState = HyeonMonsterScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDir(mDirection);
			mTime = 0.0f;
		}

	}
	void HyeonMonsterScript::move()
	{
		mTime += HyeonTime::GetDelataTime();

		if (mTime > 2.0f)
		{
			int isJump = rand() % 2;
			if (isJump)
			{
				mState = HyeonMonsterScript::eState::Jump;
				mAnimator->PlayAnimation(L"ImpJump", false);
			}
			else
			{
				mState = HyeonMonsterScript::eState::Laugh;
				mAnimator->PlayAnimation(L"ImpLaugh", false);
			}

			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			translate(tr);
		}
	}
	void HyeonMonsterScript::jump()
	{
		mTime += HyeonTime::GetDelataTime();
		if (mTime > 1.0f)
		{
			mState = HyeonMonsterScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDir(mDirection);
			mTime = 0.0f;
		}
	}
	void HyeonMonsterScript::PlayWalkAnimationByDir(eDirection dir)
	{
		switch (dir)
		{
		case eDirection::Left:
			mAnimator->PlayAnimation(L"ImpLeftWalk");
			break;
		case eDirection::Right:
			mAnimator->PlayAnimation(L"ImpRightWalk");
			break;
		case eDirection::Up:
			mAnimator->PlayAnimation(L"ImpUpWalk");
			break;
		case eDirection::Down:
			mAnimator->PlayAnimation(L"ImpDownWalk");
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonMonsterScript::translate(HyeonTransform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case eDirection::Left:
			pos.X -= 100.0f * HyeonTime::GetDelataTime();
			break;
		case eDirection::Right:
			pos.X += 100.0f * HyeonTime::GetDelataTime();
			break;
		case eDirection::Up:
			pos.Y -= 100.0f * HyeonTime::GetDelataTime();
			break;
		case eDirection::Down:
			pos.Y += 100.0f * HyeonTime::GetDelataTime();
			break;
		default:
			assert(false);
			break;
		}

		tr->SetPosition(pos);
	}
}