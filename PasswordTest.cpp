/**
 * Unit Tests for Password class
 **/

#include "Password.h"
#include <gtest/gtest.h>

class PasswordTest : public ::testing::Test {
protected:
  PasswordTest() {}          // constructor runs before each test
  virtual ~PasswordTest() {} // destructor cleans up after tests
  virtual void SetUp() {}    // sets up before each test (after constructor)
  virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("Z");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, just_lower_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("abc");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, just_upper_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("ABC");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, just_ascii_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("#$%^&*");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("ABCabc");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_ascii_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("_A-B/nC0ab@c");
  ASSERT_EQ(true, actual);
}
