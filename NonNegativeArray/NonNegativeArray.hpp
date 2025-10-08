#ifndef NON_NEGATIVE_ARRAY_HPP
#define NON_NEGATIVE_ARRAY_HPP

// This file contains the class definition that you must follow when implementing
// you assignment. Each of the functions defined within the NonNegativeArray
// class below must be implemented within the file `NonNegativeArray.cpp`.

#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <numeric>

#include <cmath>
#include <functional>
#include <unordered_set>
#include <utility>
#include <vector>

constexpr int MAX_CAPACITY{ 100 };
constexpr double INITIAL_VAL{ -1.0 };

namespace MTRN2500 {
	class NonNegativeArray {
	public:
		// ================================================================
		// ========================= Constructors =========================
		// ================================================================
		NonNegativeArray();
		NonNegativeArray(int size);
		NonNegativeArray(int size, double value);
		NonNegativeArray(std::initializer_list<double> a);
		NonNegativeArray(const NonNegativeArray& a);
		NonNegativeArray(NonNegativeArray&& a);

		// ================================================================
		// ========================== Destructor ==========================
		// ================================================================
		~NonNegativeArray();

		// ================================================================
		// =========================== Operators ==========================
		// ================================================================
		double operator[](int idx) const;
		NonNegativeArray& operator+=(const NonNegativeArray& a);
		NonNegativeArray& operator-=(const NonNegativeArray& a);
		NonNegativeArray& operator*=(double val);
		NonNegativeArray& operator/=(double val);

		// ================================================================
		// ======================= Friend Functions =======================
		// ================================================================
		friend bool operator==(const NonNegativeArray& a1, const NonNegativeArray& a2);
		friend bool operator!=(const NonNegativeArray& a1, const NonNegativeArray& a2);
		friend NonNegativeArray operator+(const NonNegativeArray& a1, const NonNegativeArray& a2);
		friend NonNegativeArray operator-(const NonNegativeArray& a1, const NonNegativeArray& a2);
		friend std::ostream& operator<<(std::ostream& stream, const NonNegativeArray& a);

		// ================================================================
		// ======================= Member Functions =======================
		// ================================================================
		double at(int idx) const;
		double front() const;
		double back() const;
		void pushFront(double val);
		void pushBack(double val);
		bool empty() const;
		int size() const;
		int maxSize() const;
		void set(int n, double val);
		void fill(double val);
		void fillN(double val, int n);
		void clear();
		void swap(NonNegativeArray& a);
		void reverse();
		void distinct();
		double dotProduct(const NonNegativeArray& a);

	private:
		// ================================================================
		// ========================= Class Members ========================
		// ================================================================
		int mCapacity{};
		// Use one of the following data types for your NonNegativeArray
		// You MUST choose one of these two options
		std::unique_ptr<double[]> mValues{};
		// double* mValues{};
		

		// Add any additional helper functions or data members as required
		friend bool isDoubleSame(const double a, const double b);
	};
}

#endif // NON_NEGATIVE_ARRAY_HPP