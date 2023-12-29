#pragma once
#include "..\\HyeonwolEngine_Source\HyeonScene.h"

namespace Hyeon
{
	class HyeonForestScene: public HyeonScene
	{
	public:
		HyeonForestScene();
		~HyeonForestScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class HyeonPlayer* Ayla;
	};

}