#pragma once
#include <initializer_list>
#include <stdexcept>
#include <vector>
#include <any>

namespace sti {
	class unkempt_data {
		std::vector<std::any> data_;
	public:
		unkempt_data(std::initializer_list<std::any> data) {
			data_.resize(data.size());
			for (std::any d : data) {
				data_.push_back(d);
			}
		}

		template <typename T>
		T get(const size_t i) {
			if (i > data_.size() - 1) throw std::range_error("Integer Out Of Range");
			if (data_[i].type() != typeid(T)) throw std::logic_error("Incorrect Type");
			return std::any_cast<T>(data_[i]);
		}
	};
}

