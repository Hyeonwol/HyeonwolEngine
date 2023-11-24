#pragma once

#include "HyeonEntity.h"

namespace Hyeon
{
	class HyeonGameObject;
	class HyeonComponent : public HyeonEntity
	{
	public:
		HyeonComponent(enums::eComponentType type);
		~HyeonComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(HyeonGameObject* owner) { mOwner = owner; }
		HyeonGameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType; }

	private:
		HyeonGameObject* mOwner;
		enums::eComponentType mType;
	};
}