#pragma once
#include <iostream>
#include "Vector.h"
struct QAngle {
	float x, y, z;
	QAngle();
	QAngle(float x, float y, float z);


	void operator=(QAngle ang);
	QAngle operator+(QAngle ang);
	QAngle operator-(QAngle ang);
	QAngle operator-();
	QAngle operator*(QAngle ang);
	QAngle operator/(QAngle ang);
	QAngle operator*(float ang);
	QAngle operator/(float ang);
	void operator+=(QAngle ang);
	void operator-=(QAngle ang);
	void operator/=(QAngle ang);
	void operator*=(QAngle ang);
    float operator[](int i);

	QAngle abs(bool set_classmember_to_abs);
    void clamp();
	void angle_from_vector(Vector forward);
	float fov();
 
};