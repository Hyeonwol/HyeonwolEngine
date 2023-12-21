#include "HyeonInput.h"
#include "HyeonApplication.h"

extern Hyeon::HyeonApplication Application;

namespace Hyeon 
{
	vector<HyeonInput::Key> HyeonInput::Keys = {};
	HyeonMath::Vector2 HyeonInput::mMousePosition = HyeonMath::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, 
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON, 
	};

	void HyeonInput::Initiallize()
	{
		createKeys();
	}

	void HyeonInput::Update()
	{
		updateKeys();
	}

	void HyeonInput::createKeys()
	{
		for (int i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key;
			key.bPressed = false;
			key.KeyState = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void HyeonInput::updateKeys()
	{
		for_each (Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void HyeonInput::updateKey(HyeonInput::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.KeyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();
		}
		else
			clearKeys();
	}

	bool HyeonInput::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void HyeonInput::updateKeyDown(HyeonInput::Key& key)
	{
		if (key.bPressed == true)
			key.KeyState = eKeyState::Pressed;
		else
			key.KeyState = eKeyState::Down;
		
		key.bPressed = true;
	}
	void HyeonInput::updateKeyUp(HyeonInput::Key& key)
	{
		if (key.bPressed == true)
			key.KeyState = eKeyState::Up;
		else
			key.KeyState = eKeyState::None;

		key.bPressed = false;
	}
	void HyeonInput::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(Application.GetHwnd(), &mousePos);

		UINT width = Application.GetWidth();
		UINT height = Application.GetHeight();

		mMousePosition.X = -1.0f;
		mMousePosition.Y = -1.0f;

		if (mousePos.x > 0 && mousePos.x < width)
			mMousePosition.X = mousePos.x;

		if (mousePos.y > 0 && mousePos.y < height)
			mMousePosition.Y = mousePos.y;
	}
	void HyeonInput::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.KeyState == eKeyState::Down || key.KeyState == eKeyState::Pressed)
				key.KeyState = eKeyState::Up;
		
			else if (key.KeyState == eKeyState::Up)
				key.KeyState = eKeyState::None;

			key.bPressed = false;
		}
	}
}
