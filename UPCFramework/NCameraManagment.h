#pragma once

#include "NBaseCamera.h"
#include "NCamera2D.h"
#include "NCamera3D.h"

class NFramework;

class NCameraManagment
{
public:
	NCameraManagment(NFramework* framework) :
		mCurrentCamera(nullptr)
		{ mFramework = framework; }
	~NCameraManagment();

	NBaseCamera* GetCurrentCamera() { return mCurrentCamera; }
	
	NCamera2D* CreateCamera2D(int screenWidth, int screenHeight);
	NCamera3D* CreateCamera3D(int screenWidth, int screenHeight, float fov, float zNear, float zFar);

	void Initialize();
	void SetCurrentCamera(NBaseCamera* camera) { mCurrentCamera = camera; }
	void Update(float dt);

private:
	NBaseCamera* mCurrentCamera;
	NFramework* mFramework;
};

