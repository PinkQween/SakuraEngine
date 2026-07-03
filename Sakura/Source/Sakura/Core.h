#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define SAKURA_PLATFORM_WINDOWSNT
#elif defined(__APPLE__) || defined(__MACH__)
#define SAKURA_PLATFORM_DARWIN
#elif defined(__linux__)
#define SAKURA_PLATFORM_LINUX
#endif

#ifdef SAKURA_PLATFORM_WINDOWSNT
#ifdef SAKURA_DLL
#ifdef SAKURA_BUILD_DLL
#define SAKURA_API __declspec(dllexport)
#else
#define SAKURA_API __declspec(dllimport)
#endif
#else
#define SAKURA_API
#endif
#else
#define SAKURA_API __attribute__((visibility("default")))
#endif

#define BIT(x) (1ULL << (x))


namespace Sakura {
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;

	using f32 = float;
	using f64 = double;

	using usize = size_t;
}

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual Sakura::usize GetCategoryFlags() const override { return category; }