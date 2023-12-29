#include "HyeonForestBattleChrono.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTime.h"
#include "HyeonAnimator.h"

namespace Hyeon
{
	HyeonForestBattleChrono::HyeonForestBattleChrono()
		:mChronoState(HyeonBattlePlayerScript::eState::DrawWeapon),\
		 mUsedSkills(eUsedSkills::Attack), 
		 mAnimator(nullptr),
		 mTime(0.0f),
		 mHp(0),
		 mStamina(0)
	{
	}
	HyeonForestBattleChrono::~HyeonForestBattleChrono()
	{
	}
	void HyeonForestBattleChrono::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
	}
	void HyeonForestBattleChrono::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<HyeonAnimator>();

		switch (mChronoState)
		{
		case eState::DrawWeapon:
			afterDrawWeapon();
			break;
		case eState::Move:
			moving();
			break;
		case eState::Attack:
			break;
		case eState::Dead:
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonForestBattleChrono::LateUpdate()
	{
		HyeonBattlePlayerScript::LateUpdate();
	}
	void HyeonForestBattleChrono::Render(HDC hdc)
	{
		HyeonBattlePlayerScript::Render(hdc);
	}
	void HyeonForestBattleChrono::OnCollisionEnter(HyeonCollider* other)
	{
		switch (mUsedSkills)
		{
		case eUsedSkills::Attack:
			mChronoState = eState::Attack;
			mAnimator->PlayAnimation(L"ChronoLeftAttack", false);
			break;
		case eUsedSkills::Skill1:
			break;
		case eUsedSkills::Skill2:
			break;
		default:
			break;
		}
	}
	void HyeonForestBattleChrono::OnCollisionStay(HyeonCollider* other)
	{
	}
	void HyeonForestBattleChrono::OnCollisionExit(HyeonCollider* other)
	{
	}
	void HyeonForestBattleChrono::afterDrawWeapon()
	{
		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			mUsedSkills = eUsedSkills::Attack;
			playerToMonster = calculatingVector();
			mChronoState = HyeonBattlePlayerScript::eState::Move;
			moving();
		}
	}
	void HyeonForestBattleChrono::afterAttack()
	{
	}
	void HyeonForestBattleChrono::moving()
	{
		//벡터로 이동해서 공격 구현 중
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		//if (chosenChar)
		pos.X += playerToMonster.X * HyeonTime::GetDelataTime() * 400.0f;
		pos.Y += playerToMonster.Y * HyeonTime::GetDelataTime() * 400.0f;

		tr->SetPosition(pos);
	}
	Vector2 HyeonForestBattleChrono::calculatingVector()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 MonsterPos = HyeonForestBattleScene::GetMonsterPos();

		return (MonsterPos - pos).normalize();
	}
}