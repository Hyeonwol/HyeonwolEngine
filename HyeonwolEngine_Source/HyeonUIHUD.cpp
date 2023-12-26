#include "HyeonUIHUD.h"
#include "HyeonResources.h"

namespace Hyeon
{
	HyeonUIHUD::HyeonUIHUD()
		:HyeonUIBase(eUIType::Hpbar)
	{
	}
	HyeonUIHUD::~HyeonUIHUD()
	{
	}
	void HyeonUIHUD::OnInit()
	{
		mTexture = HyeonResources::Find<graphics::HyeonTexture>(L"HPBar");
	}
	void HyeonUIHUD::OnActive()
	{
	}
	void HyeonUIHUD::OnInActive()
	{
	}
	void HyeonUIHUD::OnUpdate()
	{
	}
	void HyeonUIHUD::OnLateUpdate()
	{
	}
	void HyeonUIHUD::OnRender(HDC hdc)
	{
		TransparentBlt(hdc,
			0, 0,
			mTexture->GetWidth(),
			mTexture->GetHeight(),
			mTexture->GetHdc(),
			0, 0,
			mTexture->GetWidth(),
			mTexture->GetHeight(),
			RGB(255, 0, 255));
	}
	void HyeonUIHUD::OnClear()
	{
	}
}