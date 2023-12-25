#include "HyeonScene.h"
#include "HyeonCollisionManager.h"

namespace Hyeon 
{
	HyeonScene::HyeonScene()
		:mLayers{}
	{
		createLayers();
	}
	HyeonScene::~HyeonScene()
	{
		for (HyeonLayer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}
	void HyeonScene::Initialize()
	{
		for (HyeonLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}
	void HyeonScene::Update()
	{
		for (HyeonLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void HyeonScene::LateUpdate()
	{
		for (HyeonLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void HyeonScene::Render(HDC hdc)
	{
		for (HyeonLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}

	void HyeonScene::Destroy()
	{
		for (HyeonLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void HyeonScene::AddGameObject(HyeonGameObject* gameObject, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}

	void HyeonScene::EraseGameObject(HyeonGameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	void HyeonScene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new HyeonLayer();
		}
	}

	void HyeonScene::OnEnter()
	{

	}

	void HyeonScene::OnExit()
	{
		HyeonCollisionManager::Clear();
	}
}