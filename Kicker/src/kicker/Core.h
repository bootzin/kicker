#pragma once

#ifdef KCK_DEBUG
	#define KCK_ENABLE_ASSERT
#endif

#ifdef KCK_ENABLE_ASSERT
	#define KCK_ASSERT(x, ...) { if (!(x)) KCK_ERROR("Assertion Failed: {0}", __VA_ARGS__) }
#endif

namespace  Kicker {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}