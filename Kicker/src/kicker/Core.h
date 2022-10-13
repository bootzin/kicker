#pragma once

#include <memory>
#include <float.h>

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

#if 1
	#define SINGLE_PRECISION
	#define REAL_MAX FLT_MAX
	#define real_epsilon FLT_EPSILON
	#define R_PI 3.14159f
	// Define floating point precision for Kicker
	typedef float real;
#else
	#define DOUBLE_PRECISION
	#define REAL_MAX DBL_MAX
	#define real_epsilon DBL_EPSILON
	#define R_PI 3.14159265358979
	// Define floating point precision for Kicker
	typedef double real;
#endif

}
