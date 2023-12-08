#include "HyeonBoxCollider2D.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	HyeonBoxCollider2D::HyeonBoxCollider2D()
		:HyeonCollider()
	{
	}
	HyeonBoxCollider2D::~HyeonBoxCollider2D()
	{
	}
	void HyeonBoxCollider2D::Initialize()
	{
	}
	void HyeonBoxCollider2D::Update()
	{
	}
	void HyeonBoxCollider2D::LateUpdate()
	{
	}
	void HyeonBoxCollider2D::Render(HDC hdc)
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc, pos.X + offset.X,
			pos.Y + offset.Y,
			pos.X + offset.X + 100,
			pos.Y + offset.Y + 100);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}