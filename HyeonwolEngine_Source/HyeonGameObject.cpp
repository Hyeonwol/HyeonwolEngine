#include "HyeonGameObject.h"
#include "HyeonInput.h"
#include "HyeonTime.h"

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
		const float speed = 100.0f;

		if (HyeonInput::GetKeyPressed(eKeyCode::A))
		{ 
			mX -= speed * HyeonTime::GetDelataTime();
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::D))
		{
			mX += speed * HyeonTime::GetDelataTime();
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::W))
		{
			mY -= speed * HyeonTime::GetDelataTime();
		}

		if (HyeonInput::GetKeyPressed(eKeyCode::S))
		{
			mY += speed * HyeonTime::GetDelataTime();
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
