#pragma once

#include <vector>
#include <GL/glew.h>

#include "NBaseContent.h"

class NImageContent : public NBaseContent
{
public:
	NImageContent(NContentManagment* contentManagment);
	~NImageContent();

	GLuint GetTextureID() { return mTextureID; }
	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }

	void Initialize(const std::string path);

private:
	std::vector<unsigned char> mImageData;
	int mWidth;
	int mHeight;
	GLuint mTextureID;
};

