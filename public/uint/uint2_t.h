#pragma once
#include <cstdint>

namespace sti {
	class uint2_t {
		uint8_t val_;
	public:
		uint2_t() : val_(0) {}

		explicit uint2_t(const uint8_t& base);

		explicit operator int() const { return val_;}

		uint2_t operator+(const uint2_t& other) const;
		uint2_t operator-(const uint2_t& other) const;
		uint2_t operator*(const uint2_t& other) const;
		uint2_t operator/(const uint2_t& other) const;
		bool operator==(const uint2_t& other) const;
		bool operator==(const int& other) const;
		bool operator!=(const uint2_t& other) const;
	};
}