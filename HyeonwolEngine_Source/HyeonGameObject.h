#pragma once

#include "CommonInclude.h"

namespace Hyeon
{
	class HyeonGameObject
	{
	public:
		HyeonGameObject();
		~HyeonGameObject();

		void Update();
		void MonsterMoving(HWND hwnd);
		void LateUpdate();
		void Render(HDC hdc);
		void MonsterRender(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
	private:
		float mX = 0.0f;
		float mY = 0.0f;
	};
}