#include "pch.h"
#include "c:\users\yakov\source\repos\§ть ырср 4 - 6\lab4-5\source.h"

using namespace my_lub;

TEST(Rationality, test1) 
{
	Rational a(1, 2);
	Rational b(1, 2);
	
	EXPECT_EQ(a + b, Rational(1,1));
}

TEST(Rationality, test2)
{
	Rational a(6, 17);
	Rational b(0, 99999);

	EXPECT_EQ(a + b, Rational(6, 17));
}

TEST(Rationality, test3)
{
	bool error = false;
	try 
	{
		Rational(6, 0);
	}

	catch (std::exception&) 
	{
		error = true;
	}
	EXPECT_TRUE(error);
}

TEST(Rationality, test4)
{
	Rational a(3, 2);
	Rational b(5, 2);

	EXPECT_EQ(a * b, Rational(15, 4));
}


TEST(Rationality, test5)
{
	Rational a(3, 7);
	Rational b(2, 1);

	EXPECT_EQ(a += b, Rational(17,7));
}

TEST(Rationality, test6)
{
	Rational a(6, 17);
	Rational b(6, 17);

	EXPECT_TRUE(a == b);
}

TEST(Rationality, test7)
{
	Rational a(6, 17);
	Rational b(6, 5);

	EXPECT_EQ(a == b, 0);
}

TEST(Rationality, test8)
{ 
	Rational a(6, 17);
	Rational b(6, 5);

	EXPECT_EQ(a *= b, Rational(36, 85));
}

TEST(Rationality, test9)
{
	Rational a(6, 17);

	EXPECT_EQ(-a, Rational(-6,17));
}

TEST(Rationality, test10)
{
	Rational a(6, 17);
	Rational b(6, 5);

	EXPECT_EQ(a > b, false);
}

TEST(Rationality, test11)
{
	Rational a(5, 2);
	Rational b(1, 2);

	EXPECT_EQ(a > b, true);
}

TEST(Rationality, test12) 
{
	Rational testClass(0, 1);
	Rational testClass3;
	testClass3 = testClass++;
	EXPECT_EQ(1, testClass.getNumerator());
	EXPECT_EQ(1, testClass.getDenominator());
	EXPECT_EQ(0, testClass3.getNumerator());
	EXPECT_EQ(1, testClass3.getDenominator());
}

TEST(Rationality, test13) 
{
	Rational testClass(2, 5);
	Rational testClass3;
	testClass3 = testClass++;
	EXPECT_EQ(7, testClass.getNumerator());
	EXPECT_EQ(5, testClass.getDenominator());
	EXPECT_EQ(2, testClass3.getNumerator());
	EXPECT_EQ(5, testClass3.getDenominator());
}

TEST(Rationality, test14)
{
	Rational testClass(0, 1);
	Rational testClass3;
	testClass3 = ++testClass;
	EXPECT_EQ(1, testClass.getNumerator());
	EXPECT_EQ(1, testClass.getDenominator());
	EXPECT_EQ(1, testClass3.getNumerator());
	EXPECT_EQ(1, testClass3.getDenominator());
}

TEST(Rationality, test15) {
	Rational testClass(2, 5);
	Rational testClass3;
	testClass3 = ++testClass;
	EXPECT_EQ(7, testClass.getNumerator());
	EXPECT_EQ(5, testClass.getDenominator());
	EXPECT_EQ(7, testClass3.getNumerator());
	EXPECT_EQ(5, testClass3.getDenominator());
}