#include "uint2_t.h"

using namespace sti;

sti::uint2_t::uint2_t(const uint8_t& base) {
	if (base > 3) val_ = 3;
	else val_ = base;
}

sti::uint2_t sti::uint2_t::operator+(const uint2_t& other) const { return uint2_t(val_ + other.val_ & 0x03); }
sti::uint2_t sti::uint2_t::operator-(const uint2_t& other) const { return uint2_t(val_ - other.val_ & 0x03); }
sti::uint2_t sti::uint2_t::operator*(const uint2_t& other) const { return uint2_t(val_ * other.val_ & 0x03); }

sti::uint2_t sti::uint2_t::operator/(const uint2_t& other) const  {
	if (other.val_ == 0) return uint2_t(3);
	return uint2_t(val_ / other.val_ & 0x03);
}

sti::uint2_t sti::uint2_t::operator==(const uint2_t& other) const	{ return val_ == other.val_;	}
sti::uint2_t sti::uint2_t::operator==(const int& other) const		{ return val_ == other;		}
sti::uint2_t sti::uint2_t::operator!=(const uint2_t& other) const	{ return val_ != other.val_;	}
