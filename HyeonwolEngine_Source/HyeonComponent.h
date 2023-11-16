#pragma once

#include "HyeonEntity.h"

namespace Hyeon
{
	class HyeonGameObject;
	class HyeonComponent : public HyeonEntity
	{
	public:
		HyeonComponent();
		~HyeonComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(HyeonGameObject* owner) { mOwner = owner; }
		HyeonGameObject* GetOwner() { return mOwner; }
	private:
		HyeonGameObject* mOwner;
	};
}