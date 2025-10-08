#include "NonNegativeArray.hpp"

// In this file you should write the implementation of each of the functions
// defined within `NonNegativeArray.hpp`

namespace MTRN2500 {
	// Helper function
	bool isDoubleSame(const double a, const double b) {
		const double epsilon{ 0.0000001 };
		return (a <= b + epsilon && a >= b - epsilon);
	}

	// Implementation
	NonNegativeArray::NonNegativeArray() : mCapacity{ MAX_CAPACITY }, mValues{ std::make_unique<double[]>(MAX_CAPACITY) } {
		std::fill(mValues.get(), mValues.get() + mCapacity, INITIAL_VAL);
	}

	NonNegativeArray::NonNegativeArray(int size) {
		if (size < 0 || size > MAX_CAPACITY) {
			throw std::exception("Array maximum size is invalid!");
		}
		mCapacity = size;
		mValues = std::make_unique<double[]>(size);
		std::fill(mValues.get(), mValues.get() + mCapacity, INITIAL_VAL);
	}

	NonNegativeArray::NonNegativeArray(int size, double value) {
		if (size < 0 || size > MAX_CAPACITY) {
			throw std::exception("Array maximum size is invalid!");
		}
		mCapacity = size;
		mValues = std::make_unique<double[]>(size);
		std::fill(mValues.get(), mValues.get() + mCapacity, value);
	}

	NonNegativeArray::NonNegativeArray(std::initializer_list<double> a) {
		if (a.size() < 0 || a.size() > MAX_CAPACITY) {
			throw std::exception("Array maximum size is invalid!");
		}
		bool flag{ false };
		for (const double& elem : a) {
			if (elem < 0.0) {
				flag = true;
			}
			if (elem >= 0.0 && flag) {
				throw std::exception("Array constructed is invalid!");
			}
		}
		mCapacity = static_cast<int>(a.size());
		mValues = std::make_unique<double[]>(a.size());
		std::copy(a.begin(), a.end(), mValues.get());
	}

	NonNegativeArray::NonNegativeArray(const NonNegativeArray& a) : mCapacity{ a.mCapacity }, mValues{std::make_unique<double[]>(a.mCapacity)} {
		std::copy(a.mValues.get(), a.mValues.get() + a.mCapacity, mValues.get());
	}

	NonNegativeArray::NonNegativeArray(NonNegativeArray&& a) : mCapacity{ std::exchange(a.mCapacity, {}) }, mValues{ std::exchange(a.mValues, {}) } {
		// Using member initializer list
	}

	NonNegativeArray::~NonNegativeArray() {
		// No codes because using smart pointers
	}

	double NonNegativeArray::operator[](int idx) const {
		return mValues[idx];
	}

