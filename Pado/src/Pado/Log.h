#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pado {

	class PADO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PADO_CORE_TRACE(...)    ::Pado::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PADO_CORE_INFO(...)     ::Pado::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PADO_CORE_WARN(...)     ::Pado::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PADO_CORE_ERROR(...)    ::Pado::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PADO_CORE_FATAL(...)    ::Pado::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PADO_TRACE(...)         ::Pado::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PADO_INFO(...)          ::Pado::Log::GetClientLogger()->info(__VA_ARGS__)
#define PADO_WARN(...)          ::Pado::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PADO_ERROR(...)         ::Pado::Log::GetClientLogger()->error(__VA_ARGS__)
#define PADO_FATAL(...)         ::Pado::Log::GetClientLogger()->fatal(__VA_ARGS__)
