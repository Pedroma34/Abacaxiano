#include <cstdint>
#include <memory>
#include <SFML/System/Vector2.hpp>

namespace abx{

	// Alias for types
	using int8 = std::int8_t;
	using int16 = std::int16_t;
	using int32 = std::int32_t;
	using int64 = std::int64_t;
	using uint8 = std::uint8_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
	using uint = std::uint32_t;
	using char8 = char;
	using char16 = char16_t;
	using char32 = char32_t;

	//Memory
	template <typename T>
	using Ref = std::shared_ptr<T>;
	template <typename T>
	using WeakRef = std::weak_ptr<T>;
	template <typename T>
	using Unique = std::unique_ptr<T>;

	template <typename T, typename... Args>
	auto MakeRef(Args&&... args) { return std::make_shared<T>(std::forward<Args>(args)...); }
	template <typename T, typename... Args>
	auto MakeUnique(Args&&... args) { return std::make_unique<T>(std::forward<Args>(args)...); }

	// SFML
	using Vector2u = sf::Vector2<uint64>;
	using Vector2i = sf::Vector2<int64>;
	using Vector2f = sf::Vector2<float>;
	using Vector2d = sf::Vector2<double>;

} 