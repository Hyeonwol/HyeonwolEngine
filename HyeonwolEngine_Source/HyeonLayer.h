#pragma once
#include "HyeonEntity.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	class HyeonLayer : public HyeonEntity
	{
	public:
		HyeonLayer();
		virtual ~HyeonLayer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(HyeonGameObject* gameObject);
	private:
		vector<HyeonGameObject*> mGameObjects;
	};
}
