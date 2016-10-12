#pragma once

#include "NBaseCamera.h"

class NCamera3D : public NBaseCamera
{
public:
	NCamera3D() { NBaseCamera::NBaseCamera(); }
	~NCamera3D() { NBaseCamera::~NBaseCamera(); }

	void Initialize(int screenWidth, int screenHeight);
	void Initialize(int screenWidth, int screenHeight, float fov, float zNear, float zFar);
	void Update(float dt);

private:
	glm::vec3 mCameraPosition;
};

