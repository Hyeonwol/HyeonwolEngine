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
		gameObj->SetLayerType(type);
		HyeonScene* activeScene = HyeonSceneManager::GetActiveScene();
		HyeonLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObj);

		return gameObj;
	}

	template <typename T>
	static T* Instantiate(enums::eLayerType type, HyeonMath::Vector2 pos)
	{
		T* gameObj = new T();
		gameObj->SetLayerType(type);
		HyeonScene* activeScene = HyeonSceneManager::GetActiveScene();
		HyeonLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObj);

		HyeonTransform* tr = gameObj->GetComponent<HyeonTransform>();
		tr->SetPosition(pos);

		return gameObj;
	}

	static void DontDestroyOnLoad(HyeonGameObject* gameObj)
	{
		HyeonScene* activeScene = HyeonSceneManager::GetActiveScene();
		//현재 Scene에서 게임 오브젝트들 삭제
		activeScene->EraseGameObject(gameObj);

		//파괴해선 안되는 오브젝트들을 DontDestroy Scene으로 옮겨준다
		HyeonScene* dontDestroyOnLoad = HyeonSceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObj, gameObj->GetLayerType());
	}
}