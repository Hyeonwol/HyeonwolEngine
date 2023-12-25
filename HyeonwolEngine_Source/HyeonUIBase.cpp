#include "HyeonUIBase.h"

namespace Hyeon
{
	HyeonUIBase::HyeonUIBase(eUIType type)
		:mType(type), 
		 mbMouseOn(false)
	{
	}
	HyeonUIBase::~HyeonUIBase()
	{
	}
	void HyeonUIBase::Initialize()
	{
		OnInit();
	}
	void HyeonUIBase::Active()
	{
		mbEnabled = true;
		OnActive();
	}
	void HyeonUIBase::InActive()
	{
		mbEnabled = false;
		OnInActive();
	}
	void HyeonUIBase::Update()
	{
		if (mbEnabled)
			OnUpdate();
	}
	void HyeonUIBase::LateUpdate()
	{
		if (mbEnabled)
			OnLateUpdate();
	}
	void HyeonUIBase::Render(HDC hdc)
	{
		if (mbEnabled)
			OnRender(hdc);
	}
	void HyeonUIBase::UIClear()
	{
		OnClear();
	}
	void HyeonUIBase::OnInit()
	{
	}
	void HyeonUIBase::OnActive()
	{
	}
	void HyeonUIBase::OnInActive()
	{
	}
	void HyeonUIBase::OnUpdate()
	{
	}
	void HyeonUIBase::OnLateUpdate()
	{
	}
	void HyeonUIBase::OnRender(HDC hdc)
	{
	}
	void HyeonUIBase::OnClear()
	{
	}
}