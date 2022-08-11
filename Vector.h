#pragma once
#include <iostream>
struct Vector {
	float x, y, z;
	Vector();
	Vector(float x, float y, float z);


	void operator=(Vector vec);
	Vector operator+(Vector vec);
	Vector operator-(Vector vec);
	Vector operator-();
	Vector operator*(Vector vec);
	Vector operator/(Vector vec);
	Vector operator*(float vec);
	Vector operator/(float vec);
	void operator+=(Vector vec);
	void operator-=(Vector vec);
	void operator/=(Vector vec);
	void operator*=(Vector vec);
	float operator[](int i);

	Vector abs(bool set_classmember_to_abs);
	float length();

};