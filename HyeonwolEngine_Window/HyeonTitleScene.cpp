#include "HyeonTitleScene.h"
#include "HyeonSpriteRenderer.h"
#include "HyeonInput.h"
#include "HyeonSceneManager.h"

namespace Hyeon
{
	HyeonTitleScene::HyeonTitleScene()
	{
	}
	HyeonTitleScene::~HyeonTitleScene()
	{
	}
	void HyeonTitleScene::Initialize()
	{
		HyeonScene::Initialize();
	}
	void HyeonTitleScene::Update()
	{
		HyeonScene::Update();
	}
	void HyeonTitleScene::LateUpdate()
	{
		HyeonScene::LateUpdate();

		if (HyeonInput::GetKeyDown(eKeyCode::N))
		{
			HyeonSceneManager::LoadScene(L"PlayScene");
		}
	}
	void HyeonTitleScene::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}