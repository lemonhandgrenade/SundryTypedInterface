#pragma once

namespace sti {
	template<typename T>
	class dink {
		T data;
		size_t data_hash;
		size_t next_hash;

	public:
		dink() {
			data = NULL;
			data_hash = 0;
			next_hash = 0;
		}

		dink(const T& obj) {
			data = obj;
			std::hash<T> hasher;
			data_hash = hasher(obj);
			next_hash = 0;
		}

		dink(const T& obj, dink<T> follow) {
			data = obj;
			std::hash<T> hasher;
			data_hash = hasher(obj);
			next_hash = follow.hash();
		}

		T objd() {
			return data;
		}

		size_t hash() {
			return data_hash;
		}

		size_t nextHash() {
			return next_hash;
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