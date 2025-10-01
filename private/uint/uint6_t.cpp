#include "uint/uint6_t.h"

using namespace sti;

uint6_t::uint6_t(const uint8_t& base) {
	if (base > 63) val_ = 63;
	else val_ = base;
}

uint6_t uint6_t::operator+(const uint6_t& other) const { return uint6_t(val_ + other.val_ & 0x3f); }
uint6_t uint6_t::operator-(const uint6_t& other) const { return uint6_t(val_ - other.val_ & 0x3f); }
uint6_t uint6_t::operator*(const uint6_t& other) const { return uint6_t(val_ * other.val_ & 0x3f); }

uint6_t uint6_t::operator/(const uint6_t& other) const  {
	if (other.val_ == 0) return uint6_t(63);
	return uint6_t(val_ / other.val_ & 0x3f);
}

bool uint6_t::operator==(const uint6_t& other) const	{ return val_ == other.val_;	}
bool uint6_t::operator==(const int& other) const		{ return val_ == other;		}
bool uint6_t::operator!=(const uint6_t& other) const	{ return val_ != other.val_;	}