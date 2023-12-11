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

		enum class eDir
		{
			Left, 
			Right, 
			Up, 
			Down
		};

		HyeonBattlePlayerScript();
		~HyeonBattlePlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void drawWeapon();
		void afterDrawWeapon();
		void afterAttack();

	private:
		eState mState;
		eDir mDir;
		class HyeonAnimator* mAnimator;
		float mTime;
	};
}
