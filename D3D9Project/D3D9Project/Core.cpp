#include "pch.h"
#include "Core.h"

#include "Device.h"
#include "ImGuiManager.h"

IMPLEMENT_SINGLETON(Core)

Core::Core(): m_D3D9_Manager(nullptr), m_ImGui_Manager(nullptr)
{
}

Core::~Core()
{
	
}

void Core::Initialize(HWND hWnd)
{
	m_D3D9_Manager = &Device::GetInstance();
	m_D3D9_Manager->InitDevice(hWnd);

	m_ImGui_Manager = &ImGuiManager::GetInstance();
	m_ImGui_Manager->Initialize(hWnd);
}

void Core::Update()
{
}

void Core::LateUpdate()
{
}

void Core::Render(HWND hWnd)
{
	// ImGui 프레임 초기화 및 UI 작성
	m_ImGui_Manager->Create_Frame();

	// 1. DirectX 초기화
	m_D3D9_Manager->RenderBegin();

	// DirectX 드로우 작업
	m_D3D9_Manager->Render();

	// ImGui 렌더링
	m_ImGui_Manager->GUI_Render();

	// DirectX 렌더링 종료 및 프레임 출력
	// Device 클래스의 RenderEnd()를 대신함.
	m_ImGui_Manager->GUI_Render_End(hWnd);
}