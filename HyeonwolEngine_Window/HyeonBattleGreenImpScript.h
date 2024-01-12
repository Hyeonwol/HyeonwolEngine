#pragma once
#include "..//HyeonwolEngine_Source/HyeonScript.h"
#include "HyeonBattlePlayerScript.h"

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
		Vector2 calculatingVector();

	private:
		class HyeonAnimator* mAnimator;
		float mTime;
		float AnimationTimer;
		int mHp;
		int mTargetNum;
		bool isSetTarget;
		Vector2 MonsterToPlayer;
		Vector2 startPosition;
		HyeonBattlePlayerScript::eCharacter mTarget;
    };

	extern HyeonBattleGreenImpScript::eState GreenImpState;
	extern bool isMonsterTurn;
}