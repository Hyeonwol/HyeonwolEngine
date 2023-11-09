#include "HyeonApplication.h"
#include "CommonInclude.h"

namespace Hyeon
{
	HyeonApplication::HyeonApplication()
		: mHwnd(nullptr),
		  mHdc(nullptr),
		  mSpeed(0.0f),
		  mX(0.0f),
		  mY(0.0f)
	{

	}

	HyeonApplication::~HyeonApplication()
	{

	}

	void HyeonApplication::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
	}
	void HyeonApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void HyeonApplication::Update()
	{
		mPlayer.Update();
		mMonster.MonsterMoving(mHwnd);
	}
	void HyeonApplication::LateUpdate()
	{

	}
	void HyeonApplication::Render()
	{
		mPlayer.Render(mHdc);
		mMonster.MonsterRender(mHdc);
		
	}
}