#include "HyeonBattleMonsterScript.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	HyeonBattleMonsterScript::HyeonBattleMonsterScript()
		:mState(HyeonBattleMonsterScript::eState::Idle), 
		 mAnimator(nullptr), 
		 mTime(0.0f), 
		 mHp(0), 
		 mStamina(0)
		 
	{
	}
	HyeonBattleMonsterScript::~HyeonBattleMonsterScript()
	{
	}
	void HyeonBattleMonsterScript::Initialize()
	{
	}
	void HyeonBattleMonsterScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case eState::Idle:
			idleAnimation();
			break;
		case eState::Laugh:
			laughingAnimation();
			break;
		case eState::Attacked:
			attackedAnimation();
			break;
		case eState::Move:
			moveAnimation();
			break;
		case eState::Attack:
			attackAnimation();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonBattleMonsterScript::LateUpdate()
	{
	}
	void HyeonBattleMonsterScript::Render(HDC hdc)
	{
	}
	void HyeonBattleMonsterScript::idleAnimation()
	{
	}
	void HyeonBattleMonsterScript::laughingAnimation()
	{
	}
	void HyeonBattleMonsterScript::attackedAnimation()
	{
	}
	void HyeonBattleMonsterScript::moveAnimation()
	{
	}
	void HyeonBattleMonsterScript::attackAnimation()
	{
	}
}