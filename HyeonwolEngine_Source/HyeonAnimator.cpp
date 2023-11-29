#include "HyeonAnimator.h"

namespace Hyeon
{
	HyeonAnimator::HyeonAnimator()
		: HyeonComponent(enums::eComponentType::Animator),
		  mAnimations{},
		  mActiveAnimation(nullptr),
		  mbLoop(false)
	{
	}
	HyeonAnimator::~HyeonAnimator()
	{
	}
	void HyeonAnimator::Initialize()
	{
	}
	void HyeonAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mActiveAnimation->isComplete()==true
				&& mbLoop==true)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void HyeonAnimator::LateUpdate()
	{
	}
	void HyeonAnimator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	void HyeonAnimator::CreateAnimation(const wstring& name, 
		graphics::HyeonTexture* spriteSheet, 
		Vector2 leftTop, Vector2 size, 
		Vector2 offset, UINT spriteLength, 
		float duration)
	{
		HyeonAnimation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new HyeonAnimation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, 
			offset, spriteLength, duration);

		animation->SetAnimator(this);
		mAnimations.insert(make_pair(name, animation));
	}
	HyeonAnimation* HyeonAnimator::FindAnimation(const wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
		
	}
	void HyeonAnimator::PlayAnimation(const wstring& name, bool loop)
	{
		HyeonAnimation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}