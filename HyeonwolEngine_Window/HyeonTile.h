#pragma once
#include "..//HyeonwolEngine_Source/HyeonGameObject.h"

namespace Hyeon
{
	class HyeonTile : public HyeonGameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(int x, int y);
	private:

	};
}
