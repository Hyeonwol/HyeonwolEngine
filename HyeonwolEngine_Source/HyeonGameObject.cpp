#include "HyeonGameObject.h"
#include "HyeonInput.h"
#include "HyeonTime.h"
#include "HyeonTransform.h"

namespace Hyeon::object
{
	void Destroy(HyeonGameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->death();
	}
}

namespace Hyeon
{
	HyeonGameObject::HyeonGameObject()
		:mState(eState::Active), 
		 mLayerType(eLayerType::None)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	HyeonGameObject::~HyeonGameObject()
	{
		for (HyeonComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			delete comp;
			comp = nullptr;
		}
	}

	void HyeonGameObject::Initialize()
	{
		for (HyeonComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void HyeonGameObject::Update()
	{
		for (HyeonComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}


	void HyeonGameObject::LateUpdate()
	{
		for (HyeonComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void HyeonGameObject::Render(HDC hdc)
	{
		for (HyeonComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void HyeonGameObject::initializeTransform()
	{
		AddComponent<HyeonTransform>();
	}
}
