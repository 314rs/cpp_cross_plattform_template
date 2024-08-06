#include <gtest/gtest.h>
#include <string>

std::string fizzbuzz(int n) {
	std::string out = "";
	if (n % 3 == 0) {
		out += "fizz";
	} if (n % 5 == 0) {
		return out += "buzz";
	} if (out == "") {
		out = std::to_string(n);
	}
	return out;
}

// TESTS

TEST(fizzbuzz, 0) {
  EXPECT_EQ(fizzbuzz(0), "fizzbuzz");
}

TEST(fizzbuzz, 1) {
  EXPECT_EQ(fizzbuzz(1), "1");
}

TEST(fizzbuzz, 3) {
  EXPECT_EQ(fizzbuzz(3), "fizz");
}

TEST(fizzbuzz, 5) {
  EXPECT_EQ(fizzbuzz(5), "buzz");
}

TEST(fizzbuzz, 15) {
  EXPECT_EQ(fizzbuzz(15), "fizzbuzz");
}