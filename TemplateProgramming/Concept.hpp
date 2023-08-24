#pragma once
#include <concepts>

template <typename T>
concept C = sizeof(T) == 4;

template <typename T>
concept Incrementable = requires(T x) { x++; ++x; };

template <typename T>
concept C2 = requires (T x, T y) {
	{x.swap(y)} noexcept;
};

template <typename T>
concept C3 = requires (const T x) {
	{ x.size() } -> std::convertible_to<size_t>
};


template <typename T>
concept Comparable = requires(const T a, const T b) {
	{a == b} -> std::convertible_to<bool>;
	{a < b} -> std::convertible_to<bool>;
};

template <typename T>
concept C4 = requires (T t) {
	requires sizeof(t) == 4;
++t; --t, t++, t--;
};

