#include "HyeonPlayer.h"
#include "HyeonInput.h"
#include "HyeonTime.h"
#include "HyeonTransform.h"

namespace Hyeon
{
	void HyeonPlayer::Initialize()
	{
		HyeonGameObject::Initialize();
	}
	void HyeonPlayer::Update()
	{
		HyeonGameObject::Update();
	}
	void HyeonPlayer::LateUpdate()
	{
		HyeonGameObject::LateUpdate();

		if (HyeonInput::GetKeyDown(eKeyCode::D))
		{
			HyeonTransform* tr = GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPos();
			pos.X += 100.0f * HyeonTime::GetDelataTime();
			tr->SetPos(pos);
		}
	}
	void HyeonPlayer::Render(HDC hdc)
	{
		HyeonGameObject::Render(hdc);
	}
}