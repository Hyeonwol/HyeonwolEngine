#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
	using namespace HyeonMath;

	class HyeonTransform : public HyeonComponent
	{
	public:
		HyeonTransform();
		~HyeonTransform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition.X = pos.X; mPosition.Y = pos.Y; }
		Vector2 GetPosition() { return mPosition; }
		void SetRotation(float rotation) { mRotation = rotation; }
		float GetRotation() { return mRotation; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mPosition;
		float mRotation;
		Vector2 mScale;
	};
}