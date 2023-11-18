#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
	using namespace HyeonMath;

	class HyeonTransform : public HyeonComponent
	{
	public:
		HyeonTransform();
		~HyeonTransform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition.X = pos.X; mPosition.Y = pos.Y; }
		Vector2 GetPos() { return mPosition; }
	private:
		Vector2 mPosition;
	};
}