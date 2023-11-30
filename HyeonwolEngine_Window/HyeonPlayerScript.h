#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScript.h"

namespace Hyeon
{
	class HyeonPlayerScript : public HyeonScript
	{
	public:
		enum class eState
		{
			Relax, 
			Walk, 
			DrawWeapon, 
			Attack, 
		};

		HyeonPlayerScript();
		~HyeonPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void relax();
		void move();
		void drawWeapon();
		void attack();
		
	private:
		eState mState;
		class HyeonAnimator* mAnimator;
	};
}
