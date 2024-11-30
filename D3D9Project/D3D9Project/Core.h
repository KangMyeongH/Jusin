#pragma once
class Device;
class ImGuiManager;
class Core
{
	DECLARE_SINGLETON(Core)

private:
	Core();
	~Core();

public:
	void 	Initialize(HWND hWnd);
	void 	Update();
	void 	LateUpdate();
	void 	Render(HWND hWnd);


private:
	Device* 		m_D3D9_Manager;
	ImGuiManager* 	m_ImGui_Manager;
};

