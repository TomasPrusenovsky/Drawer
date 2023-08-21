#include "dwpch.hpp"

#include "Application.hpp"

#include "Drawer/Events/ApplicationEvent.hpp"
#include "Drawer/Log.hpp"

namespace Drawer
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		DW_TRACE(e);

		while (true);
	}
}

