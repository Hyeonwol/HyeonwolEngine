#pragma once
#include "..//HyeonwolEngine_Source/HyeonScript.h"
#include "..//HyeonwolEngine_Source/HyeonTransform.h"

namespace Hyeon
{
	class HyeonMonsterScript : public HyeonScript
	{
	public:
		enum class eState
		{
			Laugh, 
			Walk, 
		};

		enum class eDirection
		{
			Left, 
			Right, 
			Up, 
			Down, 
			End
		};

		HyeonMonsterScript();
		~HyeonMonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void laugh();
		void move();

		void PlayWalkAnimationByDir(eDirection dir);
		void translate(HyeonTransform* tr);

	private:
		eState mState;
		class HyeonAnimator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}
