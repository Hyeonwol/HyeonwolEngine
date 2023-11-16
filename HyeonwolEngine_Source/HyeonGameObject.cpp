#include "HyeonGameObject.h"
#include "HyeonInput.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonGameObject::HyeonGameObject()
	{

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

}
