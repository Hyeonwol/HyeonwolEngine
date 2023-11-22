#pragma once
#include "HyeonEntity.h"
#include "HyeonGameObject.h"
#include "HyeonLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(HyeonGameObject* gameObject, eLayerType type);

	private:
		void CreateLayers();
	private:
		vector<HyeonLayer*> mLayers;
	};
}
