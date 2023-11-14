#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScene.h"

namespace Hyeon
{
	class HyeonPlayScene : public HyeonScene
	{
	public:
		HyeonPlayScene();
		~HyeonPlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:


	};

}