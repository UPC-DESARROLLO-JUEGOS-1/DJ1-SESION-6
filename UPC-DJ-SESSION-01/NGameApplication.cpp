#include "NGameApplication.h"
#include <UPCFramework\NEnumWindowFlags.h>
#include <GL/glew.h>

#include <iostream>

NGameApplication::NGameApplication()
{
}

NGameApplication::~NGameApplication()
{
}

void NGameApplication::Start()
{
	// Initialize the Game
	Initialize();
}

void NGameApplication::Initialize()
{
	// Initialize Framework
	mFramework = new NFramework();
	mFramework->Initialize("UPC Framework", 800, 600, NEnumWindowFlags::Windowed);
	mFramework->OnInput(std::bind(&NGameApplication::ProcessInputs, this, std::placeholders::_1));

	NCamera3D* camera = mFramework->GetCameraManagment()->CreateCamera3D(800, 600, 3.14159265f / 4.0f, 0.01f, 100.0f);
	mFramework->GetCameraManagment()->SetCurrentCamera(camera);


	mCube.Initialize(0, 0, 0, 1.0f, 1.0f, 1.0f);
	mCube.SetZ(1.0f);
	mCube.SetRenderCamera(camera);

	//// Initialize Primitive Quad
	//mQuad.Initialize(10.0f, 200.0f, 200, 200);
	//mQuad.SetRenderCamera(mFramework->GetCamera());
	//
	//std::string imagePath = "Sprites/sonic.png";
	//std::string imageBumpPath = "Sprites/bump_map.png";
	//
	////// Initialize Sprite
	//mSprite.Initialize(100.0f, 100.0f, 200, 200, imagePath);
	//mSprite.SetRenderCamera(mFramework->GetCamera());
	//
	////// Initialize MultiSprite
	//mMultiSprite.Initialize(400.0f, 120.0f, 200, 200, imagePath, imageBumpPath);
	//mMultiSprite.SetRenderCamera(mFramework->GetCamera());
	//
	//// Initialize Primitive Circumference
	//mCircumference.Initialize(600, 120, 80, 12);
	//mCircumference.SetRenderCamera(mFramework->GetCamera());

	// Start Game Loop
	mFramework->DoGameLoop(
		std::bind(&NGameApplication::Update, this, std::placeholders::_1),
		std::bind(&NGameApplication::Draw, this, std::placeholders::_1));
}

void NGameApplication::ProcessInputs(SDL_Event evnt)
{
	
}

void NGameApplication::Update(float dt) {
	//float ro = mSprite.GetRotationZ();
	//ro += 0.01f;
	//mSprite.SetRotationZ(ro);
	//
	//mQuad.Update(dt);
	//mSprite.Update(dt);
	//mMultiSprite.Update(dt);
	//mCircumference.Update(dt);

	float x = mCube.GetRotationX();
	x += 0.01f;
	mCube.SetRotationX(x);
	mCube.SetRotationZ(x / 2.0f);

	mCube.Update(dt);
}

void NGameApplication::Draw(float dt) {
	//mQuad.Draw(dt);
	//mSprite.Draw(dt);
	//mMultiSprite.Draw(dt);
	//mCircumference.Draw(dt);

	mCube.Draw(dt);
}
