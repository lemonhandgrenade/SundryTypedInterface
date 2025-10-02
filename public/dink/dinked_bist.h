#pragma once

#include <unordered_map>
#include "dink.h"

namespace sti {
	template<typename T>
	class dinked_bist {
		std::unordered_map<size_t, dink<T>> dinks_;
		dink<T> cur_;
	public:
		explicit dinked_bist(std::vector<dink<T>> list) {
			for (size_t i = 0; i < list.size(); ++i) {
				if (i == 0) cur_ = list[0];
				dinks_.insert(std::pair<size_t, dink<T>>(list[i].hash(), list[i]));
			}
		}

		dink<T> get_current() {
			return cur_;
		}

		dink<T> start() {
			if (dinks_.empty()) return NULL;
			cur_ = dinks_[0];
			return cur_;
		}

		dink<T> next() {
			if (cur_ == NULL) return NULL;
			auto it = dinks_.find(cur_.next_hash());
			if (it == dinks_.end()) return NULL;
			cur_ = it->second;
			return cur_;
		}
	};
}