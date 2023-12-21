#include "HyeonToolScene.h"
#include "HyeonGameObject.h"
#include "HyeonCamera.h"
#include "HyeonTile.h"
#include "HyeonTexture.h"
#include "HyeonRenderer.h"
#include "HyeonObject.h"
#include "HyeonTileMapRenderer.h"
#include "HyeonResources.h"
#include "HyeonInput.h"

namespace Hyeon
{
	HyeonToolScene::HyeonToolScene()
	{
	}
	HyeonToolScene::~HyeonToolScene()
	{
	}
	void HyeonToolScene::Initialize()
	{
		HyeonGameObject* camera = object::Instantiate<HyeonGameObject>(enums::eLayerType::Particle, Vector2(607.0f, 519.0f));
		HyeonCamera* cameraComp = camera->AddComponent<HyeonCamera>();
		renderer::mainCamera = cameraComp;

		HyeonScene::Initialize();
	}
	void HyeonToolScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonToolScene::LateUpdate()
	{
		HyeonScene::LateUpdate();

		if (HyeonInput::GetKeyDown(eKeyCode::LButton))
		{
			Vector2 pos = HyeonInput::GetMousePosition();
			
			int idxX = pos.X / HyeonTileMapRenderer::TileSize.X;
			int idxY = pos.Y / HyeonTileMapRenderer::TileSize.Y;

			HyeonTile* tile = object::Instantiate<HyeonTile>(eLayerType::Tile);
			HyeonTileMapRenderer* tileMapRenderer = tile->AddComponent<HyeonTileMapRenderer>();
			tileMapRenderer->SetTexture(HyeonResources::Find<graphics::HyeonTexture>(L"BlackOmen"));
			tileMapRenderer->SetIndex(HyeonTileMapRenderer::SelectedIndex);

			tile->SetPosition(idxX, idxY);
		}
	}
	void HyeonToolScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, HyeonTileMapRenderer::TileSize.X * i, 0, NULL);
			LineTo(hdc, HyeonTileMapRenderer::TileSize.X * i, 2000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, HyeonTileMapRenderer::TileSize.Y * i, NULL);
			LineTo(hdc, 2000, HyeonTileMapRenderer::TileSize.Y * i);

		}
	}
	void HyeonToolScene::OnEnter()
	{
		HyeonScene::OnEnter();
	}
	void HyeonToolScene::OnExit()
	{
		HyeonScene::OnExit();
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		Hyeon::HyeonMath::Vector2 mousePosition;
		mousePosition.X = mousePos.x;
		mousePosition.Y = mousePos.y;

		int idxX = mousePosition.X / Hyeon::HyeonTileMapRenderer::OriginTileSize.X;
		int idxY = mousePosition.Y / Hyeon::HyeonTileMapRenderer::OriginTileSize.Y;

		Hyeon::HyeonTileMapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		Hyeon::graphics::HyeonTexture* texture
			= Hyeon::HyeonResources::Find<Hyeon::graphics::HyeonTexture>(L"BlackOmen");

		TransparentBlt(hdc,
			0,0,
			texture->GetWidth(),
			texture->GetHeight(),
			texture->GetHdc(),
			0, 0,
			texture->GetWidth(),
			texture->GetHeight(),
			RGB(0, 158, 0));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hWnd, 0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}