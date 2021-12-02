#include "pch.h"
#include "c:\users\yakov\source\repos\§ть ырср 4 - 6\lab4-5\source.h"
#include <cstdint>
#include <numeric>

using namespace my_lib;

TEST(Rationality, test1) 
{
	Rational<int> a(1), b(23);
	EXPECT_EQ(typeid(a.getNumerator()), typeid(int));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(int));
}

TEST(Rationality, test2)
{
	Rational<int> a(142), b(2);
	EXPECT_EQ(typeid(a.getNumerator()), typeid(int));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(int));
}

TEST(Rationality, test3)
{
	Rational<long> a(2147483647), b(34);
	EXPECT_EQ(typeid(a.getNumerator()), typeid(long));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(long));
}

TEST(Rationality, test4)
{
	Rational<long> a(2147648), b(23423);
	EXPECT_EQ(typeid(a.getNumerator()), typeid(long));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(long));
}

TEST(Rationality, test5)
{
	Rational<std::uint64_t> a(std::numeric_limits<std::uint64_t>().max()), b(std::numeric_limits<std::uint64_t>().min());
	EXPECT_EQ(typeid(a.getNumerator()), typeid(std::uint64_t));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(std::uint64_t));
}

TEST(Rationality, test6)
{
	Rational<std::uint64_t> a(std::numeric_limits<std::uint64_t>().infinity()), b(std::numeric_limits<std::uint64_t>().quiet_NaN());
	EXPECT_EQ(typeid(a.getNumerator()), typeid(std::uint64_t));
	EXPECT_EQ(typeid(b.getDenominator()), typeid(std::uint64_t));
}