#include "HyeonPlayerScript.h"
#include "HyeonInput.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonTime.h"

namespace Hyeon
{
	HyeonPlayerScript::HyeonPlayerScript()
	{
	}
	HyeonPlayerScript::~HyeonPlayerScript()
	{
	}
	void HyeonPlayerScript::Initialize()
	{
	}
	void HyeonPlayerScript::Update()
	{
		if (HyeonInput::GetKeyPressed(eKeyCode::Right))
		{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPos();
			pos.X += 100.0f * HyeonTime::GetDelataTime();
			tr->SetPos(pos);
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::Left))
		{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPos();
			pos.X -= 100.0f * HyeonTime::GetDelataTime();
			tr->SetPos(pos);
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::Up))
		{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPos();
			pos.Y -= 100.0f * HyeonTime::GetDelataTime();
			tr->SetPos(pos);
		}
		if (HyeonInput::GetKeyPressed(eKeyCode::Down))
		{
			HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
			Vector2 pos = tr->GetPos();
			pos.Y += 100.0f * HyeonTime::GetDelataTime();
			tr->SetPos(pos);
		}
	}
	void HyeonPlayerScript::LateUpdate()
	{
	}
	void HyeonPlayerScript::Render(HDC hdc)
	{
	}
}
