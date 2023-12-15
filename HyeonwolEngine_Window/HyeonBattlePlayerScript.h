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
			Attack, 
			Dead
		};

		enum class Character
		{
			Chrono, 
			Ayla, 
			Robo, 
		};

		HyeonBattlePlayerScript();
		~HyeonBattlePlayerScript();

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

	private:
		eState mState;
		Character mChosenChar;
		class HyeonAnimator* mAnimator;
		float mTime;
		int mHp;
		int mStamina;
		bool isAylaUseSkill1;
		bool isRoboUseSkill;
		Vector2 playerToMonster;
	};
}
