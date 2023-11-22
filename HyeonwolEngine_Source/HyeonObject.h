#pragma once

#include "HyeonComponent.h"
#include "HyeonGameObject.h"
#include "HyeonLayer.h"
#include "HyeonScene.h"
#include "HyeonSceneManager.h"
#include "HyeonTransform.h"


namespace Hyeon::object
{
	template <typename T>
	static T* Instantiate(enums::eLayerType type)
	{
		T* gameObj = new T();
		HyeonScene* activeScene = HyeonSceneManager::GetActiveScene();
		HyeonLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObj);

		return gameObj;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, HyeonMath::Vector2 pos)
	{
		T* gameObj = new T();
		HyeonScene* activeScene = HyeonSceneManager::GetActiveScene();
		HyeonLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObj);

		HyeonTransform* tr = gameObj->GetComponent<HyeonTransform>();
		tr->SetPos(pos);

		return gameObj;
	}
}