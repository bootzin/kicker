#pragma once

#include <memory>

#ifdef KCK_DEBUG
	#define KCK_ENABLE_ASSERT
#endif

#ifdef KCK_ENABLE_ASSERT
	#define KCK_ASSERT(x, ...) { if (!(x)) KCK_ERROR("Assertion Failed: {0}", __VA_ARGS__) }
#else
	#define KCK_ASSERT(x, ...)
#endif

namespace  Kicker {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	// Define floating point precision for Kicker
	typedef float real;
}