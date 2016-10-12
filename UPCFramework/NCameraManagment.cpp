#include "NCameraManagment.h"

NCameraManagment::~NCameraManagment()
{
}

NCamera2D * NCameraManagment::CreateCamera2D(int screenWidth, int screenHeight)
{
	NCamera2D* camera = new NCamera2D();
	camera->Initialize(screenWidth, screenHeight);
	return camera;
}

NCamera3D * NCameraManagment::CreateCamera3D(int screenWidth, int screenHeight, float fov, float zNear, float zFar)
{
	NCamera3D* camera = new NCamera3D();
	camera->Initialize(screenWidth, screenHeight, fov, zNear, zFar);
	return camera;
}

void NCameraManagment::Initialize()
{
}

void NCameraManagment::Update(float dt)
{
	if (mCurrentCamera != nullptr) {
		mCurrentCamera->Update(dt);
	}
}
