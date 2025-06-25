#pragma once

#ifdef PADO_PLATFORM_WINDOWS

extern Pado::Application* Pado::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pado::CreateApplication();
	app->Run();
	delete app;
}

#endif