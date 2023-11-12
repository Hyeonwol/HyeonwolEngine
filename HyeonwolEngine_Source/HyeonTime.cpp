#include "HyeonTime.h"

namespace Hyeon
{
	LARGE_INTEGER HyeonTime::CPUFreq = {};
	LARGE_INTEGER HyeonTime::PrevFreq = {};
	LARGE_INTEGER HyeonTime::CurrentFreq = {};
	float HyeonTime::DeltaTime = 0.0f;

	void HyeonTime::Initiallize()
	{
		//CPU 클럭
		QueryPerformanceFrequency(&CPUFreq);
		
		//컴퓨터가 실행되고 이 프로그램을 실행시킬 때까지 CPU가 진동한 횟수
		QueryPerformanceCounter(&PrevFreq);
	}

	void HyeonTime::Update()
	{
		//현 시점까지 CPU가 진동한 총 횟수를 저장
		QueryPerformanceCounter(&CurrentFreq);

		float DeltaFreqDifference = static_cast<float>(CurrentFreq.QuadPart - PrevFreq.QuadPart);

		DeltaTime = DeltaFreqDifference / static_cast<float>(CPUFreq.QuadPart);

		PrevFreq.QuadPart = CurrentFreq.QuadPart;
	}

	void HyeonTime::Render(HDC hdc)
	{
		float time = 0.0f;

		time += DeltaTime;

		float FPS = 1.0f / DeltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)FPS);

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
