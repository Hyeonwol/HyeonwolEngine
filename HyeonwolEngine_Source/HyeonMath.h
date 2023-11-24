#pragma once

namespace Hyeon::HyeonMath
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

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

		Vector2 operator+(Vector2 other)
		{
			return Vector2(X + other.X, Y + other.Y);
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(X - other.X, Y - other.Y);
		}

		Vector2 operator/(float value)
		{
			return Vector2(X / value, Y / value);
		}
	};
}
