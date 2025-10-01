#include "uint/uint4_t.h"

using namespace sti;

uint4_t::uint4_t(const uint8_t& base) {
	if (base > 15) val_ = 15;
	else val_ = base;
}

uint4_t uint4_t::operator+(const uint4_t& other) const { return uint4_t(val_ + other.val_ & 0x0f); }
uint4_t uint4_t::operator-(const uint4_t& other) const { return uint4_t(val_ - other.val_ & 0x0f); }
uint4_t uint4_t::operator*(const uint4_t& other) const { return uint4_t(val_ * other.val_ & 0x0f); }

uint4_t uint4_t::operator/(const uint4_t& other) const  {
	if (other.val_ == 0) return uint4_t(15);
	return uint4_t(val_ / other.val_ & 0x0f);
}

bool uint4_t::operator==(const uint4_t& other) const	{ return val_ == other.val_;	}
bool uint4_t::operator==(const int& other) const		{ return val_ == other;		}
bool uint4_t::operator!=(const uint4_t& other) const	{ return val_ != other.val_;	}