#pragma once

class ImGuiManager
{
	DECLARE_SINGLETON(ImGuiManager)

private:
	ImGuiManager();
	~ImGuiManager();

public:
	void Initialize(HWND hWnd);
	void Create_Frame();
	void GUI_Render();
	void GUI_Render_End(HWND hWnd);


private:
	ImVec4 clear_color;
	bool show_demo_window;
	bool show_another_window;
};

