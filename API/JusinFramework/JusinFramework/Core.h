#pragma once
#include "framework.h"
#include "Resource.h"

class SceneManager;
class Core
{
private:
	Core() 								= default;
	~Core() 							= default;
public:
	Core(const Core& rhs) 				= delete;
	Core(Core&& rhs) 					= delete;
	Core& operator=(const Core& rhs) 	= delete;
	Core& operator=(Core&& rhs) 		= delete;

	static Core& GetInstance() { static Core sCore; return sCore; }
public:
	void 		Init(HWND& hwnd);
	void 		Progress();

private:
	void		start();
	void 		update();
	void 		lateUpdate();
	void 		render();

private:
	SceneManager* mSceneManager;
	HWND mHwnd;
	HDC mHdc;
};