#pragma once

#ifdef DW_PLATFORM_WINDOWS

extern Drawer::Application* Drawer::CreateApplication();

int main(int argc, char** argv)
{
	Drawer::Log::Init();
	DW_CORE_INFO("Info Message");
	int testVar = 0;
	DW_ERROR("Error Message");
	DW_INFO("My varieble : {0}", testVar);

	auto app = Drawer::CreateApplication();
	app->Run();
	delete app;
}
#endif