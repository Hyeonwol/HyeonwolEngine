#include "HyeonGameObject.h"
#include "CommonInclude.h"
#include "HyeonInput.h"


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
		if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{ 
			mX -= 0.01f;
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mY += 0.01f;
		}

		
	}

	void HyeonGameObject::MonsterMoving(HWND hwnd)
	{	
		if (900 + mX + mSpeed < 1600 && flag == 0)
		{
			mX += mSpeed;
			if (900 + mX + mSpeed > 1600)
			{
				flag = 1;
			}
		}
		else if (mX + mSpeed >= 0 && flag == 1)
		{
			mX -= mSpeed;
			if (mX + mSpeed < 0)
			{
				flag = 0;
			}
		}
	}

	void HyeonGameObject::LateUpdate()
	{

	}

	void HyeonGameObject::Render(HDC hdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldbrush);
		DeleteObject(bluebrush);
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
