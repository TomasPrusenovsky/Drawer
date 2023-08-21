#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

namespace Drawer
{
	class DRAWER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

