#include "pch.h"
#include "Device.h"

IMPLEMENT_SINGLETON(Device)

Device::Device() : mD3dpp(), mSDK(nullptr), mDevice(nullptr), mVertexBuffer(nullptr)
{
}

Device::~Device()
{
	Release();
}

HRESULT Device::InitDevice(HWND hwnd)
{
	// 1. sdk 객체 생성

	mSDK = Direct3DCreate9(D3D_SDK_VERSION);

	// 2. sdk 객체를 이용하여 그래픽 카드 성능 조사

	D3DCAPS9	DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// GetDeviceCaps : 장치에 대한 지원 수준을 얻어오는 함수
	// D3DADAPTER_DEFAULT : 정보를 얻으려는 기본 그래픽 카드를 의미

	if (FAILED(mSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		//AfxMessageBox(L"GetDeviceCaps Failed");
		return E_FAIL;
	}

	// 3. 그래픽 카드 담당(제어) 객체 생성

	// 버텍스 프로세싱 = 정점의 변환 + 조명 연산
	DWORD	vp(0);

	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	ZeroMemory(&mD3dpp, sizeof(D3DPRESENT_PARAMETERS));

	SetParameters(mD3dpp, hwnd);

	// CreateDevice : 그래픽 장치를 제어할 객체를 생성
	// CreateDevice(어떤 그래픽 카드를 제어할 것인가, 어떤 정보로 장치에 접근할 것인가, 장치를 사용할 창 정보, 동작 방식, 사용 환경, 생성할 객체를 저장할 포인터)
	if (FAILED(mSDK->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		vp,
		&mD3dpp,
		&mDevice)))
	{
		//AfxMessageBox(L"CreateDevice Failed");
		return E_FAIL;
	}

	/*
	// 스프라이트 컴 객체

	if (FAILED(D3DXCreateSprite(mDevice, &mSprite)))
	{
		//AfxMessageBox(L"D3DXCreateSprite Failed");
		return E_FAIL;
	}*/

	// 폰트 컴 객체
	/*
	D3DXFONT_DESCW  tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESCW));

	tFontInfo.Height = 20;
	tFontInfo.Width = 10;
	tFontInfo.Weight = FW_HEAVY;
	tFontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, L"궁서");

	if (FAILED(D3DXCreateFontIndirect(mDevice, &tFontInfo, &mFont)))
	{
		//AfxMessageBox(L"D3DXCreateFontIndirect Failed");
		return E_FAIL;
	}*/

	mDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	DrawPolygon();

	return S_OK;
}

HRESULT Device::ResetD3DPP()
{
	HRESULT hr = mDevice->Reset(&mD3dpp);
	return hr;
}

bool Device::IsDeviceLost() const
{
	HRESULT result = mDevice->Present(nullptr, nullptr, nullptr, nullptr);
	if (result == D3DERR_DEVICELOST)
		return true;

	return false;
}

void Device::RenderBegin()
{
	mDevice->Clear(0,			// 렉트의 개수
		nullptr,	// 렉트 중 첫 번째 주소
		D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 0, 0, 255),	// 백버퍼의 색상
		1.f,  // z버퍼 초기화 값
		0);	  // 스텐실 버퍼 초기화 값

	mDevice->BeginScene();

	//mDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	//mDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	//mSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void Device::RenderEnd(HWND hWnd)
{
	//mSprite->End();
	mDevice->EndScene();
	mDevice->Present(nullptr, nullptr, hWnd, nullptr);
}

void Device::Render()
{
	mDevice->SetStreamSource(0, mVertexBuffer, 0, sizeof(CUSTOMVERTEX));
	mDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	mDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

void Device::Release()
{
	mVertexBuffer->Release();
	//mFont->Release();
	//mSprite->Release();
	mDevice->Release();
	mSDK->Release();
}

void Device::DrawPolygon()
{
	CUSTOMVERTEX vertices[] = {
		{ 0.f, 1.0f, 0.f, 0xff00ff00, }, // x, y, z, color
		{ 1.f, -1.f, 0.f, 0xff00ff00, },
		{ -1.f, -1.f, 0.f, 0xff00ff00, },
	};

	if (FAILED(mDevice->CreateVertexBuffer(sizeof(vertices), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &mVertexBuffer, nullptr)))
	{
		return;
	}

	void* pVertices;
	if (FAILED(mVertexBuffer->Lock(0, sizeof(vertices), (void**)&pVertices, 0))) 
	{
		return;
	}

	memcpy(pVertices, vertices, sizeof(vertices));
	mVertexBuffer->Unlock();
}

void Device::SetParameters(D3DPRESENT_PARAMETERS& d3dpp, HWND hwnd)
{
	d3dpp.BackBufferWidth = 1920;
	d3dpp.BackBufferHeight = 1080;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.hDeviceWindow = hwnd;

	d3dpp.Windowed = TRUE; // 창 모드(TRUE) or 전체 화면 모드(FALSE) 실행 설정

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	// 창 모드 시 모티너 재생률을 운영체제에서 관리
	// 전체화면 변경 시 , 현재 모니터 재생률을 토대로 알아서 수행
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	// 재생률과 시연 간격 설정
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}
