#pragma once
#include "CommonInclude.h"
#include "HyeonGameObject.h"


namespace Hyeon
{
	class HyeonApplication
	{
	public:
		HyeonApplication();
		~HyeonApplication();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		float mX;
		float mY;

		HyeonGameObject mPlayer;
		HyeonGameObject mMonster;
	};
}