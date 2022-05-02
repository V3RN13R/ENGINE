#include "Collisions.h"
//#include "checkML.h"


bool Collisions::collides(Vector3D o1Pos, float o1Width, float o1Height, Vector3D o2Pos, float o2Width, float o2Height) {

	// o1 completely to the left of o2, or vice versa
	if (o1Pos.getX() + o1Width < o2Pos.getX()
		|| o2Pos.getX() + o2Width < o1Pos.getX()) {
		return false;
	}

	// o1 completely to the top of o2, or vice versa
	if (o1Pos.getY() + o1Height < o2Pos.getY()
		|| o2Pos.getY() + o2Height < o1Pos.getY()) {
		return false;
	}

	return true;
}