#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScene.h"

namespace Hyeon
{
	class HyeonTitleScene : public HyeonScene
	{
	public:
		HyeonTitleScene();
		~HyeonTitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
