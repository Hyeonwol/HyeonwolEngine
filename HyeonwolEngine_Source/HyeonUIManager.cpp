#include "HyeonUIManager.h"
namespace Hyeon
{
	unordered_map<eUIType, HyeonUIBase*> HyeonUIManager::mUIs = {};
	stack<HyeonUIBase*> HyeonUIManager::mUIBases = {};
	queue<eUIType> HyeonUIManager::mRequestUIQueue = {};
	HyeonUIBase* HyeonUIManager::mActiveUI = nullptr;

	void HyeonUIManager::Initialize()
	{
	}
	void HyeonUIManager::OnLoad(eUIType type)
	{
		unordered_map<eUIType, HyeonUIBase*>::iterator iter =
			mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}
	void HyeonUIManager::Update()
	{
		stack<HyeonUIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			HyeonUIBase* UIBase = uiBases.top();

			if (UIBase)
			{
				UIBase->Update();
				uiBases.pop();
			}
		}

		if (mRequestUIQueue.size() > 0)
		{
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			OnLoad(requestUI);
		}
	}
	void HyeonUIManager::LateUpdate()
	{
		stack<HyeonUIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			HyeonUIBase* UIBase = uiBases.top();

			if (UIBase)
			{
				UIBase->LateUpdate();
				uiBases.pop();
			}
		}
	}
	void HyeonUIManager::Render(HDC hdc)
	{
		if (mUIBases.size() <= 0)
			return;

		//stack<HyeonUIBase*> uiBases = mUIBases;
		vector<HyeonUIBase*> buff;
		HyeonUIBase* uibase = nullptr;

		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			buff.push_back(uibase);
		}

		reverse(buff.begin(), buff.end());

		for (HyeonUIBase* ui : buff)
		{
			ui->Render(hdc);
			mUIBases.push(ui);
		}
	}
	void HyeonUIManager::OnComplete(HyeonUIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		if (addUI->IsFullScreen())	//UI가 전체화면이면 뒤에 있는 모든 UI를 비활성화
		{
			stack<HyeonUIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				HyeonUIBase* UIBase = uiBases.top();

				if (UIBase)
				{
					UIBase->InActive();
					uiBases.pop();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}
	void HyeonUIManager::OnFail()
	{
		mActiveUI = nullptr;
	}
	void HyeonUIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void HyeonUIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}
	void HyeonUIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		stack<HyeonUIBase*> tempStack;

		HyeonUIBase* uiBase = nullptr;
		while (mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();

			if (uiBase->GetType() != type)
			{
				tempStack.push(uiBase);
				continue;
			}

			if (uiBase->IsFullScreen())
			{
				stack<HyeonUIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					HyeonUIBase* UIBase = uiBases.top();
					uiBases.pop();

					if (UIBase)
					{
						UIBase->Active();
						break;
					}
				}
			}

			uiBase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}
	}
}