#pragma once
#include "CommonInclude.h"

namespace Hyeon
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up, 
		LButton, MButton, RButton, 
		End,
	};

	class HyeonInput
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState KeyState;
			bool bPressed;
		};

		static void Initiallize();
		static void Update();

		static bool GetKeyDown(eKeyCode Code)	//방금 누른 상태
		{
			return	Keys[(UINT)Code].KeyState == eKeyState::Down;
		}
		static bool GetKeyUp(eKeyCode Code)	//떼고 있는 상태
		{
			return	Keys[(UINT)Code].KeyState == eKeyState::Up;
		}
		static bool GetKeyPressed(eKeyCode Code)	//누르고 있는 상태
		{
			return	Keys[(UINT)Code].KeyState == eKeyState::Pressed;
		}
		static HyeonMath::Vector2 GetMousePosition() { return mMousePosition; }
	
	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(HyeonInput::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(HyeonInput::Key& key);
		static void updateKeyUp(HyeonInput::Key& key);
		static void getMousePositionByWindow();
		static void clearKeys();
	private:
		static vector<Key> Keys;
		static HyeonMath::Vector2 mMousePosition;
	};
}