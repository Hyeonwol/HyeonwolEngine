#include "HyeonUIManager.h"
#include "HyeonUIHUD.h"

namespace Hyeon
{
	unordered_map<eUIType, HyeonUIBase*> HyeonUIManager::mUIs = {};
	stack<HyeonUIBase*> HyeonUIManager::mUIBases = {};
	queue<eUIType> HyeonUIManager::mRequestUIQueue = {};
	HyeonUIBase* HyeonUIManager::mActiveUI = nullptr;

	void HyeonUIManager::Initialize()
	{
		// UI 객체 생성해주기
		HyeonUIHUD* hud = new HyeonUIHUD();
		mUIs.insert(make_pair(eUIType::Hpbar, hud));
	}

	void HyeonUIManager::OnLoad(eUIType type)
	{
		unordered_map<eUIType, HyeonUIBase*>::iterator iter
			= mUIs.find(type);

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
			HyeonUIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
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
			HyeonUIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void HyeonUIManager::Render(HDC hdc)
	{
		if (mUIBases.size() <= 0)
			return;

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

		// 만약에 현재 추가된 ui가 전체화면이라면
		// 전체화면인 ui 말고 나머지를 전부 비활성화
		if (addUI->IsFullScreen())
		{
			stack<HyeonUIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				HyeonUIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->InActive();
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

		HyeonUIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			if (uibase->GetType() != type)
			{
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen())
			{
				stack<HyeonUIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					HyeonUIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uibase->UIClear();
		}


		while (tempStack.size() > 0)
		{
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uibase);
		}
	}

}