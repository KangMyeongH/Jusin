#pragma once
#include "Define.h"

class Device
{
	DECLARE_SINGLETON(Device)

private:
	Device();
	~Device();

public:
	D3DPRESENT_PARAMETERS* GetD3DPP() { return &mD3dpp; }
	LPDIRECT3DDEVICE9		GetDevice() const { return mDevice; }
	//LPD3DXSPRITE			GetSprite() const { return mSprite; }
	//LPD3DXFONT				GetFont() const { return mFont; }

public:
	HRESULT		InitDevice(HWND hwnd);
	HRESULT		ResetD3DPP();
	bool		IsDeviceLost() const;
	void		RenderBegin();
	void		RenderEnd(HWND hWnd = nullptr);
	void		Render();
	void		Release();

	void		DrawPolygon();

private:
	void		SetParameters(D3DPRESENT_PARAMETERS& d3dpp, HWND hwnd);

private:
	D3DPRESENT_PARAMETERS	mD3dpp;
	LPDIRECT3D9			mSDK;
	LPDIRECT3DDEVICE9	mDevice;
	//LPD3DXSPRITE		mSprite;
	//LPD3DXFONT			mFont;
	IDirect3DVertexBuffer9* mVertexBuffer;
};

