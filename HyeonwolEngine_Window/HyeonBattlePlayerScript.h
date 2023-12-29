#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScript.h"

namespace Hyeon
{
	class HyeonBattlePlayerScript : public HyeonScript
	{
	public:
		enum class eState
		{
			DrawWeapon, 
			Move, 
			Attack, 
			Dead
		};

		enum class eCharacter
		{
			Chrono, 
			Ayla, 
			Robo, 
		};

		HyeonBattlePlayerScript();
		~HyeonBattlePlayerScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(HyeonCollider* other) override;
		virtual void OnCollisionStay(HyeonCollider* other) override;
		virtual void OnCollisionExit(HyeonCollider* other) override;
	
	protected:
		//virtual void stateSwitching();
		virtual void afterDrawWeapon();
		virtual void moving();
		virtual void afterAttack();
		virtual Vector2 calculatingVector();

	private:
		eState mChronoState;
		eState mAylaState;
		eState mRoboState;
		eCharacter mChosenChar;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		bool isAylaUseSkill1;
		bool isRoboUseSkill;
		Vector2 playerToMonster;
	};
}
