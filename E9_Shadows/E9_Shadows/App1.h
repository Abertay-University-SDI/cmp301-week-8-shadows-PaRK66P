// Application.h
#ifndef _APP1_H
#define _APP1_H

// Includes
#include "DXF.h"	// include dxframework
#include "TextureShader.h"
#include "ShadowShader.h"
#include "DepthShader.h"

class App1 : public BaseApplication
{
public:

	App1();
	~App1();
	void init(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight, Input* in, bool VSYNC, bool FULL_SCREEN);

	bool frame();

protected:
	bool render();
	void depthPass();
	void finalPass();
	void gui();

	void firstPass();

private:
	TextureShader* textureShader;
	PlaneMesh* mesh;

	Light* light;
	AModel* model;
	ShadowShader* shadowShader;
	DepthShader* depthShader;

	ShadowMap* shadowMap;

	CubeMesh* cube;
	SphereMesh* sphere;

	float position = -5;
	float positionModifier = 0.01;
	float rotation = 0;

	OrthoMesh* shadowMapReader;
	RenderTexture* shadowRenderTexture;
};

#endif