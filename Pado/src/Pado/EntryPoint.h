#pragma once

#ifdef PADO_PLATFORM_WINDOWS

extern Pado::Application* Pado::CreateApplication();

int main(int argc, char** argv)
{
	Pado::Log::Init();
	PADO_CORE_WARN("Initialized Log!");
	int a = 5;
	PADO_INFO("Hello! Var={0}", a);

	auto app = Pado::CreateApplication();
	app->Run();
	delete app;
}

#endif