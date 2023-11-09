#include "HyeonGameObject.h"
#include "CommonInclude.h"
#include <random>


namespace Hyeon
{
	HyeonGameObject::HyeonGameObject()
	{
	}

	HyeonGameObject::~HyeonGameObject()
	{
	}

	void HyeonGameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
		{ 
			mX -= 0.01f; 
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}

		
	}

	void HyeonGameObject::MonsterMoving(HWND hwnd)
	{		
		random_device Random;
		uniform_real_distribution<double> newX(-10.0f, 10.0f);
		uniform_real_distribution<double> newY(-10.0f, 10.0f);

		if (mX + newX(Random) >= 0 && mX + newX(Random) <= 1600
			&& mY + newY(Random) > 0 && mY + newY(Random) <= 900)
		{
			mX += newX(Random);
			mY += newY(Random);
		}
	}

	void HyeonGameObject::LateUpdate()
	{

	}

	void HyeonGameObject::Render(HDC hdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush);

		HPEN redpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(hdc, redpen);

		SelectObject(hdc, oldpen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldbrush);
		DeleteObject(bluebrush);
		DeleteObject(redpen);
	}

	void HyeonGameObject::MonsterRender(HDC hdc)
	{
		HBRUSH greenbrush = CreateSolidBrush(RGB(0, 255, 0));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, greenbrush);

		Rectangle(hdc, 800 + mX, 450 + mY, 900 + mX, 550 + mY);

		SelectObject(hdc, oldbrush);
		DeleteObject(greenbrush);

	}



}
