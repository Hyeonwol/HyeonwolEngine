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

		enum class eDir
		{
			Left, 
			Right, 
			Up, 
			Down
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
		void afterDrawWeapon();
		void afterAttack();
		void walking();
		void relaxing();
	
	private:
		eState mState;
		eDir mDir;
		float mTime;
		class HyeonAnimator* mAnimator;
	};
}
