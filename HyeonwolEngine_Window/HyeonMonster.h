#pragma once
#include "..//HyeonwolEngine_Source/HyeonGameObject.h"

namespace Hyeon
{
	class HyeonMonster : public HyeonGameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}
