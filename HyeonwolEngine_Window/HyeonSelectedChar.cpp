#include "HyeonSelectedChar.h"
#include "HyeonForestBattleScene.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	//Vector2 HyeonSelectedChar::mChosenCharPos = Vector2::Zero;

	HyeonSelectedChar::HyeonSelectedChar()
	{
	}
	HyeonSelectedChar::~HyeonSelectedChar()
	{
	}
	void HyeonSelectedChar::Initialize()
	{
		HyeonBattlePlayerScript::Initialize();
	}
	void HyeonSelectedChar::Update()
	{
		HyeonBattlePlayerScript::Update();

		switch (HyeonBattlePlayerScript::mChosenChar)
		{
		case eCharacter::Chrono:
			mChosenCharPos = HyeonForestBattleScene::GetChronoPos();
			break;
		case eCharacter::Ayla:
			mChosenCharPos = HyeonForestBattleScene::GetAylaPos();
			break;
		case eCharacter::Robo:
			mChosenCharPos = HyeonForestBattleScene::GetRoboPos();
			break;
		default:
			assert(false);
			break;
		}
	}
	void HyeonSelectedChar::LateUpdate()
	{
		HyeonBattlePlayerScript::LateUpdate();
	}
	void HyeonSelectedChar::Render(HDC hdc)
	{
		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		Rectangle(hdc, mChosenCharPos.X,
			mChosenCharPos.Y,
			mChosenCharPos.X + 125,
			mChosenCharPos.Y + 150);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}
}