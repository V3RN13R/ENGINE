#pragma once

// components -- forward declaration, i.e., assume they are defined somewhere
class Transform;
class Vector3D;
class TESTComponente1;
class TESTComponente2;
class MeshRenderer;
class Rigidbody;
#define _CMPS_LIST_  \
	Transform,\
	Vector3D,\
	TESTComponente1,\
	TESTComponente2,\
	MeshRenderer,\
	Rigidbody


// groups
struct  Grupo1;
#define _GRPS_LIST_   Grupo1

// handlers
struct Handler1;
#define _HDLRS_LIST_ Handler1
