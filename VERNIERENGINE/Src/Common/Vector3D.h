#pragma once

#include <cmath>
#include <ostream>
#include <string>

namespace Ogre {
	template<int dims, typename T>
	class Vector;
	typedef float Real;
	typedef Vector<3, Real> Vector3;
	class Quaternion;
	class Matrix4;
	class Matrix3;
}

/*
 * A class implementing a 3-dimensional vector and corresponding
 * operations. All operations generate new Vector3D, they do not
 * modify the vectors on which they operate. The only methods that
 * modify the state are the different setters (and operator=).
 */

class Vector3D {
public:

	// various constructors
	Vector3D() noexcept :
		x_(), y_(), z_() {
	}

	Vector3D(const Vector3D& v) :
		x_(v.getX()), y_(v.getY()), z_(v.getZ()) {
	}

	Vector3D(Vector3D&& v) :
		x_(v.getX()), y_(v.getY()), z_(v.getZ()) {
	}

	Vector3D(const Vector3D* v) :
		x_(v->getX()), y_(v->getY()), z_(v->getZ()) {
	}

	Vector3D(float x, float y, float z) :
		x_(x), y_(y), z_(z) {
	}

	Vector3D(std::string s) {
		char *ptr, *char_s, *next_token1;
		std::string str_obj(s);
		char_s = &str_obj[0];

		ptr = strtok_s(char_s, ",", &next_token1);
		int i = 0;
		while (ptr != NULL)
		{
			if (i == 0)
				x_ = std::stof(ptr);
			else if (i == 1)
				y_ = std::stof(ptr);
			else if (i == 2)
				z_ = std::stof(ptr);
			ptr = strtok_s(NULL, ",", &next_token1);
			i++;
		}	  
	}

	~Vector3D() {}

	// various getters
	inline float getX() const {
		return x_;
	}

	inline float getY() const {
		return y_;
	}

	inline float getZ() const {
		return z_;
	}

	// various setters
	inline void setX(float x) {
		x_ = x;
	}

	inline void setY(float y) {
		y_ = y;
	}

	inline void setZ(float z) {
		z_ = z;
	}

	inline void set(float x, float y, float z) {
		x_ = x;
		y_ = y;
		z_ = z;
	}

	inline void set(const Vector3D& v) {
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
	}

	inline void set(const Vector3D&& v) {
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
	}

	inline void set(const Vector3D* v) {
		x_ = v->x_;
		y_ = v->y_;
		z_ = v->z_;
	}

	// copy assignment
	inline Vector3D& operator=(const Vector3D& v) {
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
		return *this;
	}

	// move assignment - not really needed
	inline Vector3D& operator=(const Vector3D&& v) {
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
		return *this;
	}

	inline Vector3D& operator+=(const Vector3D&& v) {
		x_ += v.x_;
		y_ += v.y_;
		z_ += v.z_;
		return *this;
	}

	inline Vector3D& operator+(const Vector3D& v) {
		x_ += v.x_;
		y_ += v.y_;
		z_ += v.z_;
		return *this;
	}

	inline Vector3D& operator+=(const Vector3D& v) {
		x_ += v.x_;
		y_ += v.y_;
		z_ += v.z_;
		return *this;
	}

	inline bool operator==(const Vector3D& v) {

		return (x_ == v.x_ &&
			y_ == v.y_ &&
			z_ == v.z_);
	}
	inline bool operator!=(const Vector3D& v) {

		return !(x_ == v.x_ &&
			y_ == v.y_ &&
			z_ == v.z_);
	}
	// ** various operations

	// length of the vector
	inline float magnitude() const {
		return sqrtf(powf(x_, 2) + powf(y_, 2) + powf(z_, 2));
	}

	// vector in the same direction of length 1
	inline Vector3D normalize() const {
		return *this / magnitude();
	}

	// vector subtraction
	inline Vector3D operator-(const Vector3D& v) const {
		return Vector3D(x_ - v.x_, y_ - v.y_, z_ - v.z_);
	}

	// vector addition
	inline Vector3D operator+(const Vector3D& v) const {
		return Vector3D(x_ + v.x_, y_ + v.y_, z_ + v.z_);
	}

	// multiplication by constant (scaling)
	inline Vector3D operator*(float d) const {
		return Vector3D(x_ * d, y_ * d, z_ * d);
	}

	// division by constant (scaling)
	inline Vector3D operator/(float d) const {
		return Vector3D(x_ / d, y_ / d, z_ / d);
	}

	// scalar multiplication
	inline float operator *(const Vector3D& d) const {
		return d.x_ * x_ + d.y_ * y_ + d.z_ * z_;
	}


private:
	float x_;  // first coordinate
	float y_;  // second coordinate
	float z_;
};


/*
// needed for printing a value of tyep Vector2D with std::cout.
// The definition is in .cpp
std::ostream& operator<<(std::ostream& os, const Vector2D& v);
*/

/*
// counter clockwise rotation in a normal coordinate system, and
// it is clockwise rotation if we work with a coordinate system
// in which the vertical axe is flipped (it is like a mirror over
// the horizontal axe)-- which the case when working with the SDL.
//
Vector2D rotate(float degrees) const;

// Computes the angle between 'this' and 'v'. The result is
// between -180 and 180, and is such that the following holds:
//
//   this->rotate(angle) == v
//
float angle(const Vector2D& v) const;

*/