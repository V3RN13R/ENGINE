#pragma once

class Vector3D;

class Collisions {
public:
	static bool collides( const Vector3D o1Pos, float o1Width, float o1Height, const Vector3D o2Pos, float o2Width, float o2Height);

private:
	Collisions() = delete;
};