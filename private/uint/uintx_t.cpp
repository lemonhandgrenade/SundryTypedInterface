#include "uint/uintx_t.h"
using namespace sti;


uintx_t& uintx_t::operator=(const uint8_t& v) {
	ensure_size(v);
	set_vals(v);
	return *this;
}

uintx_t& uintx_t::operator=(const int v) {
	const unsigned long long raw = static_cast<unsigned long long>(v);
	ensure_size(raw);
	set_vals(raw);
	return *this;
}

bool uintx_t::operator==(const uintx_t& other) const {
	return vals_ == other.vals_;
}

bool uintx_t::operator==(const int& other) const {
	unsigned long long v = to_int();
	return v == static_cast<unsigned long long>(other);
}

uintx_t uintx_t::operator+(const uintx_t& other) const {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for addition.");
	unsigned long long result = this->to_int() + other.to_int();
	uintx_t sum(bits_);
	sum.set_vals(result);
	return sum;
}

void uintx_t::operator+=(const uintx_t& other) {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for addition.");
	unsigned long long result = this->to_int() + other.to_int();
	this->set_vals(result);
}

uintx_t uintx_t::operator-(const uintx_t& other) const {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for subtraction.");
	unsigned long long result = this->to_int() - other.to_int();
	uintx_t diff(bits_);
	diff.set_vals(result);
	return diff;
}

void uintx_t::operator-=(const uintx_t& other) {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for subtraction.");
	unsigned long long result = this->to_int() - other.to_int();
	this->set_vals(result);
}

uintx_t uintx_t::operator*(const uintx_t& other) const {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for multiplication.");
	const unsigned long long result = this->to_int() * other.to_int();
	uintx_t prod(bits_);
	prod.set_vals(result);
	return prod;
}

void uintx_t::operator*=(const uintx_t& other) {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for multiplication.");
	const unsigned long long result = this->to_int() * other.to_int();
	uintx_t prod(bits_);
	this->set_vals(result);
}

uintx_t uintx_t::operator/(const uintx_t& other) const {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for division.");
	unsigned long long divisor = other.to_int();
	if (divisor == 0) throw std::invalid_argument("Division by zero.");
	unsigned long long result = this->to_int() / divisor;
	uintx_t quot(bits_);
	quot.set_vals(result);
	return quot;
}

void uintx_t::operator/=(const uintx_t& other) {
	if (other.bits_ != this->bits_) throw std::invalid_argument("Bit sizes must match for division.");
	unsigned long long divisor = other.to_int();
	if (divisor == 0) throw std::invalid_argument("Division by zero.");
	unsigned long long result = this->to_int() / divisor;
	this->set_vals(result);
}

uintx_t uintx_t::operator+(const int& other) const {
	const unsigned long long result = this->to_int() + other;
	uintx_t res(bits_);
	res.set_vals(result);
	return res;
}

void uintx_t::operator+=(const int& other) {
	const unsigned long long result = this->to_int() + other;
	this->set_vals(result);
}

uintx_t uintx_t::operator-(const int& other) const {
	const unsigned long long result = this->to_int() - other;
	uintx_t res(bits_);
	res.set_vals(result);
	return res;
}

void uintx_t::operator-=(const int& other){
	const unsigned long long result = this->to_int() - other;
	this->set_vals(result);
}

uintx_t uintx_t::operator*(const int& other) const {
	const unsigned long long result = this->to_int() * other;
	uintx_t res(bits_);
	res.set_vals(result);
	return res;
}

void uintx_t::operator*=(const int& other) {
	const unsigned long long result = this->to_int() * other;
	this->set_vals(result);
}

uintx_t uintx_t::operator/(const int& other) const {
	if (other == 0) throw std::invalid_argument("Division By Zero.");
	const unsigned long long result = this->to_int() / other;
	uintx_t res(bits_);
	res.set_vals(result);
	return res;
}

void uintx_t::operator/=(const int& other) {
	if (other == 0) throw std::invalid_argument("Division By Zero.");
	const unsigned long long result = this->to_int() / other;
	this->set_vals(result);
}
