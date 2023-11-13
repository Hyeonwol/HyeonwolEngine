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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		HyeonGameObject mPlayer;
		HyeonGameObject mMonster;
		HyeonGameObject mBullet;
	};
}