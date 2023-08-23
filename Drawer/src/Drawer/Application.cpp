#include "dwpch.hpp"

#include "Application.hpp"

#include "Drawer/Events/ApplicationEvent.hpp"
#include "Drawer/Log.hpp"

namespace Drawer
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
			while (m_Window->IsRunning())
			{
				m_Window->OnUpdate();
			}
		if (e.IsInCategory(EventCategoryInput))
		{
			DW_TRACE(e);
		}

		while (true);
	}
}

