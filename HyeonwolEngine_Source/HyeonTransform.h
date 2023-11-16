#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
	struct Pos
	{
		int mX = 0;
		int mY = 0;
	};

	class HyeonTransform : public HyeonComponent
	{
	public:
		HyeonTransform();
		~HyeonTransform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() { return mX; }
		int GetY() { return mY; }
	private:
		int mX;
		int mY;
	};
}