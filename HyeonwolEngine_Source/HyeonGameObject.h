#pragma once

#include "CommonInclude.h"
#include "HyeonComponent.h"

namespace Hyeon
{
	class HyeonGameObject
	{
	public:
		enum class eState
		{
			Active, 
			Paused, 
			Dead, 
			End
		};

		HyeonGameObject();
		~HyeonGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->HyeonComponent::SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (HyeonComponent* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
				{
					break;
				}
			}

			return component;
		}

		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		void Death() { mState = eState::Dead; }

	private:
		void initializeTransform();

	private:
		eState mState;
		vector<HyeonComponent*> mComponents;
	};
}