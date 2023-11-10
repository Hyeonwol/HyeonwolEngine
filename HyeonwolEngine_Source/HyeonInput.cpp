#include "HyeonInput.h"

namespace Hyeon 
{
	vector<HyeonInput::Key> HyeonInput::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	void HyeonInput::Initiallize()
	{
		for (int i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key;
			key.bPressed = false;
			key.KeyState = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void HyeonInput::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//키를 누름
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed ==true)
				{
					//키를 누르고 있었음
					mKeys[i].KeyState = eKeyState::Pressed;
				}
				//키를 떼고 있다 지금 눌렀음
				else
				{
					mKeys[i].KeyState = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			//키를 누르지 않음
			else
			{
				if (mKeys[i].bPressed == true)
				{
					//키를 누르고 있다가 뗐음
					mKeys[i].KeyState = eKeyState::Up;
				}
				else
				{
					//키를 처음부터 누르지 않았음
					mKeys[i].KeyState = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}
