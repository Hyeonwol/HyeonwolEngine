#include "HyeonForestImpsScript.h"

namespace Hyeon
{
	HyeonForestImpsScript::HyeonForestImpsScript()
		:mChosenMonster(HyeonForestImpsScript::eChosenMonster::Imp1), 
		 mChosenMonsterNum(-1)
	{
	}
	HyeonForestImpsScript::~HyeonForestImpsScript()
	{
	}
	void HyeonForestImpsScript::Initialize()
	{
	}
	void HyeonForestImpsScript::Update()
	{
		mChosenMonsterNum = rand() % 3;
		mChosenMonster = (eChosenMonster)mChosenMonsterNum;
	}
	void HyeonForestImpsScript::LateUpdate()
	{
	}
	void HyeonForestImpsScript::Render(HDC hdc)
	{
	}
}