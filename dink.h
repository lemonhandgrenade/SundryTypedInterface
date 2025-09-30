#pragma once

namespace sti {
	template<typename T>
	struct dink {
		T data;
		size_t data_hash;

		dink(T obj) {
			data = obj;
			std::hash<T> hasher;
			data_hash = hasher(obj);
		}

		T objd() {
			return data;
		}

		size_t hash() {
			return data_hash;
		}

		friend bool operator==(const dink& a, const dink& b) {
			return &a == &b;
		}

		friend bool operator!=(const dink& a, const dink& b) {
			return !(a == b);
		}

		friend bool operator<<(const dink& a, const dink& b) {
			return &a < &b;
		}

		friend bool operator>>(const dink& a, const dink& b) {
			return &a > &b;
		}
	};
}