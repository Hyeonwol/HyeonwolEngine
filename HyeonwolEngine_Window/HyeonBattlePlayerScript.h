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
		};

		enum class Character
		{
			Chrono, 
			Ayla, 
			Marle, 
		};

		HyeonBattlePlayerScript();
		~HyeonBattlePlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

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
		Vector2 playerToMonster;
	};
}
