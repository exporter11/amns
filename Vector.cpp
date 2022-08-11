#include "Vector.h"
Vector::Vector() { x = 0; y = 0; z = 0; };
Vector::Vector(float x, float y, float z) { this->x = x, this->y = y; this->z = z; }
void Vector::operator=(Vector vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}
Vector Vector::operator+(Vector vec)
{
	return Vector(x + vec.x, y + vec.y, z + vec.z);
}
Vector Vector::operator-(Vector vec)
{
	return Vector(x - vec.x, y - vec.y, z - vec.z);
}
Vector Vector::operator-() {
	return Vector(-x, -y, -z);
}
Vector Vector::operator*(Vector vec)
{
	return Vector(x * vec.x, y * vec.y, z * vec.z);
}
Vector Vector::operator/(Vector vec)
{
	return Vector(x / vec.x, y / vec.y, z / vec.z);
}
Vector Vector::operator*(float vec)
{
	return Vector(x * vec, y * vec, z * vec);
}
Vector Vector::operator/(float vec)
{
	return Vector(x / vec, y / vec, z / vec);
}
void Vector::operator+=(Vector vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
}
void Vector::operator-=(Vector vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}
void Vector::operator/=(Vector vec) {
	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
}
void Vector::operator*=(Vector vec) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}
float Vector::operator[](int i) {
	if (i > 2)
		i = 2;

	return i == 0 ? x : (i == 1 ? y : z);
}
Vector Vector::abs(bool set_classmembers_to_abs) {
	if (set_classmembers_to_abs)
	{
		x = x < 0 ? -x : x;
		y = y < 0 ? -y : y;
		z = z < 0 ? -z : z;
	}

	return Vector(x < 0 ? -x : x, y < 0 ? -y : y, z < 0 ? -z : z );
}
float Vector::length() {
	return sqrt(x * x + y * y + z * z);
}