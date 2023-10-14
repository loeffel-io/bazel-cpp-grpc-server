#include <gtest/gtest.h>
#include "calculator.h"

TEST(Math, Add) {
EXPECT_EQ(add(2,3), 5);
}