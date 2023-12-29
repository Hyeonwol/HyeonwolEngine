#pragma once
#include "..//HyeonwolEngine_Source/HyeonScript.h"
#include "..//HyeonwolEngine_Source/HyeonTexture.h"

namespace Hyeon
{
	class HyeonMovePlayerScript : public HyeonScript
	{
	public:
		enum class eState
		{
			Relax,
			Move,
		};

		enum class eDir
		{
			Left,
			Right,
			Up,
			Down
		};

		HyeonMovePlayerScript();
		~HyeonMovePlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(HyeonCollider* other) override;
		void OnCollisionStay(HyeonCollider* other) override;
		void OnCollisionExit(HyeonCollider* other) override;

		void SetPixelMapTexture(graphics::HyeonTexture* texture) { mPixelMap = texture; }
	private:
		void relaxing();
		void moving();
		void walkingAnimation();
		void relaxingAnimation();
		void runnungAnimation();

	private:
		eState mState;
		eDir mDir;
		float mTime;
		bool isRunning;
		class HyeonAnimator* mAnimator;

		graphics::HyeonTexture* mPixelMap;
	};
}
