#pragma once
#include "CommonInclude.h"
#include "HyeonEntity.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	class HyeonScene : public HyeonEntity
	{
	public:
		HyeonScene();
		~HyeonScene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(HyeonGameObject* gameObject);
	private:
		vector<HyeonGameObject*> mGameObjects;
	};
}
