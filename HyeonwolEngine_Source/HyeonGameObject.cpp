#include "HyeonGameObject.h"
#include "HyeonInput.h"
#include "HyeonTime.h"
#include "HyeonTransform.h"

namespace Hyeon
{
	HyeonGameObject::HyeonGameObject()
	{
		initializeTransform();
	}

	HyeonGameObject::~HyeonGameObject()
	{
	}

	void HyeonGameObject::Initialize()
	{
		for (HyeonComponent* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void HyeonGameObject::Update()
	{
		for (HyeonComponent* comp : mComponents)
		{
			comp->Update();
		}
	}


	void HyeonGameObject::LateUpdate()
	{
		for (HyeonComponent* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void HyeonGameObject::Render(HDC hdc)
	{
		for (HyeonComponent* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}

	void HyeonGameObject::initializeTransform()
	{
		AddComponent<HyeonTransform>();
	}
}
