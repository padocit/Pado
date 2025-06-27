#include "padopch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Pado {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PADO_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PADO_TRACE(e);
		}

		while (true);
	}

}
