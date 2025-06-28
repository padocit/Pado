#include "padopch.h"
#include "WindowsWindow.h"

namespace Pado {

	// UTF-8 std::string �� UTF-16 std::wstring ��ȯ
	static std::wstring StringToWide(const std::string& str) {
		int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
		std::wstring wstr;
		wstr.resize(size);
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size);
		return wstr;
	}

	static bool s_win32Initialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		PADO_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);
	
		if (!s_win32Initialized)
		{
			// TODO: win32Terminate on system shutdown
			WNDCLASSEX wc = { sizeof(WNDCLASSEX),
							 CS_CLASSDC,
							 WindowsWindow::WndProc,
							 0L,
							 0L,
							 GetModuleHandle(NULL),
							 NULL,
							 NULL,
							 NULL,
							 NULL,
							 L"PadoWindowClass", // lpszClassName, L-string
							 NULL };

			int success = RegisterClassEx(&wc);
			PADO_CORE_ASSERT(success, "Could not initialize Win32 Class!");
			s_win32Initialized = true;
		}

		RECT wr = { 0, 0, m_data.width, m_data.height };
		AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

		std::wstring wtitle = StringToWide(m_data.title);
		HINSTANCE hInstance = GetModuleHandle(nullptr);
		m_window =
			CreateWindow(L"PadoWindowClass", wtitle.c_str(), WS_OVERLAPPEDWINDOW,
				100,                // Window upper-left X
				100,                // Window upper-left Y
				wr.right - wr.left, // Window width
				wr.bottom - wr.top, // Window height
				NULL, NULL, hInstance, NULL);

		PADO_CORE_ASSERT(m_window, "Could not initialize Win32 Window!");

		SetWindowLongPtr(m_window, GWLP_USERDATA, (LONG_PTR)&m_data);
		ShowWindow(m_window, SW_SHOWDEFAULT);
		UpdateWindow(m_window);

		//TODO:
		// ===== DirectX �ʱ�ȭ �ڸ� ǥ�� =====
	    // ���⼭ m_window�� �̿��� DirectX ����̽��� ����ü�� ���� �ڵ带 �ۼ�
	    // ��: DXGI_SWAP_CHAIN_DESC ���� �� D3D11CreateDeviceAndSwapChain(..., OutputWindow = m_Window, ...)
		
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		//TODO:
		// ===== DirectX ���� �ڸ� ǥ�� =====
		// DirectX ���ҽ�(����ü��, ����̽�, ���ؽ�Ʈ) ���� �ڵ带 ���⿡.

		DestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate()
	{
		// Win32 �޽��� ó��
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//TODO:
		// ===== DirectX ������ ǥ�� =====
		// swapChain->Present(1, 0);

		//SwapBuffers(m_hdc);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		m_data.vSync = enabled;

		//TODO: 
		// DirectX������ Present ȣ�� �� ���ڷ� sync interval�� �ָ� �˴ϴ�.
		// ��: swapChain->Present(enabled ? 1 : 0, 0);
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_data.vSync;
	}

	LRESULT CALLBACK WindowsWindow::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		auto data = reinterpret_cast<WindowData*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		//case WM_SIZE:
		//	data->width = LOWORD(lParam);
		//	data->height = HIWORD(lParam);
		//	WindowResizeEvent event(data->width, data->height);
		//	data->eventCallback(event);
		//	break;

		//case WM_CLOSE:
		//	WindowCloseEvent event;
		//	data->eventCallback(event);
		//	break;

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}
} // namespace Pado
