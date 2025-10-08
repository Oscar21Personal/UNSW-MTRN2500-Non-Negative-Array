#include "pch.h"
#include "CppUnitTest.h"
#include "NonNegativeArray.hpp"
#include "NonNegativeArray.cpp"

#include <sstream>
#include <string>
#include <utility>

namespace MVC = Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	bool isDoubleSame(const double a, const double b) {
		const double epsilon{ 0.0000001 };
		return (a <= b + epsilon && a >= b - epsilon);
	}

	TEST_CLASS(DefaultConstructor)
	{
	public:
		TEST_METHOD(CallingConstructor1)
		{
			MTRN2500::NonNegativeArray a1;
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -1.0));
			}
		}
		TEST_METHOD(CallingConstructor2)
		{
			MTRN2500::NonNegativeArray a1{};
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -1.0));
			}
		}
		TEST_METHOD(CallingConstructor3)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray() };
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -1.0));
			}
		}
	};

	TEST_CLASS(ConstructorWithSize)
	{
	public:
		TEST_METHOD(CallingConstructor)
		{
			const int size{ 3 };
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(size) };
			for (int i{ 0 }; i < size; ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -1.0));
			}
		}
		TEST_METHOD(BoundaryCase)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(0) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(MAX_CAPACITY) };
			for (int i{ 0 }; i < MAX_CAPACITY; ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], -1.0));
			}
		}
		TEST_METHOD(InvalidRange)
		{
			auto shouldFail1 = []() { MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(-1) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = []() { MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(MAX_CAPACITY + 1) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);
		}
	};

	TEST_CLASS(ConstructorWithSizeAndValue)
	{
	public:
		TEST_METHOD(CallingConstructor)
		{
			const int size{ 4 };
			const double value{ 1.675 };
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(size, value) };
			for (int i{ 0 }; i < size; ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], value));
			}
		}
		TEST_METHOD(BoundaryCase)
		{
			const double value{ -2.95 };
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(0, value) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(MAX_CAPACITY, value) };
			for (int i{ 0 }; i < MAX_CAPACITY; ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], value));
			}
		}
		TEST_METHOD(InvalidRange)
		{
			const double value{ 7.6 };
			auto shouldFail1 = [&]() { MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(-1, value) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(MAX_CAPACITY + 1, value) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);
		}
	};

	TEST_CLASS(ConstructorWithList)
	{
	public:
		TEST_METHOD(CallingConstructor)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.0, 2.0, 0, -3.0}) };
			std::vector<double> result1{ 1.0, 2.0, 0, -3.0 };
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
			}

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({-4.5, -5.67, -94, -9.42, -7.185}) };
			std::vector<double> result2{ -4.5, -5.67, -94, -9.42, -7.185 };
			for (int i{ 0 }; i < a2.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], result2.at(i)));
			}
		}
		TEST_METHOD(BoundaryCase)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({}) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);

			std::initializer_list<double> lMax{ 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(lMax) };
			for (int i{ 0 }; i < a2.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], 1.00));
			}
		}
		TEST_METHOD(InvalidRange)
		{
			auto shouldFail1 = []() { MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.0, -2.0, 86.4}) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = []() { MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({-1.0, 2.0, 86.4}) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);

			std::initializer_list<double> lInvalid{ 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
			auto shouldFail3 = [&]() { MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(lInvalid) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail3);
		}
	};

	TEST_CLASS(CopyConstructor)
	{
	public:
		TEST_METHOD(CopyActiveElements)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({7.18, 5.0, 2.555, 8.61}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(a1) };
			MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(a2) };
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], a2[i]));
				MVC::Assert::IsTrue(isDoubleSame(a1[i], a3[i]));
			}
		}
		TEST_METHOD(CopyInactiveElements)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({7.78, -5.01, -2.565, -8.81}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(a1) };
			MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(a2) };
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], a2[i]));
				MVC::Assert::IsTrue(isDoubleSame(a1[i], a3[i]));
			}
		}
	};

	TEST_CLASS(MoveConstructor)
	{
	public:
		TEST_METHOD(MoveActiveElements)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({7.18, 0, 2.555, 8.61}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(std::move(a1)) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);

			std::vector<double> result{ 7.18, 0, 2.555, 8.61 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], result.at(i)));
			}
		}
		TEST_METHOD(MoveInactiveElements)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({7.18, -5.0, -2.555, -8.61}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(std::move(a1)) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);

			std::vector<double> result{ 7.18, -5.0, -2.555, -8.61 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], result.at(i)));
			}
		}
		TEST_METHOD(MultipleMoves)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({7.18, -5.0, -2.555, -8.61}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(std::move(a1)) };
			MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(std::move(a2)) };
			MTRN2500::NonNegativeArray a4{ MTRN2500::NonNegativeArray(std::move(a3)) };
			MTRN2500::NonNegativeArray a5{ MTRN2500::NonNegativeArray(std::move(a4)) };
			MVC::Assert::AreEqual(a1.maxSize(), 0);
			MVC::Assert::AreEqual(a2.maxSize(), 0);
			MVC::Assert::AreEqual(a3.maxSize(), 0);
			MVC::Assert::AreEqual(a4.maxSize(), 0);

			std::vector<double> result{ 7.18, -5.0, -2.555, -8.61 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a5[i], result.at(i)));
			}
		}
	};

	TEST_CLASS(OperatorIndex)
	{
	public:
		TEST_METHOD(AccessingAllElements)
		{
			const int size{ 5 };
			const double value{ 38.095 };
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(size, value) };
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				const auto elem{ a1[i] };
				MVC::Assert::IsTrue(isDoubleSame(elem, value));
			}
		}
		TEST_METHOD(AccessingOutOfRangeElements)
		{
			const int size{ 5 };
			const double value{ -5.93 };
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray(size, value) };
			MVC::Assert::IsFalse(isDoubleSame(a1[-1], value));
			MVC::Assert::IsFalse(isDoubleSame(a1[size], value));
		}
	};

	TEST_CLASS(OperatorPlusEqu)
	{
	public:
		TEST_METHOD(SimpleAdd)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47}) };
			a1 += a2;
			std::vector<double> result{ 3.0, 5.565, 7.5 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.33, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, -8.17}) };
			a1 += a2;
			std::vector<double> result{ 3.0, 5.565, 7.8, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(AddMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.0, 3.0, -8.17}) };
			((a1 += a2) += a2) += a2;
			std::vector<double> result{ 5.3, 9.0, 13.0, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.565, 3.47, -8.17}) };
			auto shouldFail = [&]() { a1 += a2; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OperatorMinusEqu)
	{
	public:
		TEST_METHOD(SimpleSubtract)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47}) };
			a1 -= a2;
			std::vector<double> result{ 1.0, 0.435, 0.56 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.33, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, -8.17}) };
			a1 -= a2;
			std::vector<double> result{ 1.0, 0.435, 0.86, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(SubtractMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({10.0, 73.155, 19.6, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.0, 3.0, -8.17}) };
			((a1 -= a2) -= a2) -= a2;
			std::vector<double> result{ 6.7, 67.155, 10.6, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.565, 3.47, -8.17}) };
			auto shouldFail = [&]() { a1 -= a2; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
		TEST_METHOD(OperationContainNegative)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 4.0, 3.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({3.1, 2.565, 3.47, -8.17}) };
			auto shouldFail = [&]() { a1 -= a2; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OperatorTimesEqu)
	{
	public:
		TEST_METHOD(SimpleMultiply)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, 0.0}) };
			a1 *= 2.0;
			std::vector<double> result{ 4.0, 6.0, 8.06, 0.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(MultiplyMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({10.0, 73.155, 19.6, -9.05, -0.57}) };
			const double value{ 1.5 };
			((a1 *= value) *= value) *= value;
			std::vector<double> result{ 33.75, 246.898125, 66.15, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(OperationContainsNegative)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 4.0, 3.05, -0.57}) };
			auto shouldFail = [&]() { a1 *= -2.0; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OperatorDivideEqu)
	{
	public:
		TEST_METHOD(SimpleDivide)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, 0.0}) };
			a1 /= 2.0;
			std::vector<double> result{ 1.0, 1.5, 2.015, 0.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DivideMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({10.0, 73.155, 19.6, -9.05, -0.57}) };
			const double value{ 1.5 };
			((a1 /= value) /= value) /= value;
			std::vector<double> result{ 2.962962963, 21.67555556, 5.807407407, -9.05, -0.57 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DividedByZero)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 4.0, 3.05, -0.57}) };
			auto shouldFail = [&]() { a1 /= 0.0; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
		TEST_METHOD(OperationContainNegative)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 4.0, 3.05, -0.57}) };
			auto shouldFail = [&]() { a1 /= -0.5; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OperatorEqu)
	{
	public:
		TEST_METHOD(SameArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.1658, 4.03, -0.1}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.1658, 4.03, -0.5}) };
			auto equal{ a1 == a2 };
			MVC::Assert::IsTrue(equal);
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.0, -4.03, -0.1}) };
			auto equal{ a1 == a2 };
			MVC::Assert::IsFalse(equal);
		}
		TEST_METHOD(DifferentMaximumSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1, -6.975}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1}) };
			auto equal{ a1 == a2 };
			MVC::Assert::IsFalse(equal);
		}
	};

	TEST_CLASS(OperatorNotEqu)
	{
	public:
		TEST_METHOD(SameArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.1658, 4.03, -0.1}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.1658, 4.03, -0.5}) };
			auto equal{ a1 != a2 };
			MVC::Assert::IsFalse(equal);
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.0, -4.03, -0.1}) };
			auto equal{ a1 != a2 };
			MVC::Assert::IsTrue(equal);
		}
		TEST_METHOD(DifferentMaximumSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1, -6.975}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03, -0.1}) };
			auto equal{ a1 != a2 };
			MVC::Assert::IsTrue(equal);
		}
	};

	TEST_CLASS(OperatorPlus)
	{
	public:
		TEST_METHOD(SimpleAdd)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({0.0, 2.0, 3.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, 9.24}) };
			auto a3{ a1 + a2 };
			std::vector<double> result{ 1.0, 4.565, 6.47, 13.27 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.33, -9.05}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, -8.17, -0.57}) };
			auto a3{ a1 + a2 };
			std::vector<double> result{ 3.0, 5.565, 7.8, -1.0, -1.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				if (i < a2.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a3[i] < 0.0);
				}
			}
		}
		TEST_METHOD(AddMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.0, 3.0, -8.17}) };
			auto a3{ a1 + a1 + a1 + a2 };
			std::vector<double> result{ 7.1, 11.0, 15.0, 1.0, -1.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a3[i] < 0.0);
				}
			}
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.565, 3.47, -8.17}) };
			auto shouldFail = [&]() { auto a3{ a1 + a2 }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OperatorMinus)
	{
	public:
		TEST_METHOD(SimpleSubtract)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.0, 3.0, 4.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, 1.24}) };
			auto a3{ a1 - a2 };
			std::vector<double> result{ 0.0, 0.435, 0.53, 2.79 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
			}
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.33, -9.05}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.0, 2.565, 3.47, -8.17, -0.57}) };
			auto a3{ a1 - a2 };
			std::vector<double> result{ 1.0, 0.435, 0.86, -1.0, -1.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				if (i < a2.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a3[i] < 0.0);
				}
			}
		}
		TEST_METHOD(SubtractMultipleTimes)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({12.0, 13.0, 24.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.0, 3.0, -8.17}) };
			auto a3{ a1 - a2 - a2 - a2 };
			std::vector<double> result{ 8.7, 7.0, 15.0, -1.0, -1.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a3[i], result.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a3[i] < 0.0);
				}
			}
		}
		TEST_METHOD(DifferentActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -9.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.1, 2.565, 3.47, -8.17}) };
			auto shouldFail = [&]() { auto a3{ a1 - a2 }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
		TEST_METHOD(OperationContainsNegative)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.0, 3.0, 6.05, -0.57}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.1, 2.565, 7.47, -8.17}) };
			auto shouldFail = [&]() { auto a3{ a1 - a2 }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(OutputOperator)
	{
	public:
		TEST_METHOD(OutputCorrectFormat)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.0, 3.0, 2.0, 4.03}) };
			std::stringstream sst{};
			sst << a1;
			std::string expected{"{1.00, 3.00, 2.00, 4.03}"};
			MVC::Assert::AreEqual(sst.str(), expected);
		}
		TEST_METHOD(RoundTo2dpWithNegative)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({1.3656, 3.35, 2.099999, -4.03}) };
			std::stringstream sst{};
			sst << a1;
			std::string expected{ "{1.37, 3.35, 2.10}" };
			MVC::Assert::AreEqual(sst.str(), expected);
		}
		TEST_METHOD(NoAvtiveRange)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({-1.3656, -3.35, -2.09}) };
			std::string expected{ "{}" };
			std::stringstream sst1{};
			sst1 << a1;
			MVC::Assert::AreEqual(sst1.str(), expected);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({}) };
			std::stringstream sst2{};;
			sst2 << a2;
			MVC::Assert::AreEqual(sst2.str(), expected);
		}
	};

	TEST_CLASS(FunctionAt)
	{
	public:
		TEST_METHOD(ValidRange)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03}) };
			std::vector<double> result{ 2.0, 3.0, 4.03 };
			for (int i{ 0 }; i < result.size(); ++i) {
				const auto val{ a1.at(i) };
				MVC::Assert::IsTrue(isDoubleSame(val, result.at(i)));
			}
		}
		TEST_METHOD(InvalidRange)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -4.03}) };
			auto shouldFail1 = [&]() { const auto val{ a1.at(2) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { const auto val{ a1.at(3) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);

			auto shouldFail3 = [&]() { const auto val{ a1.at(-1) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail3);
		}
	};

	TEST_CLASS(FunctionFront)
	{
	public:
		TEST_METHOD(ValidCall)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({3.155, -3.0, -4.03}) };
			const auto val1{ a1.front() };
			MVC::Assert::IsTrue(isDoubleSame(val1, 2.15));

			const auto val2{ a2.front() };
			MVC::Assert::IsTrue(isDoubleSame(val2, 3.155));
		}
		TEST_METHOD(NoElementsInActive)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({-2.0, -3.0, -4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({}) };
			
			auto shouldFail1 = [&]() { const auto val{ a1.front() }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { const auto val{ a2.front() }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);
		}
	};

	TEST_CLASS(FunctionBack)
	{
	public:
		TEST_METHOD(ValidCall)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({3.0, 3.255, -4.03}) };
			const auto val1{ a1.back() };
			MVC::Assert::IsTrue(isDoubleSame(val1, 4.03));

			const auto val2{ a2.back() };
			MVC::Assert::IsTrue(isDoubleSame(val2, 3.255));
		}
		TEST_METHOD(NoElementsInActive)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({-2.0, -3.0, -4.03}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({}) };

			auto shouldFail1 = [&]() { const auto val{ a1.back() }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { const auto val{ a2.back() }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);
		}
	};

	TEST_CLASS(FunctionPushFront)
	{
	public:
		TEST_METHOD(ValidCall)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.pushFront(1.5);
			std::vector<double> result1{ 1.5, 2.15, 3.0, 4.03, -1.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a1[i] < 0.0);
				}
			}

			a1.pushFront(1.5);
			std::vector<double> result2{ 1.5, 1.5, 2.15, 3.0, 4.03 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result2.at(i)));
			}
		}
		TEST_METHOD(PushToFullArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03}) };
			auto shouldFail = [&]() { a1.pushFront(1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
		TEST_METHOD(InvalidPushValue)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -4.03}) };
			auto shouldFail = [&]() { a1.pushFront(-1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(FunctionPushBack)
	{
	public:
		TEST_METHOD(ValidCall)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.pushBack(1.5);
			std::vector<double> result1{ 2.15, 3.0, 4.03, 1.5, -1.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a1[i] < 0.0);
				}
			}

			a1.pushBack(1.5);
			std::vector<double> result2{ 2.15, 3.0, 4.03, 1.5, 1.5 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result2.at(i)));
			}
		}
		TEST_METHOD(PushToFullArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, 4.03}) };
			auto shouldFail = [&]() { a1.pushBack(1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
		TEST_METHOD(InvalidPushValue)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.0, -4.03}) };
			auto shouldFail = [&]() { a1.pushBack(-1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(FunctionEmpty)
	{
	public:
		TEST_METHOD(IsEmpty)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({-4.03, -7.16, -1.0}) };
			auto isEmpty1{ a1.empty() };
			MVC::Assert::IsTrue(isEmpty1);
			
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({}) };
			auto isEmpty2{ a2.empty() };
			MVC::Assert::IsTrue(isEmpty2);
		}
		TEST_METHOD(NotEmpty)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({4.03, -7.16, -1.0}) };
			auto isEmpty1{ a1.empty() };
			MVC::Assert::IsFalse(isEmpty1);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(10, 2.5) };
			auto isEmpty2{ a2.empty() };
			MVC::Assert::IsFalse(isEmpty2);
		}
	};

	TEST_CLASS(FunctionSize)
	{
	public:
		TEST_METHOD(CorrectNumber)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({4.03, 7.16, 1.0}) };
			auto activeSize1{ a1.size() };
			MVC::Assert::AreEqual(activeSize1, 3);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray(100, 2.0) };
			auto activeSize2{ a2.size() };
			MVC::Assert::AreEqual(activeSize2, 100);
		}
		TEST_METHOD(ZeroActiveSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({-4.03, -7.16, -1.0}) };
			auto activeSize1{ a1.size() };
			MVC::Assert::AreEqual(activeSize1, 0);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({})};
			auto activeSize2{ a2.size() };
			MVC::Assert::AreEqual(activeSize2, 0);
		}
	};

	TEST_CLASS(FunctionMaxSize)
	{
	public:
		TEST_METHOD(CorrectNumber)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({4.03, 7.16, 1.0}) };
			auto capacity1{ a1.maxSize() };
			MVC::Assert::AreEqual(capacity1, 3);

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({4.03, -7.16, -1.0}) };
			auto capacity2{ a2.maxSize() };
			MVC::Assert::AreEqual(capacity2, 3);

			MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray(99) };
			auto capacity3{ a3.maxSize() };
			MVC::Assert::AreEqual(capacity3, 99);
		}
		TEST_METHOD(ZeroMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({}) };
			auto capacity{ a1.maxSize() };
			MVC::Assert::AreEqual(capacity, 0);
		}
	};

	TEST_CLASS(FunctionSet)
	{
	public:
		TEST_METHOD(ValidSet)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.set(0, 5.1);
			std::vector<double> result1{ 5.1, 3.0, 4.03, -7.16, -1.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
			}

			a1.set(2, 0.0);
			std::vector<double> result2{ 5.1, 3.0, 0.0, -7.16, -1.0 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result2.at(i)));
			}
		}
		TEST_METHOD(IndexOutsideActiveRange)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			auto shouldFail1 = [&]() { a1.set(3, 1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { a1.set(5, 1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);

			auto shouldFail3 = [&]() { a1.set(-1, 1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail3);
		}
		TEST_METHOD(InvalidSetValue)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			auto shouldFail = [&]() { a1.set(1, -1.5); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(FunctionFill)
	{
	public:
		TEST_METHOD(FillPositives)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.fill(1.5);
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], 1.5));
			}

			a1.fill(0.0);
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], 0.0));
			}
		}
		TEST_METHOD(FillNegatives)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.fill(-2.5);
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -2.5));
			}
		}
	};

	TEST_CLASS(FunctionFillN)
	{
	public:
		TEST_METHOD(FillNPositives)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.fillN(1.5, 2);
			std::vector<double> result1{ 1.5, 1.5, 4.03, -7.16, -1.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
			}

			a1.fillN(0.0, 5);
			std::vector<double> result2{ 0.0, 0.0, 0.0, 0.0, 0.0 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result2.at(i)));
			}
		}
		TEST_METHOD(IndexOutsideMaxRange)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			auto shouldFail1 = [&]() { a1.fillN(1.5, 6); };
			MVC::Assert::ExpectException<std::exception>(shouldFail1);

			auto shouldFail2 = [&]() { a1.fillN(1.5, -1); };
			MVC::Assert::ExpectException<std::exception>(shouldFail2);
		}
		TEST_METHOD(InvalidFillNValues)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			auto shouldFail = [&]() { a1.fillN(-1.5, 4); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(FunctionClear)
	{
	public:
		TEST_METHOD(InitialiseArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16, -1.0}) };
			a1.clear();
			for (int i{ 0 }; i < a1.maxSize(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], -1.0));
			}
		}
	};

	TEST_CLASS(FunctionSwap)
	{
	public:
		TEST_METHOD(SwapActiveElements)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -1.0}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, 1.47, -9.0}) };
			a1.swap(a2);
			std::vector<double> result1{ 7.5, 0.0, 1.4598, 1.47, -1.0 };
			std::vector<double> result2{ 2.15, 3.0, 4.03, 7.16, -9.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
					MVC::Assert::IsTrue(isDoubleSame(a2[i], result2.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a1[i] < 0);
					MVC::Assert::IsTrue(a2[i] < 0);
				}
			}
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -1.0, -3.56}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, 1.47, -9.0}) };
			a1.swap(a2);
			std::vector<double> result1{ 7.5, 0.0, 1.4598, 1.47, -1.0, -3.56 };
			std::vector<double> result2{ 2.15, 3.0, 4.03, 7.16, -9.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				if (i < a1.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a1[i] < 0);
				}
			}
			for (int i{ 0 }; i < result2.size(); ++i) {
				if (i < a2.size()) {
					MVC::Assert::IsTrue(isDoubleSame(a2[i], result2.at(i)));
				}
				else {
					MVC::Assert::IsTrue(a2[i] < 0);
				}
			}
		}
		TEST_METHOD(ActiveRangeNotMatch)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -1.0}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, -1.47, -9.0}) };
			auto shouldFail = [&]() { a1.swap(a2); };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

	TEST_CLASS(FunctionReverse)
	{
	public:
		TEST_METHOD(ReverseArray)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, 1.0}) };
			a1.reverse();
			std::vector<double> result1{ 1.0, 7.16, 4.03, 3.0, 2.15 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
			}

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16}) };
			a2.reverse();
			std::vector<double> result2{ 7.16, 4.03, 3.0, 2.15 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], result2.at(i)));
			}
		}
		TEST_METHOD(ReverseActiveOnly)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, 1.0, -1.0, -2.0}) };
			a1.reverse();
			std::vector<double> result1{ 1.0, 7.16, 4.03, 3.0, 2.15, -1.0, -2.0 };
			for (int i{ 0 }; i < result1.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result1.at(i)));
			}

			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -3.0, -4.5}) };
			a2.reverse();
			std::vector<double> result2{ 7.16, 4.03, 3.0, 2.15, -3.0, -4.5 };
			for (int i{ 0 }; i < result2.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a2[i], result2.at(i)));
			}
		}
	};

	TEST_CLASS(FunctionDistinct)
	{
	public:
		TEST_METHOD(RemoveDuplicates)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 2.15, 4.03, 7.16, 3.0}) };
			a1.distinct();
			std::vector<double> result{ 2.15, 3.0, 4.03, 7.16, -1.0, -1.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(DistinctActiveOnly)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 2.15, 4.03, -7.16, -7.16, -3.0}) };
			a1.distinct();
			std::vector<double> result{ 2.15, 3.0, 4.03, -1.0, -7.16, -7.16, -3.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
		TEST_METHOD(MultipleDuplicates)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({4.155, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.155, -4.0}) };
			a1.distinct();
			std::vector<double> result{ 4.155, 3.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -4.0 };
			for (int i{ 0 }; i < result.size(); ++i) {
				MVC::Assert::IsTrue(isDoubleSame(a1[i], result.at(i)));
			}
		}
	};

	TEST_CLASS(FunctionDotProduct)
	{
	public:
		TEST_METHOD(CalculateDotProduct)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -1.0}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, 1.47, -9.0}) };
			double result{ a1.dotProduct(a2) };
			MVC::Assert::IsTrue(isDoubleSame(result, 32.533194));
		}
		TEST_METHOD(DifferentMaxSize)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, -7.16}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, -1.47, -9.0}) };
			double result{ a1.dotProduct(a2) };
			MVC::Assert::IsTrue(isDoubleSame(result, 22.007994));
		}
		TEST_METHOD(ActiveRangeNotMatch)
		{
			MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.15, 3.0, 4.03, 7.16, -1.0}) };
			MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({7.5, 0.0, 1.4598, -1.47, -9.0}) };
			auto shouldFail = [&]() { double result{ a1.dotProduct(a2) }; };
			MVC::Assert::ExpectException<std::exception>(shouldFail);
		}
	};

}
