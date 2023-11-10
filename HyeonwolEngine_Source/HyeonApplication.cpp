#include "HyeonApplication.h"
#include "CommonInclude.h"
#include "HyeonInput.h"

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

		HyeonInput::Initiallize();
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

		HyeonInput::Update();
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