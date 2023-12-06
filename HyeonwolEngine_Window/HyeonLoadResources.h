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
			L"..\\Resources\\Chrono Trigger\\Title.bmp");

		HyeonResources::Load<graphics::HyeonTexture>(L"Chrono",
			L"..\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Crono.bmp");
		
		HyeonResources::Load<graphics::HyeonTexture>(L"ChronoSheet2",
			L"..\\Resources\\Chrono Trigger\\ChronoSheet2.bmp");
		
		HyeonResources::Load<graphics::HyeonTexture>(L"Ayla",
			L"..\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Ayla.bmp");


		HyeonResources::Load<graphics::HyeonTexture>(L"Imp",
			L"..\\Resources\\Chrono Trigger\\SNES - Chrono Trigger - Blue Imp Green Imp Mud Imp & Stone Imp.bmp");

	}
}