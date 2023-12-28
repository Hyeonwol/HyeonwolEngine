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
#include "HyeonCameraScript.h"

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
		camera->AddComponent<HyeonCameraScript>();
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
			createTileObject();
		}

		if (HyeonInput::GetKeyDown(eKeyCode::S))
			Save();

		else if (HyeonInput::GetKeyDown(eKeyCode::L))
			Load();
	}
	void HyeonToolScene::Render(HDC hdc)
	{
		renderGreed(hdc);
	}
	void HyeonToolScene::OnEnter()
	{
		HyeonScene::OnEnter();
	}
	void HyeonToolScene::OnExit()
	{
		HyeonScene::OnExit();
	}
	void HyeonToolScene::Save()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (HyeonTile* tile : mTiles)
		{
			HyeonTileMapRenderer* tmr = tile->GetComponent<HyeonTileMapRenderer>();
			HyeonTransform* tr = tile->GetComponent<HyeonTransform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();

			int x = sourceIndex.X;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.Y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.X;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.Y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}
	void HyeonToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			HyeonTile* tile = object::Instantiate<HyeonTile>(eLayerType::Tile, Vector2(posX, posY));
			HyeonTileMapRenderer* tmr = tile->AddComponent<HyeonTileMapRenderer>();
			tmr->SetTexture(HyeonResources::Find<graphics::HyeonTexture>(L"Mountain"));
			tmr->SetIndex(Vector2(idxX, idxY));

			mTiles.push_back(tile);
		}

		fclose(pFile);
	}
	void HyeonToolScene::renderGreed(HDC hdc)
	{
		HyeonScene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePos
			(
				Vector2(HyeonTileMapRenderer::TileSize.X * i, 0.0f)
			);

			MoveToEx(hdc, HyeonTileMapRenderer::TileSize.X * i, 0, NULL);
			LineTo(hdc, HyeonTileMapRenderer::TileSize.X * i, 2000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePos
			(
				Vector2(0.0f, HyeonTileMapRenderer::TileSize.Y * i)
			);

			MoveToEx(hdc, 0, HyeonTileMapRenderer::TileSize.Y * i, NULL);
			LineTo(hdc, 2000, HyeonTileMapRenderer::TileSize.Y * i);
		}
	}
	void HyeonToolScene::createTileObject()
	{
		Vector2 pos = HyeonInput::GetMousePosition();
			pos = renderer::mainCamera->CalcualteTilePosition(pos);

			if (pos.X >= 0.0f && pos.Y >= 0.0f)
			{
				int idxX = pos.X / HyeonTileMapRenderer::TileSize.X;
				int idxY = pos.Y / HyeonTileMapRenderer::TileSize.Y;

				HyeonTile* tile = object::Instantiate<HyeonTile>(eLayerType::Tile);
				HyeonTileMapRenderer* tileMapRenderer = tile->AddComponent<HyeonTileMapRenderer>();
				tileMapRenderer->SetTexture(HyeonResources::Find<graphics::HyeonTexture>(L"Mountain"));
				tileMapRenderer->SetIndex(HyeonTileMapRenderer::SelectedIndex);

				tile->SetPosition(idxX, idxY);
				mTiles.push_back(tile);
			}
			else
			{

			}
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
			= Hyeon::HyeonResources::Find<Hyeon::graphics::HyeonTexture>(L"Mountain");

		TransparentBlt(hdc,
			0,0,
			texture->GetWidth(),
			texture->GetHeight(),
			texture->GetHdc(),
			0, 0,
			texture->GetWidth(),
			texture->GetHeight(),
			RGB(179, 38, 195));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}