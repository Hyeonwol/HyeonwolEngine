#include "HyeonCameraScript.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonInput.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonCameraScript::HyeonCameraScript()
	{
	}
	HyeonCameraScript::~HyeonCameraScript()
	{
	}
	void HyeonCameraScript::Initialize()
	{
	}
	void HyeonCameraScript::Update()
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		if (HyeonInput::GetKeyPressed(eKeyCode::Right))
		{
			pos.X += 100.0f * HyeonTime::GetDelataTime();
		}
		
		else if (HyeonInput::GetKeyPressed(eKeyCode::Left))
		{
			pos.X -= 100.0f * HyeonTime::GetDelataTime();
		}

		else if (HyeonInput::GetKeyPressed(eKeyCode::Down))
		{
			pos.Y += 100.0f * HyeonTime::GetDelataTime();
		}

		else if (HyeonInput::GetKeyPressed(eKeyCode::Up))
		{
			pos.Y -= 100.0f * HyeonTime::GetDelataTime();
		}

		tr->SetPosition(pos);
	}
	void HyeonCameraScript::LateUpdate()
	{
	}
	void HyeonCameraScript::Render(HDC hdc)
	{
	}
}