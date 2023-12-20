#pragma once
#include "HyeonBattlePlayerScript.h"

namespace Hyeon
{
	class HyeonBattleChronoScript : public HyeonBattlePlayerScript
	{
	public:
		/*enum class eState
		{
			DrawWeapon, 
			Attack, 
		};

		enum class eDir
		{
			Left, 
			Right, 
			Up, 
			Down, 
		};*/

		HyeonBattleChronoScript();
		~HyeonBattleChronoScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void drawWeapon() override;
		void afterDrawWeapon() override;
		void afterAttack() override;

	private:
		eState mState;
		Character mDir;
		class HyeonAnimator* mChronoAnimator;
		float mTime;
		int mHp;
		int mStamina;
	};
}
