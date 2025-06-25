#pragma once

#include "Core.h"

namespace Pado {

	class PADO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

