#include "HyeonCircleCollider2D.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonRenderer.h"
#include "HyeonCamera.h"

namespace Hyeon
{
	HyeonCircleCollider2D::HyeonCircleCollider2D()
		:HyeonCollider(enums::eCollidertype::Circle2D)
	{
	}
	HyeonCircleCollider2D::~HyeonCircleCollider2D()
	{
	}
	void HyeonCircleCollider2D::Initialize()
	{
	}
	void HyeonCircleCollider2D::Update()
	{
	}
	void HyeonCircleCollider2D::LateUpdate()
	{
	}
	void HyeonCircleCollider2D::Render(HDC hdc)
	{
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBottom;
		rightBottom.X = pos.X + offset.X + 100 * GetSize().X;
		rightBottom.Y = pos.Y + offset.Y + 100 * GetSize().Y;

		Ellipse(hdc, pos.X + offset.X,
			pos.Y + offset.Y,
			rightBottom.X,
			rightBottom.Y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}