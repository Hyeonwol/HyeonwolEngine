#include "HyeonDontDestroyOnLoad.h"

namespace Hyeon
{
	HyeonDontDestroyOnLoad::HyeonDontDestroyOnLoad()
	{
	}
	HyeonDontDestroyOnLoad::~HyeonDontDestroyOnLoad()
	{
	}
	void HyeonDontDestroyOnLoad::Initialize()
	{
		HyeonScene::Initialize();
	}
	void HyeonDontDestroyOnLoad::Update()
	{
		HyeonScene::Update();
	}
	void HyeonDontDestroyOnLoad::LateUpdate()
	{
		HyeonScene::LateUpdate();
	}
	void HyeonDontDestroyOnLoad::Render(HDC hdc)
	{
		HyeonScene::Render(hdc);
	}
	void HyeonDontDestroyOnLoad::OnEnter()
	{
		HyeonScene::OnEnter();
	}
	void HyeonDontDestroyOnLoad::OnExit()
	{
		HyeonScene::OnExit();
	}
}