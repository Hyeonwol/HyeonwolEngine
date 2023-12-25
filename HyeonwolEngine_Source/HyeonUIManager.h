#pragma once
#include "CommonInclude.h"
#include "HyeonUIBase.h"

namespace Hyeon
{
	using namespace enums;
	class HyeonUIManager
	{
	public:
		static void Initialize();	//UI ����
		static void OnLoad(eUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(HyeonUIBase* addUI);	//�ε忡 ������ �Ŀ� ����
		static void OnFail();	//�ε忡 ����
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
