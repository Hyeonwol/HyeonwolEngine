#include "HyeonSpriteRenderer.h"
#include "HyeonGameObject.h"
#include "HyeonTransform.h"


namespace Hyeon
{
	HyeonSpriteRenderer::HyeonSpriteRenderer()
	{
	}
	HyeonSpriteRenderer::~HyeonSpriteRenderer()
	{
	}
	void HyeonSpriteRenderer::Initialize()
	{
	}
	void HyeonSpriteRenderer::Update()
	{
	}
	void HyeonSpriteRenderer::LateUpdate()
	{
	}
	void HyeonSpriteRenderer::Render(HDC hdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush);

		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();

		Rectangle(hdc, 100 + tr->GetX(), 100 + tr->GetY(), 200 + tr->GetX(), 200 + tr->GetY());

		SelectObject(hdc, oldbrush);
		DeleteObject(bluebrush);
	}
}