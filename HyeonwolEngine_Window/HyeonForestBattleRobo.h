#pragma once
#include "HyeonBattlePlayerScript.h"

namespace Hyeon
{
	class HyeonForestBattleRobo : public HyeonBattlePlayerScript
	{
	public:
		HyeonForestBattleRobo();
		~HyeonForestBattleRobo();

		enum class eUsedSkills
		{
			Attack,
			Skill1
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
		void moveToMonster();
		void moveToStartPoint();
		Vector2 calculatingVector();

	private:
		eUsedSkills mUsedSkills;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		Vector2 playerToMonster;
		Vector2 startPosition;
		float AnimationTimer;
	};
	extern HyeonBattlePlayerScript::eState mRoboState;
}