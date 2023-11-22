#pragma once

#include "CommonInclude.h"
#include "HyeonComponent.h"

namespace Hyeon
{
	class HyeonGameObject
	{
	public:
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
			//comp->Initialize();
			comp->HyeonComponent::SetOwner(this);
			mComponents.push_back(comp);
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
	private:
		vector<HyeonComponent*> mComponents;
	};
}