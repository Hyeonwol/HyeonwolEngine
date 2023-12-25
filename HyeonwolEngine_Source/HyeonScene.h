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
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(HyeonGameObject* gameObject, const enums::eLayerType type);
		void EraseGameObject(HyeonGameObject* gameObj);
		HyeonLayer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void createLayers();
	private:
		vector<HyeonLayer*> mLayers;
	};
}
