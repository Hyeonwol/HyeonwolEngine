#pragma once
#include "HyeonScript.h"

namespace Hyeon
{
    class HyeonBattleGreenImpScript : public HyeonScript
    {
	public:
		enum class eState
		{
			Idle, 
			Attacked, 
			MoveToPlayer,  
			MoveToStartPoint,
		};

		HyeonBattleGreenImpScript();
		~HyeonBattleGreenImpScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(HyeonCollider* other) override;
		void OnCollisionStay(HyeonCollider* other) override;
		void OnCollisionExit(HyeonCollider* other) override;

	private:
		void setAttackTarget();
		void afterAttacked();
		void moveToPlayer();
		void moveToStartPoint();

	private:
		eState mState;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		int mTarget;
    };
}
