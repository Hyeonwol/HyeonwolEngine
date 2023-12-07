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
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void HyeonAnimator::Initialize()
	{
	}
	void HyeonAnimator::Update()
	{
		mActiveAnimation->Update();

		Events* events = FindEvents(mActiveAnimation->GetName());

		if (mActiveAnimation->isComplete() == true)
		{
			if (events)
				events->completeEvent();

			if (mbLoop == true)
				mActiveAnimation->Reset();
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
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet, leftTop, size, 
			offset, spriteLength, duration);

		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(make_pair(name, events));

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

		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());

		if (nextEvents)
			nextEvents->startEvent();

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
	HyeonAnimator::Events* HyeonAnimator::FindEvents(const wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}
	function<void()>& HyeonAnimator::GetStartEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}
	function<void()>& HyeonAnimator::GetCompleteEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}
	function<void()>& HyeonAnimator::GetEndEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}