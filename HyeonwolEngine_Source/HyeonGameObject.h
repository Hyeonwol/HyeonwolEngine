#pragma once

#include "CommonInclude.h"
#include "HyeonComponent.h"
#include "HyeonCollider.h"

namespace Hyeon::object
{
	void Destroy(HyeonGameObject* gameObject);
}

namespace Hyeon
{
	class HyeonGameObject
	{
	public:
		friend void object::Destroy(HyeonGameObject* obj);

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

		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool isActive() { return mState == eState::Active; }
		bool isDead() { return mState == eState::Dead; }

		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }
	private:
		eState mState;
		vector<HyeonComponent*> mComponents;
		eLayerType mLayerType;
	};
}