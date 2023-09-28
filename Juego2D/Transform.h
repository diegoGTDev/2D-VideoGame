#ifndef TRANSFORM_H
#define TRANSFORM_H
#include<iostream>
class Transform
{
public:
	float X, Y;
	Transform(float x = 0, float y = 0) : X(x), Y(y) {};

	void Log(std::string msg = "") {
		std::cout << msg << " X: " << X << " Y: " << Y << std::endl;
	}
private:
	inline void TranslateX(float x) {
		X += x;
	}
	inline void TranslateY(float y) {
		Y += y;
	}
	inline void Translate(float x, float y) {
		X += x;
		Y += y;
	}

};

#endif