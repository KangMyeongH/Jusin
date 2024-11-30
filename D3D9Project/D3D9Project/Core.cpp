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
	// ImGui ������ �ʱ�ȭ �� UI �ۼ�
	m_ImGui_Manager->Create_Frame();

	// 1. DirectX �ʱ�ȭ
	m_D3D9_Manager->RenderBegin();

	// DirectX ��ο� �۾�
	m_D3D9_Manager->Render();

	// ImGui ������
	m_ImGui_Manager->GUI_Render();

	// DirectX ������ ���� �� ������ ���
	// Device Ŭ������ RenderEnd()�� �����.
	m_ImGui_Manager->GUI_Render_End(hWnd);
}