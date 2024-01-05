#include "HyeonBattleGreenImpScript.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"
#include "HyeonGameObject.h"
#include "HyeonCamera.h"
#include "HyeonRenderer.h"
#include "HyeonForestBattleScene.h"


extern Hyeon::HyeonCamera* Hyeon::renderer::mainCamera;

namespace Hyeon
{
	HyeonBattleGreenImpScript::HyeonBattleGreenImpScript()
		:mState(HyeonBattleGreenImpScript::eState::Idle),
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0), 
		 mTarget(-1)
	{
	}
	HyeonBattleGreenImpScript::~HyeonBattleGreenImpScript()
	{
	}
	void HyeonBattleGreenImpScript::Initialize()
	{
	}
	void HyeonBattleGreenImpScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case eState::Idle:
			break;
		case eState::Attacked:
			break;
		case eState::MoveToPlayer:
			break;
		case eState::MoveToStartPoint:
			break;
		default:
			break;
		}
	}
	void HyeonBattleGreenImpScript::LateUpdate()
	{
	}
	void HyeonBattleGreenImpScript::Render(HDC hdc)
	{
	}

	void HyeonBattleGreenImpScript::OnCollisionEnter(HyeonCollider* other)
	{
	}

	void HyeonBattleGreenImpScript::OnCollisionStay(HyeonCollider* other)
	{
	}

	void HyeonBattleGreenImpScript::OnCollisionExit(HyeonCollider* other)
	{
	}

	void HyeonBattleGreenImpScript::setAttackTarget()
	{
		mTarget = rand() % 3;
	}

	void HyeonBattleGreenImpScript::afterAttacked()
	{
		mAnimator->PlayAnimation(L"GreenImpAttacked");
	}

	void HyeonBattleGreenImpScript::moveToPlayer()
	{
	}

	void HyeonBattleGreenImpScript::moveToStartPoint()
	{
	}
}