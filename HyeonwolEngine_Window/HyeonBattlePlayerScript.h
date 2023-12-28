#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScript.h"

namespace Hyeon
{
	class HyeonBattlePlayerScript : public HyeonScript
	{
	public:
		/*struct CharacterState
		{
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
		};*/
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

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(HyeonCollider* other) override;
		void OnCollisionStay(HyeonCollider* other) override;
		void OnCollisionExit(HyeonCollider* other) override;
	
	private:
		void stateSwitching();
		void afterDrawWeapon();
		void moving(eCharacter chosenChar);
		void afterAttack();
		Vector2 calculatingVector();

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
