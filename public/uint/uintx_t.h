#pragma once
#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>

namespace sti {
	class uintx_t {
		std::vector<uint8_t> vals_;
		size_t bits_;

		void ensure_size(const unsigned long long v) const {
			if (v >= 1ULL << bits_) throw std::overflow_error("Value Exceeds Bits");
		}

		void set_vals(unsigned long long v) {
			vals_.clear();
			for (size_t i = 0; i < bits_; ++i) {
				vals_.push_back(static_cast<uint8_t>(v & 1));
				v >>= 1;
			}
		}

		unsigned long long to_int() const {
			unsigned long long v = 0;
			for (size_t i = 0; i < bits_; ++i) {
				v |= static_cast<unsigned long long>(vals_[i]) << i;
			}
			return v;
		}
		
	public:
		explicit uintx_t(const size_t bits) : bits_(bits) {
			if (bits == 0) throw std::invalid_argument("Bits Must Be Greater Than 0");
			const size_t num = (bits_ + 7) / 8;
			vals_.resize(num, 0);
			std::cout << "reserved " << std::size(vals_) * sizeof(vals_[0]) << " bytes\n";
		}

		uintx_t& operator=(const uint8_t& v) {
			ensure_size(v);
			set_vals(v);
			return *this;
		}

		uintx_t& operator=(const int v) {
			const unsigned long long raw = static_cast<unsigned long long>(v);
			ensure_size(raw);
			set_vals(raw);
			return *this;
		}

		bool operator==(const uintx_t& other) const {
			return vals_ == other.vals_;
		}

		bool operator==(const int& other) const {
			unsigned long long v = to_int();
			return v == static_cast<unsigned long long>(other);
		}
		
		unsigned long long get_value() const {
			return to_int();
		}

		size_t get_bit_count() const {
			return std::size(vals_);
		}
	};
}

