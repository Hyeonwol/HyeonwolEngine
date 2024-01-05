#include "HyeonBattlePlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTime.h"
#include "HyeonEntity.h"
#include "HyeonForestBattleScene.h"
#include "HyeonUIManager.h"

namespace Hyeon
{
	HyeonBattlePlayerScript::HyeonBattlePlayerScript()
		: mChosenChar(HyeonBattlePlayerScript::eCharacter::Chrono)
		, mChosenCharNum(-1)
	{
	}
	HyeonBattlePlayerScript::~HyeonBattlePlayerScript()
	{
	}
	void HyeonBattlePlayerScript::Initialize()
	{
	}
	void HyeonBattlePlayerScript::Update()
	{
		/*if (GetKeyState(VK_F1) & 0x8000)
			mChosenChar = eCharacter::Chrono;
		else if (GetKeyState(VK_F2) & 0x8000)
			mChosenChar = eCharacter::Ayla;
		else if (GetKeyState(VK_F3) & 0x8000)
			mChosenChar = eCharacter::Robo;*/
		mChosenCharNum = static_cast<int>(mChosenChar);

		if (HyeonInput::GetKeyDown(eKeyCode::Right))
		{
			mChosenCharNum++;
			mChosenChar = (eCharacter)mChosenCharNum;
		}
	}
	void HyeonBattlePlayerScript::LateUpdate()
	{
	}
	void HyeonBattlePlayerScript::Render(HDC hdc)
	{
	}
}