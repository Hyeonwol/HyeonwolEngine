#include "HyeonMovePlayerScript.h"
#include "HyeonTransform.h"
#include "HyeonInput.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonCollider.h"
#include "HyeonTime.h"
#include "HyeonSceneManager.h"
#include "HyeonUIManager.h"

namespace Hyeon
{
	HyeonMovePlayerScript::HyeonMovePlayerScript()
		:mState(HyeonMovePlayerScript::eState::Relax),
		 mDir(HyeonMovePlayerScript::eDir::Down),
		 isRunning(false), 
		 mAnimator(nullptr)
	{
	}
	HyeonMovePlayerScript::~HyeonMovePlayerScript()
	{
	}
	void HyeonMovePlayerScript::Initialize()
	{
	}
	void HyeonMovePlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mState)
		{
		case HyeonMovePlayerScript::eState::Relax:
			relaxing();
			break;
		case HyeonMovePlayerScript::eState::Move:
			moving();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonMovePlayerScript::LateUpdate()
	{
	}
	void HyeonMovePlayerScript::Render(HDC hdc)
	{
	}
	void HyeonMovePlayerScript::OnCollisionEnter(HyeonCollider* other)
	{
		HyeonSceneManager::LoadScene(L"ForestBattleScene");
	}
	void HyeonMovePlayerScript::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonMovePlayerScript::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonMovePlayerScript::relaxing()
	{
		if (GetKeyState(VK_SHIFT) & 0x8000 && isRunning == false)
			isRunning = true;
		else if (GetKeyState(VK_SHIFT) & 0x8000 && isRunning == true)
			isRunning = false;


		if (((HyeonInput::GetKeyPressed(eKeyCode::W) ||
			HyeonInput::GetKeyPressed(eKeyCode::A) ||
			HyeonInput::GetKeyPressed(eKeyCode::S) ||
			HyeonInput::GetKeyPressed(eKeyCode::D))) 
			&& isRunning == false)
		{
			walkingAnimation();
		}
		else if (((HyeonInput::GetKeyPressed(eKeyCode::W) ||
			HyeonInput::GetKeyPressed(eKeyCode::A) ||
			HyeonInput::GetKeyPressed(eKeyCode::S) ||
			HyeonInput::GetKeyPressed(eKeyCode::D)))
			&& isRunning == true)
		{
			runnungAnimation();
		}
	}
	void HyeonMovePlayerScript::moving()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		if (isRunning == false)
		{
			if (HyeonInput::GetKeyPressed(eKeyCode::D))
			{
				pos.X += 100.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::A))
			{
				pos.X -= 100.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::W))
			{
				pos.Y -= 100.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::S))
			{
				pos.Y += 100.0f * HyeonTime::GetDelataTime();
			}
		}
		else
		{
			if (HyeonInput::GetKeyPressed(eKeyCode::D))
			{
				pos.X += 250.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::A))
			{
				pos.X -= 250.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::W))
			{
				pos.Y -= 250.0f * HyeonTime::GetDelataTime();
			}

			else if (HyeonInput::GetKeyPressed(eKeyCode::S))
			{
				pos.Y += 250.0f * HyeonTime::GetDelataTime();
			}
		}

		tr->SetPosition(pos);

		if (HyeonInput::GetKeyUp(eKeyCode::W) ||
			HyeonInput::GetKeyUp(eKeyCode::A) ||
			HyeonInput::GetKeyUp(eKeyCode::S) ||
			HyeonInput::GetKeyUp(eKeyCode::D))
		{
			mState = HyeonMovePlayerScript::eState::Relax;
			relaxingAnimation();
		}
	}
	void HyeonMovePlayerScript::walkingAnimation()
	{
		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"DownWalk");
		}
	}
	void HyeonMovePlayerScript::relaxingAnimation()
	{
		if (HyeonInput::GetKeyUp(eKeyCode::W))
		{
			mState = HyeonMovePlayerScript::eState::Relax;
			mDir = HyeonMovePlayerScript::eDir::Up;
			mAnimator->PlayAnimation(L"UpRelax", false);
		}
		else if (HyeonInput::GetKeyUp(eKeyCode::S))
		{
			mState = HyeonMovePlayerScript::eState::Relax;
			mDir = HyeonMovePlayerScript::eDir::Down;
			mAnimator->PlayAnimation(L"DownRelax", false);
		}

		else if (HyeonInput::GetKeyUp(eKeyCode::D))
		{
			mState = HyeonMovePlayerScript::eState::Relax;
			mDir = HyeonMovePlayerScript::eDir::Right;
			mAnimator->PlayAnimation(L"RightRelax", false);
		}
		else if (HyeonInput::GetKeyUp(eKeyCode::A))
		{
			mState = HyeonMovePlayerScript::eState::Relax;
			mDir = HyeonMovePlayerScript::eDir::Left;
			mAnimator->PlayAnimation(L"LeftRelax", false);
		}
	}
	void HyeonMovePlayerScript::runnungAnimation()
	{
		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"RightRun");
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"LeftRun");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"UpRun");
		}
		else if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mState = HyeonMovePlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"DownRun");
		}
	}
}