#pragma once

#ifdef DW_PLATFORM_WINDOWS

extern Drawer::Application* Drawer::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Drawer::CreateApplication();
	app->Run();
	delete app;
}
#endif