#pragma once
#include <stdexcept>
#include <bitset>
#include <iostream>
#include <vector>

namespace sti {
	template<typename E>
	class flag_bearer {
		std::vector<uint8_t> flags_;
		size_t bits_;

		int get_active_index(const int flag) const {
			return flags_[flag / 8];
		}
		
	public:

		flag_bearer() {
			size_t s = sizeof(int);
			flags_.resize(s, 0);
			bits_ = s;
		}

		explicit flag_bearer(const size_t& enum_count) {
			if (enum_count == 0) throw std::invalid_argument("Flag Bearer Can't Be Assigned 0 Bits");
			bits_ = enum_count;
			flags_.resize((bits_ + 7) / 8, 0);
		}
		
		void set_flag(E flag, const bool val) {
			const int f = static_cast<int>(flag);
			const int idx = f / 8;
			const int mod = f % 8;
			int act = flags_[idx];
			
			if (val)
				act |= 1 << mod;
			else
				act &= ~(1 << mod);
			
			flags_[idx] = act;
		}

		bool get_flag(E flag) const {
			const int f = static_cast<int>(flag);
			const int idx = f / 8;
			const int mod = f % 8;
			const int act = flags_[idx];

			return (act & 1 << mod) != 0;
		}

		void print() const {
			for (int i = std::size(flags_); i > 0; --i) {
				std::cout << std::bitset<8>(flags_[i-1]);
			}
		}
	};
}
