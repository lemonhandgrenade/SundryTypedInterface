#pragma once

#include <unordered_map>
#include "dink.h"

namespace sti {
	template<typename T>
	class dinked_bist {
		std::unordered_map<size_t, dink<T>> dinks;
		dink<T> cur;
	public:
		dinked_bist(std::vector<dink<T>> list) {
			for (size_t i = 0; i < list.size(); ++i) {
				if (i == 0) cur = list[0];
				dinks.insert(std::pair<size_t, dink<T>>(list[i].hash(), list[i]));
			}
		}

		dink<T> getCurrent() {
			return cur;
		}

		dink<T> start() {
			if (dinks.size() <= 0) return NULL;
			cur = dinks[0];
			return cur;
		}

		dink<T> next() {
			if (cur == NULL) return NULL;
			
			auto it = dinks.find(cur.nextHash());
			if (it == dinks.end()) return NULL;
			cur = it->second;
			return cur;
		}
	};
}