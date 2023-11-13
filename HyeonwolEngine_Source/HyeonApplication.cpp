#include "HyeonApplication.h"
#include "CommonInclude.h"
#include "HyeonInput.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonApplication::HyeonApplication()
		: mHwnd(nullptr),
		  mHdc(nullptr),
		  mWidth(0),
		  mHeight(0),
		  mBackHdc(NULL),
	      mBackBitmap(NULL)
	{

	}

	HyeonApplication::~HyeonApplication()
	{

	}

	void HyeonApplication::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);


		HyeonInput::Initiallize();
		HyeonTime::Initiallize();
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
		mBullet.BulletMoving(mHwnd);

		HyeonInput::Update();
		HyeonTime::Update();
	}
	void HyeonApplication::LateUpdate()
	{

	}
	void HyeonApplication::Render()
	{
		//���ʿ� �ִ� DC�� �׸��� �׸�
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		mPlayer.Render(mBackHdc);
		mMonster.MonsterRender(mBackHdc);
		mBullet.BulletRender(mBackHdc);
		HyeonTime::Render(mBackHdc);

		//���� DC�� �׸� �׸��� ���� DC�� ���(����)
		//�̷��� ������ ������ �� �����̴� �ܻ��� ���ֱ� ������

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}