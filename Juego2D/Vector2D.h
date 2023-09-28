#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H
#include<iostream>
class Vector2D
{
	public:
	float X, Y;
	Vector2D(float x=0, float y=0): X(x), Y(y){}
	
		inline Vector2D operator+ (const Vector2D& v2) const {
			return Vector2D(X + v2.X, Y + v2.Y);
		}
		
		inline Vector2D operator- (const Vector2D& v2) const {
			return Vector2D(X - v2.X, Y - v2.Y);
		}

		// Multiplicacion por escalar
		inline Vector2D operator* (float escalar) const {
			return Vector2D(X * escalar, Y * escalar);
		}

		// Division por escalar
		inline Vector2D operator/ (float escalar) const {
			return Vector2D(X / escalar, Y / escalar);
		}

		void Log(std::string msg = "") {
			std::cout<<msg<<" X: "<<X<<" Y: "<<Y<<std::endl;
		}

};
#endif
