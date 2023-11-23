#pragma once
#include "..\\HyeonwolEngine_Source\HyeonResources.h"
#include "..\\HyeonwolEngine_Source\HyeonTexture.h"

namespace Hyeon
{
	void LoadResources()
	{
		HyeonResources::Load<graphics::HyeonTexture>(L"BG",
			L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Guardia Forest.png");

		HyeonResources::Load<graphics::HyeonTexture>(L"Portal",
			L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\Chrono Trigger - Gate.png");

		HyeonResources::Load<graphics::HyeonTexture>(L"Title",
			L"D:\\GameProgramming\\HyeonwolEngine\\Resources\\Chrono Trigger\\Title.png");

	}
}