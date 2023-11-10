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
			//Ű�� ����
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed ==true)
				{
					//Ű�� ������ �־���
					mKeys[i].KeyState = eKeyState::Pressed;
				}
				//Ű�� ���� �ִ� ���� ������
				else
				{
					mKeys[i].KeyState = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			//Ű�� ������ ����
			else
			{
				if (mKeys[i].bPressed == true)
				{
					//Ű�� ������ �ִٰ� ����
					mKeys[i].KeyState = eKeyState::Up;
				}
				else
				{
					//Ű�� ó������ ������ �ʾ���
					mKeys[i].KeyState = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}
