#include <Drawer.hpp>

class Sandbox : public Drawer::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{

	}
};

Drawer::Application* Drawer::CreateApplication()
{
	return new Sandbox();
}