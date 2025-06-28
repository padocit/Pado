#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Pado {

	class PADO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

