#include "HyeonDontDestroyOnLoad.h"

Hyeon::HyeonDontDestroyOnLoad::HyeonDontDestroyOnLoad()
{
}

Hyeon::HyeonDontDestroyOnLoad::~HyeonDontDestroyOnLoad()
{
}

void Hyeon::HyeonDontDestroyOnLoad::Initialize()
{
	HyeonScene::Initialize();
}

void Hyeon::HyeonDontDestroyOnLoad::Update()
{
	HyeonScene::Update();
}

void Hyeon::HyeonDontDestroyOnLoad::LateUpdate()
{
	HyeonScene::LateUpdate();
}

void Hyeon::HyeonDontDestroyOnLoad::Render(HDC hdc)
{
	HyeonScene::Render(hdc);
}

void Hyeon::HyeonDontDestroyOnLoad::OnEnter()
{
	HyeonScene::OnEnter();
}

void Hyeon::HyeonDontDestroyOnLoad::OnExit()
{
	HyeonScene::OnExit();
}