	NonNegativeArray& NonNegativeArray::operator+=(const NonNegativeArray& a) {
		if (this->size() != a.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		std::transform(mValues.get(), mValues.get() + this->size(), a.mValues.get(), mValues.get(), std::plus<double>());
		return *this;
	}

	NonNegativeArray& NonNegativeArray::operator-=(const NonNegativeArray& a) {
		if (this->size() != a.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		for (int i{ 0 }; i < this->size(); ++i) {
			if (mValues[i] - a.mValues[i] < 0) {
				throw std::exception("Result contains a negative number!");
			}
		}
		std::transform(mValues.get(), mValues.get() + this->size(), a.mValues.get(), mValues.get(), std::minus<double>());
		return *this;
	}

	NonNegativeArray& NonNegativeArray::operator*=(double val) {
		if (val < 0) {
			throw std::exception("Result contains a negative number!");
		}
		std::for_each(mValues.get(), mValues.get() + this->size(), [val](double& elem) { elem *= val; });
		return *this;
	}

	NonNegativeArray& NonNegativeArray::operator/=(double val) {
		if (val < 0) {
			throw std::exception("Result contains a negative number!");
		}
		if (val == 0) {
			throw std::exception("Result cannot divide by 0!");
		}
		std::for_each(mValues.get(), mValues.get() + this->size(), [val](double& elem) { elem /= val; });
		return *this;
	}

	bool operator==(const NonNegativeArray& a1, const NonNegativeArray& a2) {
		bool flag{ true };
		for (int i{ 0 }; i < a1.size(); ++i) {
			if (!(isDoubleSame(a1.mValues[i], a2.mValues[i]))) {
				flag = false;
			}
		}
		return (a1.size() == a2.size() && a1.maxSize() == a2.maxSize() && flag);
	}

	bool operator!=(const NonNegativeArray& a1, const NonNegativeArray& a2) {
		bool flag{ false };
		for (int i{ 0 }; i < a1.size(); ++i) {
			if (!(isDoubleSame(a1.mValues[i], a2.mValues[i]))) {
				flag = true;
			}
		}
		return (a1.size() != a2.size() || a1.maxSize() != a2.maxSize() || flag);
	}

	NonNegativeArray operator+(const NonNegativeArray& a1, const NonNegativeArray& a2) {
		if (a1.size() != a2.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		int largerCapacity{ a1.maxSize() };
		if (a1.maxSize() < a2.maxSize()) {
			largerCapacity = a2.maxSize();
		}
		MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(largerCapacity) };
		std::transform(a1.mValues.get(), a1.mValues.get() + a1.size(), a2.mValues.get(), a3.mValues.get(), std::plus<double>());
		return a3;
	}

	NonNegativeArray operator-(const NonNegativeArray& a1, const NonNegativeArray& a2) {
		if (a1.size() != a2.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		for (int i{ 0 }; i < a1.size(); ++i) {
			if (a1.mValues[i] - a2.mValues[i] < 0) {
				throw std::exception("Result contains a negative number!");
			}
		}
		int largerCapacity{ a1.maxSize() };
		if (a1.maxSize() < a2.maxSize()) {
			largerCapacity = a2.maxSize();
		}
		MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(largerCapacity) };
		std::transform(a1.mValues.get(), a1.mValues.get() + a1.size(), a2.mValues.get(), a3.mValues.get(), std::minus<double>());
		return a3;
	}

	std::ostream& operator<<(std::ostream& stream, const NonNegativeArray& a) {
		stream << std::fixed << std::setprecision(2);
		stream << "{";
		for (int i{ 0 }; i < a.size(); ++i) {
			stream << round(a.mValues[i] * 100) / 100;
			if (i < a.size() - 1) {
				stream << ", ";
			}
		}
		stream << "}";
		return stream;
	}

	double NonNegativeArray::at(int idx) const {
		if (idx < 0 || idx >= this->size()) {
			throw std::exception("Index is outside the active range!");
		}
		return mValues[idx];
	}

	double NonNegativeArray::front() const {
		if (this->empty()) {
			throw std::exception("No elements in the active range!");
		}
		return mValues[0];
	}

	double NonNegativeArray::back() const {
		if (this->empty()) {
			throw std::exception("No elements in the active range!");
		}
		return mValues[this->size() - 1];
	}

	void NonNegativeArray::pushFront(double val) {
		if (this->size() == mCapacity) {
			throw std::exception("Cannot push to a full array!");
		}
		if (val < 0) {
			throw std::exception("The push value is invalid!");
		}
		const int activeSize{ this->size() };
		std::move_backward(mValues.get(), mValues.get() + activeSize, mValues.get() + activeSize + 1);
		mValues[0] = val;
	}

	void NonNegativeArray::pushBack(double val) {
		if (this->size() == mCapacity) {
			throw std::exception("Cannot push to a full array!");
		}
		if (val < 0) {
			throw std::exception("The push value is invalid!");
		}
		mValues[this->size()] = val;
	}

	bool NonNegativeArray::empty() const {
		if (this->size() > 0) {
			return false;
		}
		return true;
	}

	int NonNegativeArray::size() const {
		auto isPositive = [](const double& elem) { return elem >= 0; };
		return std::count_if(mValues.get(), mValues.get() + mCapacity, isPositive);
	}

	int NonNegativeArray::maxSize() const {
		return mCapacity;
	}

	void NonNegativeArray::set(int n, double val) {
		if (n < 0 || n >= this->size()) {
			throw std::exception("Index is outside the active range!");
		}
		if (val < 0) {
			throw std::exception("The set value is invalid!");
		}
		mValues[n] = val;
	}

	void NonNegativeArray::fill(double val) {
		std::fill(mValues.get(), mValues.get() + mCapacity, val);
	}

	void NonNegativeArray::fillN(double val, int n) {
		if (n < 0 || n > mCapacity) {
			throw std::exception("Index is outside the maximum range!");
		}
		if (val < 0) {
			throw std::exception("The fill value is invalid!");
		}
		std::fill(mValues.get(), mValues.get() + n, val);
	}

	void NonNegativeArray::clear() {
		std::fill(mValues.get(), mValues.get() + mCapacity, INITIAL_VAL);
	}

	void NonNegativeArray::swap(NonNegativeArray& a) {
		if (this->size() != a.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		std::swap_ranges(mValues.get(), mValues.get() + this->size(), a.mValues.get());
	}

	void NonNegativeArray::reverse() {
		std::reverse(mValues.get(), mValues.get() + this->size());
	}

	void NonNegativeArray::distinct() {	
		const int activeSize{ this->size() };
		std::unordered_set<double> elemSet{};
		std::for_each(mValues.get(), mValues.get() + activeSize, [&](const double& elem){ elemSet.insert(elem); });
		std::copy(elemSet.begin(), elemSet.end(), mValues.get());
		std::fill(mValues.get() + elemSet.size(), mValues.get() + activeSize, INITIAL_VAL);
	}

	double NonNegativeArray::dotProduct(const NonNegativeArray& a) {
		if (this->size() != a.size()) {
			throw std::exception("Arrays active sizes do not match!");
		}
		double result{ 0 };
		for (int i{ 0 }; i < a.size(); ++i) {
			result += mValues[i] * a.mValues[i];
		}
		return result;
	}
	
};