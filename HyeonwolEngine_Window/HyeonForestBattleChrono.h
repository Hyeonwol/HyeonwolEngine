#pragma once
#include "HyeonBattlePlayerScript.h"

namespace Hyeon
{
    class HyeonForestBattleChrono : public HyeonBattlePlayerScript
    {
	public:
        HyeonForestBattleChrono();
        ~HyeonForestBattleChrono();

		enum class eUsedSkills
		{
			Attack, 
			Skill1, 
			Skill2
		};

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(HyeonCollider* other) override;
		void OnCollisionStay(HyeonCollider* other) override;
		void OnCollisionExit(HyeonCollider* other) override;

	private:
		void afterDrawWeapon() override;
		void afterAttack() override;
		void moving();
		Vector2 calculatingVector();

	private:
		eState mChronoState;
		eUsedSkills mUsedSkills;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		Vector2 playerToMonster;

    };
}