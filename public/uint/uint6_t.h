#pragma once
#include <cstdint>

namespace sti {
	class uint6_t {
		uint8_t val_;
	public:
		uint6_t() : val_(0) {}

		uint6_t(const uint8_t& base);
		
		operator int() const { return val_;}

		uint6_t operator+(const uint6_t& other) const;
		uint6_t operator-(const uint6_t& other) const;
		uint6_t operator*(const uint6_t& other) const;
		uint6_t operator/(const uint6_t& other) const;
		bool operator==(const uint6_t& other) const;
		bool operator==(const int& other) const;
		bool operator!=(const uint6_t& other) const;
	};
}
