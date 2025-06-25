#include <Pado.h>

class Sandbox : public Pado::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Pado::Application* Pado::CreateApplication()
{
	return new Sandbox();
}