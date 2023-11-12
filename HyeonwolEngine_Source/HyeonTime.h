#pragma once

#include "CommonInclude.h"

namespace Hyeon
{
	class HyeonTime
	{
	public:
		static void Initiallize();
		static void Update();
		static void Render(HDC hdc);
		static float GetDelataTime() { return DeltaTime; }

	private:
		static LARGE_INTEGER CPUFreq;
		static LARGE_INTEGER PrevFreq;
		static LARGE_INTEGER CurrentFreq;

		static float DeltaTime;
	};
}