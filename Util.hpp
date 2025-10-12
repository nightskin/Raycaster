#pragma once
#include <math.h>

struct Vector2
{
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float rad)
	{
		x = cosf(rad);
		y = sinf(rad);
	}
	Vector2(float xp, float yp)
	{
		x = xp;
		y = yp;
	}
	float Distance(Vector2 other)
	{
		return sqrtf(powf(other.x - x, 2) + powf(other.y - y, 2));
	}
	float GetLength()
	{
		return sqrtf((x * x) + (y * y));
	}
	Vector2 Normalized()
	{
		return Vector2(x, y) / GetLength();
	}
	Vector2 Rotated(float rad)
	{
		float xp = x * cosf(rad) - y * sinf(rad);
		float yp = x * sinf(rad) + y * cosf(rad);
		return Vector2(xp, yp);
	}

	Vector2 operator + (Vector2 o)
	{
		return Vector2(x + o.x, y + o.y);
	}
	Vector2 operator - (Vector2 o)
	{
		return Vector2(x - o.x, y - o.y);
	}
	Vector2 operator * (float o)
	{
		return Vector2(x * o, y * o);
	}
	Vector2 operator / (float o)
	{
		return Vector2(x / o, y / o);
	}
	void operator += (Vector2 o)
	{
		x += o.x;
		y += o.y;
	}
	void operator -= (Vector2 o)
	{
		x -= o.x;
		y -= o.y;
	}
	void operator *= (float o)
	{
		x *= o;
		y *= o;
	}
	void operator /= (float o)
	{
		x /= o;
		y /= o;

	}



	float x = 0;
	float y = 0;
};

struct Vector3
{
	Vector3()
	{
		x = 0;
		y = 0;
	}
	Vector3(float xp, float yp)
	{
		x = xp;
		y = yp;
		z = 0;
	}
	Vector3(Vector2 xy)
	{
		x = xy.x;
		y = xy.y;
		z = 0;
	}
	Vector3(float xp, float yp, float zp)
	{
		x = xp;
		y = yp;
		z = zp;
	}
	Vector3(Vector2 xy, float zp)
	{
		x = xy.x;
		y = xy.y;
		z = zp;
	}

	float GetLength()
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}
	Vector3 Normalized()
	{
		return Vector3(x,y,z) / GetLength();
	}
	void Normalize()
	{
		float length = GetLength();
		x /= length;
		y /= length;
		z /= length;
	}
	Vector3 operator + (Vector3 o)
	{
		return Vector3(x + o.x, y + o.y, z + o.z);
	}
	Vector3 operator - (Vector3 o)
	{
		return Vector3(x - o.x, y - o.y, z - o.z);
	}
	Vector3 operator * (float o)
	{
		return Vector3(x * o, y * o, z * o);
	}
	Vector3 operator / (float o)
	{
		return Vector3(x / o, y / o, z / o);
	}
	void operator += (Vector3 o)
	{
		x += o.x;
		y += o.y;
		z += o.z;
	}
	void operator -= (Vector3 o)
	{
		x -= o.x;
		y -= o.y;
		z -= o.z;
	}
	void operator *= (float o)
	{
		x *= o;
		y *= o;
		z *= o;
	}
	void operator /= (float o)
	{
		x /= o;
		y /= o;
		z /= o;
	}

	

	float x = 0;
	float y = 0;
	float z = 0;
};

struct Color
{
	Color()
	{

	}
	Color(float s)
	{
		r = g = b = s;
		a = 1;
	}
	Color(float red, float green, float blue)
	{
		r = red;
		g = green;
		b = blue;
		a = 1;
	}
	Color(float red, float green, float blue, float alpha)
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;
};

struct Hit2D
{
	Hit2D()
	{
		exists = false;
		hitPoint = Vector2();
	}
	Hit2D(Vector2 p)
	{
		exists = true;
		hitPoint = p;
	}

	bool exists;
	Vector2 hitPoint;
};

struct Line
{
	Line()
	{
		start = Vector2();
		end = Vector2();
	}
	Line(float sx, float sy, float ex, float ey)
	{
		start = Vector2(sx, sy);
		end = Vector2(ex, ey);
	}
	Line(Vector2 s, Vector2 e)
	{
		start = s;
		end = e;
	}

	Hit2D Intersection(Line other)
	{
		float x1 = start.x;
		float x2 = end.x;
		float x3 = other.start.x;
		float x4 = other.end.x;

		float y1 = start.y;
		float y2 = end.y;
		float y3 = other.start.y;
		float y4 = other.end.y;

		float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
		float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

		if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) 
		{
			float intersectionX = x1 + (uA * (x2 - x1));
			float intersectionY = y1 + (uA * (y2 - y1));
			return Hit2D(Vector2(intersectionX, intersectionY));
		}
		return Hit2D();
	}

	Vector2 start;
	Vector2 end;
};

class MathHelper
{
public:
	static float Deg2Rad(float d)
	{
		return (3.14159f / 180.0f) * d;
	}

	static float Rad2Deg(float r)
	{
		return (180.0f / 3.14159f) * r;
	}
};
