#pragma once
#include "HyeonResource.h"
#include "HyeonTexture.h"

namespace Hyeon
{
	class HyeonAnimation : public HyeonResource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				:leftTop(Vector2::Zero),
				 size(Vector2::Zero),
				 offset(Vector2::Zero),
				 duration(0.0f)
			{

			}
		};

		HyeonAnimation();
		~HyeonAnimation();

		HRESULT Load(const wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const wstring& name,
			graphics::HyeonTexture* spriteSheet,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		void Reset();

		bool isComplete() { return mbComplete; }
		void SetAnimator(class HyeonAnimator* animator) { mAnimator = animator; }

	private:
		class HyeonAnimator* mAnimator;
		graphics::HyeonTexture* mTexture;

		vector<Sprite> mAnimationSheet;
		int mindex;
		float mTime;
		bool mbComplete;
	};
}
