#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
	using namespace HyeonMath;

	class HyeonCamera : public HyeonComponent
	{
	public:
		Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		
		HyeonCamera();
		~HyeonCamera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(HyeonGameObject* target) { mTarget = target; }

	private:
		class HyeonGameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}
