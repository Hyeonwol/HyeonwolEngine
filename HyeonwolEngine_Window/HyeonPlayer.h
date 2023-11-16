#pragma once
#include "..\\HyeonwolEngine_Source\HyeonGameObject.h"

namespace Hyeon
{
	class HyeonPlayer : public HyeonGameObject
	{
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}