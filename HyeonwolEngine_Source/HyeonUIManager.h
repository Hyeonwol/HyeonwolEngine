#pragma once
#include "CommonInclude.h"
#include "HyeonUIBase.h"

namespace Hyeon
{
	using namespace enums;
	class HyeonUIManager
	{
	public:
		static void Initialize();	//UI 생성
		static void OnLoad(eUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(HyeonUIBase* addUI);	//로드에 성공한 후에 실행
		static void OnFail();	//로드에 실패
		static void Release();

		static void Push(eUIType type);
		static void Pop(eUIType type);

	private:
		static unordered_map<eUIType, HyeonUIBase*> mUIs;
		static stack<HyeonUIBase*> mUIBases;
		static queue<eUIType> mRequestUIQueue;
		static HyeonUIBase* mActiveUI;
	};
}
