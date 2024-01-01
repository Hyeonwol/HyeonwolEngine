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
		:mChosenChar(HyeonBattlePlayerScript::eCharacter::Chrono), 
		 mAnimator(nullptr), 
		 mTime(0.0f), 
		 mHp(0), 
		 isAylaUseSkill1(false), 
		 isRoboUseSkill(false), 
		 mStamina(0)
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
	}
	void HyeonBattlePlayerScript::LateUpdate()
	{
		if (GetKeyState(VK_F1) & 0x8000)
			mChosenChar = eCharacter::Chrono;
		else if (GetKeyState(VK_F2) & 0x8000)
			mChosenChar = eCharacter::Ayla;
		else if (GetKeyState(VK_F3) & 0x8000)
			mChosenChar = eCharacter::Robo;
	}
	void HyeonBattlePlayerScript::Render(HDC hdc)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionEnter(HyeonCollider* other)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionStay(HyeonCollider* other)
	{
	}

	void HyeonBattlePlayerScript::OnCollisionExit(HyeonCollider* other)
	{
	}
}