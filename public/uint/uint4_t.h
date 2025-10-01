#pragma once
#include <cstdint>

namespace sti {
	class uint4_t {
		uint8_t val_;
	public:
		uint4_t() : val_(0) {}

		explicit uint4_t(const uint8_t& base);
		
		explicit operator int() const { return val_;}

		uint4_t operator+(const uint4_t& other) const;
		uint4_t operator-(const uint4_t& other) const;
		uint4_t operator*(const uint4_t& other) const;
		uint4_t operator/(const uint4_t& other) const;
		bool operator==(const uint4_t& other) const;
		bool operator==(const int& other) const;
		bool operator!=(const uint4_t& other) const;
	};
}
