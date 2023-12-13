#pragma once
#include "HyeonScript.h"

namespace Hyeon
{
    class HyeonBattleMonsterScript : public HyeonScript
    {
	public:
		enum class eState
		{
			Idle, 
			Laugh, 
			Attacked, 
			Move, 
			Attack, 
		};

		HyeonBattleMonsterScript();
		~HyeonBattleMonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idleAnimation();
		void laughingAnimation();
		void attackedAnimation();
		void moveAnimation();
		void attackAnimation();

	private:
		eState mState;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
    };
}
