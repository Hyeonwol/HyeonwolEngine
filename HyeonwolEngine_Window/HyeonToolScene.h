#pragma once
#include "..//HyeonwolEngine_Source/HyeonScene.h"
#include "HyeonTile.h"

namespace Hyeon
{
	class HyeonToolScene : public HyeonScene
	{
	public:
		HyeonToolScene();
		~HyeonToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		void Save();
		void Load();

	private:
		vector<HyeonTile*> mTiles;
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);