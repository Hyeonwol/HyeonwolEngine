#pragma once

namespace Hyeon::HyeonMath
{
	struct Vector2
	{
		float X;
		float Y;

		Vector2()
		   :X(0.0f),
			Y(0.0f)
		{
		}

		Vector2(float _x, float _y)
			:X(_x),
			 Y(_y)
		{
		}
	};
}
