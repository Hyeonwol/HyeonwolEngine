#pragma once
#include "HyeonComponent.h"
#include "HyeonAnimation.h"

namespace Hyeon
{
	class HyeonAnimator : public HyeonComponent
	{
	public:
		struct Event
		{
			void operator=(function<void()> func)
			{
				mEvent = move(func);
			}

			void operator()()
			{
				if (mEvent)
						mEvent;
			}

			function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

		HyeonAnimator();
		~HyeonAnimator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const wstring& name,
			graphics::HyeonTexture* spriteSheet,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		HyeonAnimation* FindAnimation(const wstring& name);
		void PlayAnimation(const wstring& name, bool loop = true);

		bool IsComplete() { return mActiveAnimation->isComplete(); }

	private:
		map<wstring, HyeonAnimation*> mAnimations;
		HyeonAnimation* mActiveAnimation;
		bool mbLoop;

		map<wstring, Events*> mEvents;
	};
}
