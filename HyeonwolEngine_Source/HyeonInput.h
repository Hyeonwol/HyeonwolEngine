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

		static bool GetKeyDown(eKeyCode Code)	//��� ���� ����
		{
			return	mKeys[(UINT)Code].KeyState == eKeyState::Down;
		}
		static bool GetKeyUp(eKeyCode Code)	//���� �ִ� ����
		{
			return	mKeys[(UINT)Code].KeyState == eKeyState::Up;
		}
		static bool GetKeyPressed(eKeyCode Code)	//������ �ִ� ����
		{
			return	mKeys[(UINT)Code].KeyState == eKeyState::Pressed;
		}
	private:
		static vector<Key> mKeys;
	};
}