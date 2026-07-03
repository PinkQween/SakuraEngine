#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sakura {
    class Logging
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

#ifdef SAKURA_PLATFORM_WINDOWSNT
#define SAKURA_BREAK() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
#define SAKURA_BREAK() __builtin_trap()
#else
#define SAKURA_BREAK()
#endif

#ifndef NDEBUG
#define SAKURA_LOGGING_ENABLED
#endif

#ifdef SAKURA_LOGGING_ENABLED
#define SAKURA_INTERNAL_INFO(...)       ::Sakura::Logging::GetCoreLogger()->info(__VA_ARGS__)
#define SAKURA_INTERNAL_WARNING(...)    ::Sakura::Logging::GetCoreLogger()->warn(__VA_ARGS__)
#define SAKURA_INTERNAL_ERROR(...)      ::Sakura::Logging::GetCoreLogger()->error(__VA_ARGS__)

#define SAKURA_INFO(...)                ::Sakura::Logging::GetClientLogger()->info(__VA_ARGS__)
#define SAKURA_WARNING(...)             ::Sakura::Logging::GetClientLogger()->warn(__VA_ARGS__)
#define SAKURA_ERROR(...)               ::Sakura::Logging::GetClientLogger()->error(__VA_ARGS__)
#else
#define SAKURA_INTERNAL_INFO(...)    do { } while(0)
#define SAKURA_INTERNAL_WARNING(...) do { } while(0)
#define SAKURA_INTERNAL_ERROR(...)   do { } while(0)

#define SAKURA_INFO(...)      do { } while(0)
#define SAKURA_WARNING(...)   do { } while(0)
#define SAKURA_ERROR(...)     do { } while(0)
#endif

// Fatal logs are always enabled
#define SAKURA_INTERNAL_FATAL(...)      ::Sakura::Logging::GetCoreLogger()->critical(__VA_ARGS__);
#define SAKURA_FATAL(...)               ::Sakura::Logging::GetClientLogger()->critical(__VA_ARGS__);


#define SAKURA_ASSERT(x, ...) { if(!(x)) { SAKURA_FATAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SAKURA_INTERNAL_ASSERT(x, ...) { if(!(x)) { SAKURA_INTERNAL_FATAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }