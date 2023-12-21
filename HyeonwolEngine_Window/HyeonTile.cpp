#include "HyeonTile.h"
#include "HyeonInput.h"
#include "HyeonTime.h"
#include "HyeonTransform.h"
#include "HyeonTileMapRenderer.h"

namespace Hyeon
{
	void HyeonTile::Initialize()
	{
		HyeonGameObject::Initialize();
	}
	void HyeonTile::Update()
	{
		HyeonGameObject::Update();
	}
	void HyeonTile::LateUpdate()
	{
		HyeonGameObject::LateUpdate();
	}
	void HyeonTile::Render(HDC hdc)
	{
		HyeonGameObject::Render(hdc);
	}
	void HyeonTile::SetPosition(int x, int y)
	{
		HyeonTransform* tr = GetComponent<HyeonTransform>();
		Vector2 pos;
		pos.X = x * HyeonTileMapRenderer::TileSize.X;
		pos.Y = y * HyeonTileMapRenderer::TileSize.Y;
		tr->SetPosition(pos);
	}
}