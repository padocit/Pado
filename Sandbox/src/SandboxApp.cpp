#include <Pado.h>

class ExampleLayer : public Pado::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		PADO_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pado::Event& event) override
	{
		PADO_TRACE("{0}", event);
	}
};

class Sandbox : public Pado::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};

Pado::Application* Pado::CreateApplication()
{
	return new Sandbox();
}