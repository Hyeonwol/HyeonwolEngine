#pragma once
#include <cmath>

namespace Hyeon::HyeonMath
{
	#define PI 3.141592f

	static float ConvertDegree(float radian) { return radian * (180 / PI); }

	struct Vector2
	{
		static Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180.f) * PI;
			vector.normalize();
			float x = cosf(radian) * vector.X - sinf(radian) * vector.Y;
			float y = sinf(radian) * vector.X - cosf(radian) * vector.Y;

			return Vector2(x, y);
		}

		static float Dot(Vector2& v1, Vector2 v2)
		{
			return v1.X * v2.X + v1.Y * v2.Y;
		}

		static float Cross(Vector2 v1, Vector2 v2)
		{
			return v1.X * v2.Y - v1.Y * v2.X;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

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

		Vector2 operator+=(Vector2 other)
		{
			X += other.X;
			Y += other.Y;
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(X - other.X, Y - other.Y);
		}

		Vector2 operator/(float value)
		{
			return Vector2(X / value, Y / value);
		}

		Vector2 operator*(float value)
		{
			return Vector2(X * value, Y * value);
		}

		Vector2 operator*(Vector2 v)
		{
			return Vector2(X * v.X, Y * v.Y);
		}

		void clear()
		{
			X = 0.0f;
			Y = 0.0f;
		}

		float length()
		{
			return sqrtf(X * X + Y * Y);
		}

		Vector2 normalize()
		{
			float len = length();
			X /= len;
			Y /= len;

			return *this;
		}
	};
}
