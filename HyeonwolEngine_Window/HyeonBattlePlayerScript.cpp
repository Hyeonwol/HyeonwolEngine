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
		mChosenCharNum = static_cast<int>(mChosenChar);

		if (HyeonInput::GetKeyDown(eKeyCode::Right))
		{
			mChosenCharNum++;
			if (mChosenCharNum == 3)
			{
				mChosenCharNum = 0;
			}
			mChosenChar = (eCharacter)mChosenCharNum;
		}

		if (HyeonInput::GetKeyDown(eKeyCode::Left))
		{
			mChosenCharNum--;
			if (mChosenCharNum == -1)
			{
				mChosenCharNum = 2;
			}
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