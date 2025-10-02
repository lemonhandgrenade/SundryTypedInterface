#pragma once
#include <initializer_list>
#include <stdexcept>
#include <vector>
#include <any>

namespace sti {
	class unkempt_data {
		std::vector<std::any> data_;
	public:
		unkempt_data(const std::initializer_list<std::any>& data) : data_(data) {}

		template <typename T>
		T get(const size_t i) {
			if (i > data_.size() - 1) throw std::range_error("Integer Out Of Range");
			if (data_[i].type() != typeid(T)) throw std::logic_error("Incorrect Type");
			return std::any_cast<T>(data_.at(i));
		}
		std::any get_raw(const size_t i) {
			if (i > data_.size() - 1) throw std::range_error("Integer Out Of Range");
			return data_[i];
		}

		std::vector<std::any>::iterator begin() { return data_.begin(); }
		[[nodiscard]] std::vector<std::any>::const_iterator begin() const { return data_.begin(); }
		std::vector<std::any>::iterator end() { return data_.end(); }
		[[nodiscard]] std::vector<std::any>::const_iterator end() const { return data_.end(); }
	};
}

