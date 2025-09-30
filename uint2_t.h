#pragma once
#include <cstdint>

namespace sti {
	class uint2_t {
		uint8_t val_;
	public:
		uint2_t() : val_(0) {}

		uint2_t(const uint8_t& base);
		
		operator int() const { return val_;}

		uint2_t operator+(const uint2_t& other) const;
		uint2_t operator-(const uint2_t& other) const;
		uint2_t operator*(const uint2_t& other) const;
		uint2_t operator/(const uint2_t& other) const;
		uint2_t operator==(const uint2_t& other) const;
		uint2_t operator==(const int& other) const;
		uint2_t operator!=(const uint2_t& other) const;
	};
}
