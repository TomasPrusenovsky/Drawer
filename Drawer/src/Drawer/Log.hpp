#pragma once

#include <memory>

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Drawer
{
	class DRAWER_API Log
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

// Core LOG macros
#define DW_CORE_TRACE(...)    ::Drawer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DW_CORE_INFO(...)     ::Drawer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DW_CORE_WARN(...)     ::Drawer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DW_CORE_ERROR(...)    ::Drawer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DW_CORE_FATAL(...)    ::Drawer::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client LOG macros
#define DW_TRACE(...)         ::Drawer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DW_INFO(...)          ::Drawer::Log::GetClientLogger()->info(__VA_ARGS__)
#define DW_WARN(...)          ::Drawer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DW_ERROR(...)         ::Drawer::Log::GetClientLogger()->error(__VA_ARGS__)
#define DW_FATAL(...)         ::Drawer::Log::GetClientLogger()->fatal(__VA_ARGS__)


