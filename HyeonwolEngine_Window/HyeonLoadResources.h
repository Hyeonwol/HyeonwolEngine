#pragma once
#include "..\\HyeonwolEngine_Source\HyeonResources.h"
#include "..\\HyeonwolEngine_Source\HyeonTexture.h"

namespace Hyeon
{
	void LoadResources()
	{
		HyeonResources::Load<graphics::HyeonTexture>(L"BG",
			L"..\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Guardia Forest.png");

		HyeonResources::Load<graphics::HyeonTexture>(L"Portal",
			L"..\\Resources\\Chrono Trigger\\Chrono Trigger - Gate.png");

		HyeonResources::Load<graphics::HyeonTexture>(L"Title",
			L"..\\Resources\\Chrono Trigger\\Title.png");

	}
}