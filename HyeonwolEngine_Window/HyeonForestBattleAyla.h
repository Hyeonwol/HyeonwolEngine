#pragma once
#include "HyeonBattlePlayerScript.h"

namespace Hyeon
{
    class HyeonForestBattleAyla : public HyeonBattlePlayerScript
    {
	public:
		HyeonForestBattleAyla();
		~HyeonForestBattleAyla();

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
		void afterDrawWeapon();
		void afterAttack();
		void moving();
		Vector2 calculatingVector();

	private:
		eState mAylaState;
		eUsedSkills mUsedSkills;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		Vector2 playerToMonster;
	};
}
