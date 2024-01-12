#pragma once
#include "HyeonScript.h"

namespace Hyeon
{
	class HyeonForestImpsScript : public HyeonScript
	{
	public:
		enum class eChosenMonster
		{
			Imp1, 
			Imp2, 
			Imp3
		};

		HyeonForestImpsScript();
		~HyeonForestImpsScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	protected:
		eChosenMonster mChosenMonster;

	private:
		int mChosenMonsterNum;
	};
}
