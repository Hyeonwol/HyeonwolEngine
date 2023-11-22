#include "HyeonScene.h"

namespace Hyeon 
{
	HyeonScene::HyeonScene()
		:mLayers{}
	{
		CreateLayers();
	}
	HyeonScene::~HyeonScene()
	{
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

	void HyeonScene::AddGameObject(HyeonGameObject* gameObject, eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}

	void HyeonScene::CreateLayers()
	{
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new HyeonLayer();
		}
	}

	void HyeonScene::OnEnter()
	{

	}

	void HyeonScene::OnExit()
	{

	}
}