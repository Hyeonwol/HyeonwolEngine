#include "HyeonApplication.h"
#include "CommonInclude.h"
#include "HyeonInput.h"
#include "HyeonTime.h"
#include "HyeonSceneManager.h"

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
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		HyeonSceneManager::Initialize();
	}
	void HyeonApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void HyeonApplication::Update()
	{
		HyeonInput::Update();
		HyeonTime::Update();

		HyeonSceneManager::Update();
	}
	void HyeonApplication::LateUpdate()
	{
		HyeonSceneManager::LateUpdate();
	}
	void HyeonApplication::Render()
	{
		//���ʿ� �ִ� DC�� �׸��� �׸�
		clearRenderTarget();

		HyeonTime::Render(mBackHdc);
		HyeonSceneManager::Render(mBackHdc);
		copyRenderTarget(mBackHdc, mHdc);
	}

	void HyeonApplication::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void HyeonApplication::copyRenderTarget(HDC source, HDC dest)
	{
		//���� DC�� �׸� �׸��� ���� DC�� ���(����)
		//�̷��� ������ ������ �� �����̴� �ܻ��� ���ֱ� ������
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void HyeonApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;

		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void HyeonApplication::createBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void HyeonApplication::initializeEtc()
	{
		HyeonInput::Initiallize();
		HyeonTime::Initiallize();
	}
}