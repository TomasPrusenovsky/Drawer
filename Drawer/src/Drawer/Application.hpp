#pragma once

#include "Events/Event.hpp"
#include "Window.hpp"

namespace Drawer
{
	class DRAWER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

