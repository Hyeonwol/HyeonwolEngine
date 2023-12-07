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
		virtual void Destroy();

		void AddGameObject(HyeonGameObject* gameObject);
	
	private:
		void findDeadGameObjects(OUT vector<HyeonGameObject*>& gameObjs);
		void deleteGameObjects(vector<HyeonGameObject*> gameObjs);
		void eraseGameObject();
	private:
		vector<HyeonGameObject*> mGameObjects;
		typedef vector<HyeonGameObject*>::iterator GameObjectIter;
	};
}
