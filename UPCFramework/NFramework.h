#pragma once

#include <SDL/SDL.h>
#include <functional>
#include "NWindow.h"
#include "NContentManagment.h"
#include "NShaderManagment.h"
#include "NCameraManagment.h"
#include "NBaseCamera.h"
#include "FatalError.h"

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

enum NEnumFrameworkState {
	Running,
	Exit
};

class NFramework
{
public:
	static NFramework* GET_FRAMEWORK();

	NFramework();
	~NFramework();
	
	NContentManagment* GetContentManagment() { return &mContentManagment; }
	NShaderManagment* GetShaderManagment() { return &mShaderManagment; }
	NCameraManagment* GetCameraManagment() { return &mCameraManagment; }

	NWindow* GetWindow() { return &mWindow; }

	void Initialize(const std::string windowName, int screenWidth,
		int screenHeight, unsigned int windowFlags);

	void SetFrameworkState(NEnumFrameworkState state) { mFrameworkState = state; }
	void OnInput(std::function<void(SDL_Event)> onInput) { mOnInput = onInput; }

	void DoGameLoop(std::function<void(float)> onUpdate, 
		std::function<void(float)> onDraw);
	void Update(float dt);
	void Draw(float dt);

private:
	static NFramework* M_FRAMEWORK;

	NEnumFrameworkState mFrameworkState;

	NWindow mWindow;
	NShaderManagment mShaderManagment;
	NContentManagment mContentManagment;
	NCameraManagment mCameraManagment;

	std::function<void(SDL_Event)> mOnInput;
	std::function<void(float)> mOnUpdate;
	std::function<void(float)> mOnDraw;

	float ComputeDeltaTime();
	void OnListenInputFromWindow(SDL_Event evnt);
};

