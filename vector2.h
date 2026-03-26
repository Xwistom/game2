
#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include<math.h>

class Vector2
	/*二维向量类，表示一个具有x和y坐标的点或向量*/
{

public:
	Vector2() = default;
	Vector2(float x, float y) :x(x), y(y) {}
	~Vector2() = default;

	Vector2 operator+(const Vector2& other) const//重载加法运算符，实现向量的加法运算，参数other是另一个Vector2对象，返回一个新的Vector2对象，表示两个向量的和
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const//重载减法运算符，实现向量的减法运算，参数other是另一个Vector2对象，返回一个新的Vector2对象，表示两个向量的差
	{
		return Vector2(x - other.x, y - other.y);
	}

	void operator+=(const Vector2& other)//重载加法赋值运算符，实现向量的加法赋值运算，参数other是另一个Vector2对象，将当前向量与other相加，并将结果赋值给当前向量
	{
		x += other.x;
		y += other.y;
	}	

	void operator-=(const Vector2& other)//重载减法赋值运算符，实现向量的减法赋值运算，参数other是另一个Vector2对象，将当前向量与other相减，并将结果赋值给当前向量
	{
		x -= other.x;
		y -= other.y;
	}

	float operator*(const Vector2& other) const//重载乘法运算符，实现向量的点积运算，参数other是另一个Vector2对象，返回一个浮点数，表示两个向量的点积结果
	{
		return x * other.x + y * other.y;
	}

	Vector2 operator*(float scalar) const//重载乘法运算符，实现向量与标量的乘法运算，参数scalar是一个浮点数，返回一个新的Vector2对象，表示当前向量与标量的乘积
	{
		return Vector2(x * scalar, y * scalar);
	}

	void operator*=(float scalar)//重载乘法赋值运算符，实现向量与标量的乘法赋值运算，参数scalar是一个浮点数，将当前向量与标量相乘，并将结果赋值���当前向量
	{
		x *= scalar;
		y *= scalar;
	}

	float length() const//计算向量的长度，返回一个浮点数，表示当前向量的长度
	{
		return sqrt(x * x + y * y);
	}

	Vector2 normalized() //计算向量的单位向量，返回一个新的Vector2对象，表示当前向量的单位向量
	{
		float len = length();
		if (len == 0)
		{
			return Vector2(0, 0);
		}
		return Vector2(x / len, y / len);
	}


public:
	float x = 0;//x坐标
	float y = 0;//y坐标
};

#endif