#pragma once

#include "Core.hpp"

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

